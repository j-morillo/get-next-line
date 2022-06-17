/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:56:06 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/16 20:44:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

size_t	string_length(char *str)
{
	size_t	count;

	count = 0;
	if (str)
	{
		while (str[count])
			count++;
	}
	return (count);
}

char	*extract_string(char *str, size_t pos, size_t length)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(length + 1);
	if (new_str)
	{
		i = 0;
		while (pos + i < length)
		{
			new_str[i] = str[pos + i];
			i++;
		}
	}
	return (new_str);
}

void	merge_strings(char **str1, char **str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*new_str;
	int		i;

	str1_len = string_length(*str1);
	str2_len = string_length(*str2);
	if (str1_len + str2_len > 0)
		new_str = malloc (str1_len + str2_len + 1);
	else
		new_str = NULL;
	if (new_str)
	{
		i = 0;
		while (i < str1_len)
		{
			new_str[i] = *str1[i];
			i++;
		}
		i = 0;
		while (i < str2_len)
		{
			new_str[i + str1_len] = *str2[i];
			i++;
		}
		new_str[str1_len + str2_len] = '\0';
	}
	free(*str1);
	free(*str2);
	*str1 = new_str;
	*str2 = NULL;
}

int	find_newline(char *str)
{
	size_t	pos;
	int		result;

	result = -1;
	pos = 0;
	if (str)
	{
		while (str[pos] && str[pos] != 10)
			pos++;
		if (str[pos] == 10)
			result = pos;
	}
	return (result);
}

char	*split_string(char **str)
{
	char	*new_str;
	int		newline_pos;
	int		i;

	newline_pos = find_newline(*str);
	if (newline_pos >= 0)
	{
		new_str = malloc (newline_pos + 1);
		if (new_str)
		{
			i = 0;
			while (i <= newline_pos)
			{
				new_str[i] = *str[i];
				i++;
			}
			i = 0;
			while (i < str_len)
			{
				new_str[i + str1_len] = *str2[i];
				i++;
			}

		}

	}
	else
		new_str = *str;

	new_str[str1_len + str2_len] = '\0';
	free(*str1);
	free(*str2);
	*str1 = new_str;
	*str2 = NULL;
}
