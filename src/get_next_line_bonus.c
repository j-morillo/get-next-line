/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:52:49 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 19:03:34 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	init_buffer(char **buffer);
void	read_until_line(int fd, char **cache, char *buffer);
char	*split_string(char **str);

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*cache[FD_MAX];

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (find_newline(cache[fd]) < 0)
	{
		init_buffer(&buffer);
		if (!buffer)
			return (NULL);
		read_until_line(fd, &cache[fd], buffer);
		free(buffer);
	}
	return (split_string(&cache[fd]));
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

char	*get_line_from_cache(char **cache, size_t len, int pos)
{
	char	*line;
	char	*new_cache;

	line = malloc(pos + 2);
	if (!line)
	{
		free(*cache);
		*cache = NULL;
		return (NULL);
	}
	copy_memory(line, *cache, pos + 1);
	line[pos + 1] = 0;
	new_cache = malloc(len - pos);
	if (!new_cache)
	{
		free(line);
		free(*cache);
		*cache = NULL;
		return (NULL);
	}
	copy_memory(new_cache, *cache + pos + 1, len - pos - 1);
	new_cache[len - pos - 1] = 0;
	free(*cache);
	*cache = new_cache;
	return (line);
}

char	*split_string(char **str)
{
	char	*line;
	int		newline_pos;
	size_t	str_len;

	newline_pos = find_newline(*str);
	str_len = string_length(*str);
	if (newline_pos >= 0 && str_len - newline_pos > 1)
		line = get_line_from_cache(str, str_len, newline_pos);
	else if (str_len == 0)
	{
		line = NULL;
		free(*str);
		*str = NULL;
	}
	else
	{
		line = *str;
		*str = NULL;
	}
	return (line);
}
