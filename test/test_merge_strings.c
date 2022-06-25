/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_merge_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamd <jamd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:09:09 by jamd              #+#    #+#             */
/*   Updated: 2022/06/25 21:09:58 by jamd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	assert_equal_merge_strings(char *str1, char *str2, char *expected)
{
	char	*string1;
	char	*string2;
	char	*output1;
	char	*output2;
	char	*ok;

	string1 = alloc_string(str1);
	string2 = alloc_string(str2);
	merge_strings(&string1, &string2);
	if (!string1)
		output1 = GREY_NULL;
	else
		output1 = string1;
	if (!string2)
		output2 = GREY_NULL;
	else
		output2 = string2;
	if (strcmp(string1, expected))
		ok = RED_CROSS;
	else
		ok = GREEN_CHECK;
	printf("  [%s + %s] --> %s [%s]  %s\n", str1, str2, output1, output2, ok);
	free(string1);
	free(string2);
}

void	test_merge_strings(void)
{
	assert_equal_merge_strings(NULL, NULL, NULL);
	assert_equal_merge_strings(NULL, "", NULL);
	assert_equal_merge_strings("", NULL, NULL);
	assert_equal_merge_strings("1", NULL, "1");
	assert_equal_merge_strings("foobar", NULL, "foobar");
	assert_equal_merge_strings(NULL, "1", "1");
	assert_equal_merge_strings(NULL, "foobar", "foobar");
	assert_equal_merge_strings("1", "", "1");
	assert_equal_merge_strings("foobar", "", "foobar");
	assert_equal_merge_strings("", "1", "1");
	assert_equal_merge_strings("", "foobar", "foobar");
	assert_equal_merge_strings("foo", "bar", "foobar");
}
