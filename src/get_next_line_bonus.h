/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:56:13 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 19:01:50 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

char	*get_next_line(int fd);
size_t	string_length(char *str);
void	copy_memory(char *str1, char *str2, size_t length);
void	merge_strings(char **str1, char **str2);
int		find_newline(char *str);
char	*split_string(char **str);

#endif
