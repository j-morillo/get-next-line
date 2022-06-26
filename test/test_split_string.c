/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:15:44 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 13:34:02 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	assert_equal(char *str, char *expected1, char *expected2)
{
	char	*result;
	char	*string;

	string = alloc_string(str);
	printf("  ");
	print_fstring(string);
	printf(" %s ", ARROW);
	result = split_string(&string);
	print_fstring(result);
	printf(" + ");
	print_fstring(string);
	printf(" (");
	print_fstring(expected1);
	printf(" + ");
	print_fstring(expected2);
	printf(") ");
	print_ok(are_strings_equal(result, expected1));
	print_ok(are_strings_equal(string, expected2));
	print_newline();
	free(result);
	free(string);
}

void	test_split_string(void)
{
	assert_equal(NULL, NULL, NULL);
	assert_equal("", NULL, NULL);
	assert_equal("1", "1", NULL);
	assert_equal("foobar", "foobar", NULL);
	assert_equal("\n", "\n", NULL);
	assert_equal("1\n", "1\n", NULL);
	assert_equal("1\n1", "1\n", "1");
	assert_equal("\n1", "\n", "1");
	assert_equal("foo\nbar\n", "foo\n", "bar\n");
}
