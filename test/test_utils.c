/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:36:56 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 12:39:02 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	are_strings_equal(char *str1, char *str2)
{
	size_t	i;
	size_t	str1_len;
	size_t	str2_len;

	if (!str1 != !str2)
		return (0);
	str1_len = string_length(str1);
	str2_len = string_length(str2);
	if (str1_len != str2_len)
		return (0);
	i = 0;
	while (i < str1_len && str1[i] == str2[i])
		i++;
	return (i == str1_len);
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

void	print_fstring(char *text)
{
	size_t	i;
	size_t	length;

	if (!text)
		printf("%s", BLUE_NULL);
	else
	{
		printf("%s", LEFT_QUOTE);
		i = 0;
		length = string_length(text);
		while (i < length)
		{
			if (text[i] > 0 && text[i] < 32)
				printf("%s\\%02X%s", BLUE, text[i], RESET_COLOR);
			else
				printf("%c", text[i]);
			i++;
		}
		printf("%s", RIGHT_QUOTE);
	}
}

void	print_ok(int is_ok)
{
	char	*ok;

	if (is_ok)
		ok = GREEN_CHECK;
	else
		ok = RED_CROSS;
	printf("%s", ok);
}

void	print_newline(void)
{
	printf("%c", NEWLINE);
}
