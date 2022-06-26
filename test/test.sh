#!/bin/bash

TITLE="\033[34;43m"
RESET="\033[0m"
SRC_DIR="../src/"
DIRECTORY="../"
if [[ -d "$SRC_DIR" ]]
then
    DIRECTORY=${SRC_DIR}
fi
echo -e "${TITLE}NORMINETTE${RESET}"
norminette ${DIRECTORY}get_next_line*
echo 
echo -e "${TITLE}GCC${RESET}"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 -I ${DIRECTORY} test*.c ${DIRECTORY}get_next_line.c ${DIRECTORY}get_next_line_utils.c
echo 
echo -e "${TITLE}TEST${RESET}"
./a.out
echo 
