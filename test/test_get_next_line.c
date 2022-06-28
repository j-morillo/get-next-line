/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:09:12 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/26 19:00:05 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_file(char *filename)
{
	int		fd;
	char	*line;

	printf("  %sfile%s %s\n", SUBTITLE_COLOR, RESET_COLOR, filename);
	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			line = get_next_line(fd);
		}
		close (fd);
	}
	else
	{
		printf("  %s Error al abrir fichero\n", RED_CROSS);
	}	
}

void	test_get_next_line(void)
{
	print_file("test.sh");
	print_file("text_file_1.txt");
	print_file("non_exists_file");
}
