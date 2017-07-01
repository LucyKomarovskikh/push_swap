/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:19:26 by cramirez          #+#    #+#             */
/*   Updated: 2016/09/23 04:19:26 by cramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SIZE		buffer->size
#define LASTPOS		buffer->last_pos
#define LAST_SIZE	buffer->last_size
#define BUFFER		buffer->buffer
#define INDEX		buffer->index
#define NEWLINE		ft_memchr((BUFFER + LASTPOS), '\n', SIZE - LASTPOS)
#define LINE_READ 	3

t_line	*get_buffer(int fd, t_list **head)
{
	t_line *line_info;
	t_line new_line;
	t_list *list;

	if (*head)
	{
		list = *head;
		while (list)
		{
			line_info = (t_line*)(list->content);
			if (line_info->fd == fd)
				return (line_info);
			list = list->next;
		}
	}
	new_line.fd = fd;
	new_line.last_pos = 0;
	new_line.last_size = 0;
	new_line.size = 0;
	new_line.index = 0;
	new_line.eof = 0;
	ft_lstadd(head, ft_lstnew(&new_line, sizeof(new_line)));
	line_info = (t_line*)((*head)->content);
	return (line_info);
}

int		newline_append(t_line *buffer, char **next_line, char **line)
{
	while (LASTPOS + INDEX < SIZE)
	{
		if (BUFFER[LASTPOS + INDEX] == '\n')
		{
			if (next_line[0] == 0)
				*line = ft_strsub(BUFFER, LASTPOS, INDEX);
			else
			{
				next_line[1] = ft_strsub(BUFFER, LASTPOS, INDEX);
				next_line[2] = next_line[0];
				*line = ft_strjoin(next_line[0], next_line[1]);
				free(next_line[1]);
				free(next_line[2]);
			}
			LASTPOS += INDEX + 1;
			if (SIZE == BUFF_SIZE && LASTPOS == SIZE)
			{
				LAST_SIZE = SIZE;
				SIZE = 0;
			}
			return (1);
		}
		INDEX += 1;
	}
	return (0);
}

int		conditional_read(int fd, t_line *buffer, char **next_line)
{
	INDEX = 0;
	if (LASTPOS >= SIZE && SIZE < BUFF_SIZE)
	{
		SIZE = read(fd, BUFFER, BUFF_SIZE);
		if (ERROR_OR_EOF(SIZE))
		{
			if (LAST_SIZE == BUFF_SIZE || next_line[0])
				return (1);
			else
				return (SIZE);
		}
		LASTPOS = 0;
	}
	return (3);
}

int		buffer_append(t_line *buffer, char **next_line, char **line)
{
	if (next_line[0] == 0)
		next_line[0] = ft_strsub(BUFFER, LASTPOS, INDEX);
	else
	{
		next_line[1] = ft_strsub(BUFFER, LASTPOS, INDEX);
		next_line[2] = next_line[0];
		next_line[0] = ft_strjoin(next_line[0], next_line[1]);
		free(next_line[1]);
		free(next_line[2]);
	}
	*line = next_line[0];
	if (SIZE < BUFF_SIZE && LASTPOS == SIZE)
	{
		buffer->eof = 1;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*buffer_list;
	char			*next_line[3];
	t_line			*buffer;
	int				ret;

	next_line[0] = 0;
	buffer = get_buffer(fd, &buffer_list);
	LAST_SIZE = 0;
	if (buffer->eof == 1)
		return (0);
	while (1)
	{
		if ((ret = conditional_read(fd, buffer, next_line)) == 1)
			return (1);
		else if (ret == 0 || ret == -1)
			return (ret);
		if (newline_append(buffer, next_line, line) == 1)
			return (1);
		if (buffer_append(buffer, next_line, line) == 1)
			return (1);
		LAST_SIZE = SIZE;
		SIZE = 0;
	}
}
