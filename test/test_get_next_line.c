/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:09:12 by jamd              #+#    #+#             */
/*   Updated: 2022/06/26 14:08:57 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_get_next_line(void)
{
	int		fd;
	char	*line;

	fd = open("test.sh", O_RDONLY);
	if (fd > 0)
	{
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			line = get_next_line(fd);
		}
		close (fd);
	}
}
