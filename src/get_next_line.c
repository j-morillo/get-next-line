/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:52:49 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/16 20:30:20 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*buffer[BUFFER_SIZE];
	static char	*line = NULL;

	while (!has_new_line(line))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		line = ft_strconcat(line, buffer);
		if (bytes_read == 0 && line == NULL)
			return (NULL);
	}
	if (has_new_line(line))
		return (ft_strsplit(line));
	else
		return (line);
}
