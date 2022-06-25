/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamd <jamd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:03 by jamd              #+#    #+#             */
/*   Updated: 2022/06/25 19:44:59 by jamd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_string_length(void)
{
	printf("  > %s => %zu\n", GREY_NULL, string_length(NULL));
	printf("  > '' => %zu\n", string_length(""));
	printf("  > '1' => %zu\n", string_length("1"));
	printf("  > 'NULL' => %zu\n", string_length("NULL"));
	printf("  > ' 12345 \\n' => %zu\n", string_length(" 12345 \n"));
}
