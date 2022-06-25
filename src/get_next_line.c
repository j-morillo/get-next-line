/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:52:49 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/25 14:11:48 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_buffer(char **buffer);
void	read_until_line(int fd, char **cache, char *buffer);

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
	}
	return (split_string(&cache));
}

void	init_buffer(char **buffer)
{
	int		i;

	*buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (*buffer)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
		{
			*buffer[i] = 0;
			i++;
		}
	}
}

void	read_until_line(int fd, char **cache, char *buffer)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read && find_newline(buffer) < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || (!bytes_read && !string_length(*cache)))
		{
			free(buffer);
			free(*cache);
			*cache = NULL;
			return ;
		}
		buffer[bytes_read] = 0;
		merge_strings(cache, &buffer);
	}
}
