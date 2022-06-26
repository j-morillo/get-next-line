/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_copy_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:45:44 by jamd              #+#    #+#             */
/*   Updated: 2022/06/26 12:50:12 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	assert_equal(char *str1, char *str2, size_t len, char *expected)
{
	char	*string1;

	string1 = alloc_string(str1);
	copy_memory(string1, str2, len);
	printf("  ");
	print_fstring(str1);
	printf(" + ");
	print_fstring(str2);
	printf("[%zu] %s ", len, ARROW);
	print_fstring(string1);
	printf(" (");
	print_fstring(expected);
	printf(") ");
	print_ok(are_strings_equal(string1, expected));
	print_newline();
	free(string1);
}

void	test_copy_memory(void)
{
	assert_equal("1234", "5678", 0, "1234");
	assert_equal("1234", "5678", 2, "5634");
	assert_equal("1234", "5678", 4, "5678");
	assert_equal("1234", "5678", 6, "5678");
	assert_equal("1234", "56", 2, "5634");
	assert_equal("1234", NULL, 0, "1234");
	assert_equal("1234", NULL, 2, "1234");
	assert_equal(NULL, "5678", 2, NULL);
}
