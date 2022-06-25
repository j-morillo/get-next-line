/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:54:07 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/25 15:31:48 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define TITLE_COLOR "\e[30;43m"
# define RESET_COLOR "\e[0m"
# define GREEN "\e[1;32m"
# define GREY_NULL "\e[1;30mNULL\e[0m"
# define GREEN_CHECK "\e[1;32m✓\e[0m"

void	copy_string(char *str1, char *str2, size_t pos, size_t length);

#endif
