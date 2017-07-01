NAME1	= push_swap
NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= push_swap.c operations.c assist.c commands.c scoring.c stack.c error.c perform.c a_score.c b_score.c ab_score.c free_stack.c

SRC2 	= checker.c operations.c assist.c commands.c stack.c error.c perform.c free_stack.o

.PHONY: all clean fclean re

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

OBJSFD 	= objects

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))
OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I./includes
LIBFT_HDR 	= -I./libft/includes
LIB_BINARY	= -L./libft -lft
LIBFT		= libft/libft.a

all:  $(NAME1) $(NAME2) $(LIBFT)

$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME1): $(OBJS1) $(LIBFT)
	@gcc $(CFLAGS) $(OBJS1) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to test$(NC)"

$(NAME2): $(OBJS2) $(LIBFT)
	@gcc $(CFLAGS) $(OBJS2) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to test$(NC)"

$(LIBFT):
	@make -C libft re

clean:
	@echo "$(RED)deleting object files...$(NC)"
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)
	@make -C ./libft clean

fclean: clean
	@echo "$(RED)deleting both executables...$(NC)"
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)
	@make -C ./libft fclean

re: fclean all
