# !/bin/bash
# Passing arguments
# $1 - corresponds to the first argument, so if you want to access them as values you can just put the value.
# read takes in input and assigns the arguments to corresponding variable names
# Shuf function takes a sequence of numbers and randomly mixes them around


echo "Enter the number range you'd like: <low> - <high>"
#read low high

low=1
high=500

shuf() { awk 'BEGIN {srand(); OFMT="%.17f"} {print rand(), $0}' "$@" |sort -k1,1n | cut -d ' ' -f2-; };

ARG="$(seq $low $high | shuf | tr '\n' ' ')"
echo $ARG
 ./push_swap $ARG | wc -l
 ./push_swap $ARG | ./checker $ARG