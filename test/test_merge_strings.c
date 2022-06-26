/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_merge_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:09:09 by jamd              #+#    #+#             */
/*   Updated: 2022/06/26 15:12:59 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	assert_equal(char *str1, char *str2, char *expected1, char *expected2)
{
	char	*string1;
	char	*string2;

	printf("  ");
	print_fstring(str1);
	printf(" + ");
	print_fstring(str2);
	printf(" %s ", ARROW);
	string1 = alloc_string(str1);
	string2 = alloc_string(str2);
	merge_strings(&string1, &string2);
	print_fstring(string1);
	printf(" + ");
	print_fstring(string2);
	printf(" (");
	print_fstring(expected1);
	printf(") ");
	print_ok(are_strings_equal(string1, expected1));
	print_ok(are_strings_equal(string2, expected2));
	print_newline();
	free(string1);
	free(string2);
}

void	test_merge_strings(void)
{
	assert_equal(NULL, NULL, NULL, NULL);
	assert_equal(NULL, "", NULL, "");
	assert_equal("", NULL, NULL, NULL);
	assert_equal("1", NULL, "1", NULL);
	assert_equal("foobar", NULL, "foobar", NULL);
	assert_equal(NULL, "1", "1", "");
	assert_equal(NULL, "foobar", "foobar", "");
	assert_equal("1", "", "1", "");
	assert_equal("foobar", "", "foobar", "");
	assert_equal("", "1", "1", "");
	assert_equal("", "foobar", "foobar", "");
	assert_equal("foo", "bar", "foobar", "");
}
