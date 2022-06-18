/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:52:49 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/18 10:42:59 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_line(int fd, char *cache);

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*buffer;
	char		*result;
	static char	*cache = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(cache);
		return (NULL);
	}
	if (find_newline(cache) < 0)
	{
		bytes_read = 1;
		buffer[0] = 0;
		while (bytes_read && find_newline(buffer) < 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
			{
				free(buffer);
				free(cache);
				return (NULL);
			}
			buffer[bytes_read] = 0;
			merge_strings(&cache, &buffer);
			if (bytes_read == 0 && cache == NULL)
				return (NULL);
		}
	}
	result = split_string(&cache);
	return (result);
}

char	*read_until_line(int fd, char *cache)
{
}
