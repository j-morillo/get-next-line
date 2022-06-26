/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:03 by jamd              #+#    #+#             */
/*   Updated: 2022/06/26 12:51:18 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	assert_equal(char *text, size_t expected)
{
	size_t	length;

	length = string_length(text);
	printf("  ");
	print_fstring(text);
	printf(" %s %zu ", ARROW, length);
	print_ok(length == expected);
	print_newline();
}

void	test_string_length(void)
{
	assert_equal(NULL, 0);
	assert_equal("", 0);
	assert_equal("1", 1);
	assert_equal("1234", 4);
	assert_equal(" 12345 \t", 8);
}
