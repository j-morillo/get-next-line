/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamd <jamd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:56:06 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/23 17:30:14 by jamd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	copy_string(char *str1, char *str2, size_t pos, size_t length)
{
	size_t	i;

	if (!str1 || !str2 || !length)
		return ;
	i = 0;
	while (pos + i < length)
	{
		str1[i] = str2[pos + i];
		i++;
	}
}

void	merge_strings(char **str1, char **str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*new_str;

	str1_len = string_length(*str1);
	str2_len = string_length(*str2);
	if (str1_len + str2_len > 0)
		new_str = malloc (str1_len + str2_len + 1);
	else
		new_str = NULL;
	if (new_str)
	{
		copy_string(new_str, *str1, 0, str1_len);
		copy_string(&new_str[str1_len], *str2, 0, str2_len);
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
	char	*tmp_str;
	int		newline_pos;
	size_t	str_len;

	newline_pos = find_newline(*str);
	str_len = string_length(*str);
	tmp_str = NULL;
	if (newline_pos >= 0)
	{
		new_str = malloc(newline_pos + 2);
		if (!new_str)
			return (NULL);
		copy_string(new_str, *str, 0, newline_pos + 1);
		tmp_str = malloc(str_len - newline_pos);
		if (!tmp_str)
			return (NULL);
		copy_string(tmp_str, *str, newline_pos + 1, str_len - newline_pos - 1);
	}
	else
		new_str = *str;
	new_str[newline_pos + 1] = 0;
	free(*str);
	*str = tmp_str;
	return (new_str);
}
