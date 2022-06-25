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

char	*init_buffer(void);

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*buffer;
	char		*result;
	static char	*cache = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (find_newline(cache) < 0)
	{
		buffer = init_buffer();
		if (!buffer)
			return (NULL);
		bytes_read = 1;
		while (bytes_read && find_newline(buffer) < 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0 || (!bytes_read && !string_length(cache)))
			{
				free(buffer);
				free(cache);
				return (NULL);
			}
			buffer[bytes_read] = 0;
			merge_strings(&cache, &buffer);
		}
	}
	result = split_string(&cache);
	return (result);
}

char	*init_buffer(void)
{
	char	*buffer;
	int		i;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (buffer)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
		{
			buffer[i] = 0;
			i++;
		}
	}
	return (buffer);
}
