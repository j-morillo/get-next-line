/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamd <jamd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:09:12 by jamd              #+#    #+#             */
/*   Updated: 2022/06/25 21:10:08 by jamd             ###   ########.fr       */
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
		printf(line);
		close (fd);
	}
}
