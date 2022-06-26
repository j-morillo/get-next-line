/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:54:24 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 14:09:12 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	printf(" buffer size = %s%d%s\n", TITLE_COLOR, BUFFER_SIZE, RESET_COLOR);
	printf(" %sstring_length%s\n", TITLE_COLOR, RESET_COLOR);
	test_string_length();
	printf(" %scopy_memory%s\n", TITLE_COLOR, RESET_COLOR);
	test_copy_memory();
	printf(" %smerge_strings%s\n", TITLE_COLOR, RESET_COLOR);
	test_merge_strings();
	printf(" %sfind_newline%s\n", TITLE_COLOR, RESET_COLOR);
	test_find_newline();
	printf(" %ssplit_string%s\n", TITLE_COLOR, RESET_COLOR);
	test_split_string();
	printf(" %sget_next_line%s\n", TITLE_COLOR, RESET_COLOR);
	test_get_next_line();
	return (0);
}
