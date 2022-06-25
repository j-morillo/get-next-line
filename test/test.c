/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamd <jamd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:54:24 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/25 21:19:48 by jamd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	printf(" %sstring_length%s\n", TITLE_COLOR, RESET_COLOR);
	test_string_length();
	printf(" %scopy_memory%s\n", TITLE_COLOR, RESET_COLOR);
	test_copy_memory();
	printf(" %smerge_strings%s\n", TITLE_COLOR, RESET_COLOR);
	test_merge_strings();
	printf(" %sfint_newline%s\n", TITLE_COLOR, RESET_COLOR);
	printf("\n");
	printf(" %ssplit_strings%s\n", TITLE_COLOR, RESET_COLOR);
	printf("\n");
	printf(" %sget_next_line%s\n", TITLE_COLOR, RESET_COLOR);
	printf("\n");
	return (0);
}

char	*alloc_string(char *text)
{
	size_t	length;
	char	*result;

	if (!text)
		return (NULL);
	length = string_length(text);
	result = (char *)malloc(length + 1);
	copy_memory(result, text, length);
	result[length] = 0;
	return (result);
}
