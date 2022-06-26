/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:52:49 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 15:21:40 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_buffer(char **buffer);
void	read_until_line(int fd, char **cache, char *buffer);
char	*split_string(char **str);

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*cache = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (find_newline(cache) < 0)
	{
		init_buffer(&buffer);
		if (!buffer)
			return (NULL);
		read_until_line(fd, &cache, buffer);
		free(buffer);
	}
	return (split_string(&cache));
}

void	init_buffer(char **buffer)
{
	int		i;
	char	*letter_ptr;

	*buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (*buffer)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
		{
			letter_ptr = *buffer + i;
			*letter_ptr = 0;
			i++;
		}
	}
}

void	read_until_line(int fd, char **cache, char *buffer)
{
	int	bytes_read;
	int	newline_pos;

	bytes_read = 1;
	newline_pos = -1;
	while (bytes_read && newline_pos < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		newline_pos = find_newline(buffer);
		if (bytes_read < 0 || (!bytes_read && !string_length(*cache)))
		{
			free(*cache);
			*cache = NULL;
			return ;
		}
		buffer[bytes_read] = 0;
		merge_strings(cache, &buffer);
	}
}

char	*split_string(char **str)
{
	char	*line;
	char	*new_str;
	int		newline_pos;
	size_t	str_len;

	newline_pos = find_newline(*str);
	str_len = string_length(*str);
	new_str = NULL;
	if (newline_pos >= 0 && newline_pos < (int)str_len - 1)
	{
		line = malloc(newline_pos + 2);
		if (!line)
		{
			free(*str);
			*str = NULL;
			return (NULL);
		}
		copy_memory(line, *str, newline_pos + 1);
		line[newline_pos + 1] = 0;
		new_str = malloc(str_len - newline_pos);
		if (!new_str)
		{
			free(line);
			free(*str);
			*str = NULL;
			return (NULL);
		}
		copy_memory(new_str, *str + newline_pos + 1, str_len - newline_pos - 1);
		new_str[newline_pos + 1] = 0;
		free(*str);
	}
	else if (str_len == 0)
	{
		line = NULL;
		free(*str);
	}
	else
		line = *str;
	*str = new_str;
	return (line);
}
