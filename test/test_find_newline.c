/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_find_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:04:10 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 13:31:53 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	assert_equal(char *text, int expected)
{
	int		pos;

	pos = find_newline(text);
	printf("  ");
	print_fstring(text);
	printf(" %s %d (%d) ", ARROW, pos, expected);
	print_ok(pos == expected);
	print_newline();
}

void	test_find_newline(void)
{
	assert_equal(NULL, -1);
	assert_equal("", -1);
	assert_equal("1", -1);
	assert_equal("foobar", -1);
	assert_equal("\n", 0);
	assert_equal("\nfoobar", 0);
	assert_equal("\nfoo\nbar\n", 0);
	assert_equal("1\n", 1);
	assert_equal("1\nfoobar\n", 1);
	assert_equal("foo\nbar", 3);
	assert_equal("foo\nbar\n", 3);
	assert_equal("foobar\n", 6);
	assert_equal("foobar\n\n", 6);
}
