/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_copy_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamd <jamd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:45:44 by jamd              #+#    #+#             */
/*   Updated: 2022/06/25 21:40:22 by jamd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	assert_equal(char *str1, char *str2, size_t len, char *expected)
{
	char	*string1;
	char	*string2;
	char	*ok;
	size_t	i;

	if (!str1)
		string1 = GREY_NULL;
	else
		string1 = alloc_string(str1);
	if (!str2)
		string2 = GREY_NULL;
	else
		string2 = alloc_string(str2);
	copy_memory(string1, string2, len);
	i = 0;
	while (i < len && string1[i] == expected[i])
		i++;
	if (i == len)
		ok = GREEN_CHECK;
	else
		ok = RED_CROSS;
	printf("  [%s + %s] --> %s [%s]  %s\n", str1, str2, string1, string2, ok);
	free(string1);
	free(string2);
}

void	test_copy_memory(void)
{
	assert_equal("1234", "NULL", 2, "NU");
}