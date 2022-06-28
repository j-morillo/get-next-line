/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:54:07 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 19:00:34 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define TITLE_COLOR "\e[30;46m"
# define SUBTITLE_COLOR "\e[31;44m"
# define RESET_COLOR "\e[0m"
# define GREEN "\e[1;32m"
# define BLUE "\e[1;34m"
# define GREY_NULL "\e[1;30mNULL\e[0m"
# define BLUE_NULL "\e[1;34mNULL\e[0m"
# define ARROW "\e[1;33m-->\e[0m"
# define GREEN_CHECK "\e[1;32m ✓ \e[0m"
# define RED_CROSS "\e[1;31m ❌ \e[0m"
# define LEFT_QUOTE "\e[1;30m‟\e[0m"
# define RIGHT_QUOTE "\e[1;30m”\e[0m"
# define NEWLINE '\n'

int		are_strings_equal(char *str1, char *str2);
char	*alloc_string(char *text);
void	print_fstring(char *text);
void	print_ok(int is_ok);
void	print_newline(void);

void	test_string_length(void);
void	test_copy_memory(void);
void	test_merge_strings(void);
void	test_find_newline(void);
void	test_split_string(void);
void	test_get_next_line(void);

#endif
