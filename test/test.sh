#!/bin/bash

TITLE="\033[34;1;43m"
RESET="\033[0m"
echo -e "${TITLE}NORMINETTE${RESET}"
norminette ../get_next_line*
echo 
echo -e "${TITLE}GCC${RESET}"
gcc -Wall -Werror -Wextra test.c ../get_next_line.c ../get_next_line_utils.c
echo 
echo -e "${TITLE}TEST${RESET}"
./a.out
