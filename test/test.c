/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:54:24 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/25 15:35:37 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_string_length(void);
void	test_merge_strings(void);
void	test_get_next_line(void);

int	main(void)
{
	printf("%sTest string_length%s\n", TITLE_COLOR, RESET_COLOR);
	test_string_length();
	printf("%sTest merge_strings%s\n", TITLE_COLOR, RESET_COLOR);
	test_merge_strings();
	printf("%sTest get_next_line%s\n", TITLE_COLOR, RESET_COLOR);
	test_get_next_line();
}

char	*alloc_string(char *text)
{
	size_t	length;
	char	*result;

	if (!text)
		return (NULL);
	length = string_length(text);
	result = (char *)malloc(length + 1);
	copy_string(result, text, 0, length);
	result[length] = 0;
	return (result);
}

void	test_string_length(void)
{
	printf("  > NULL => %zu\n", string_length(NULL));
	printf("  > '' => %zu\n", string_length(""));
	printf("  > '1' => %zu\n", string_length("1"));
	printf("  > 'NULL' => %zu\n", string_length("NULL"));
	printf("  > ' 12345 \\n' => %zu\n", string_length(" 12345 \n"));
}

void	print_merge_results(char *str1, char *str2, char *expected)
{
	char	*string1;
	char	*string2;
	char	*output2;
	char	*ok;

	string1 = alloc_string(str1);
	string2 = alloc_string(str2);
	merge_strings(&string1, &string2);
	if (!string2)
		output2 = GREY_NULL;
	else
		output2 = string2;
	if (strcmp(string1, expected))
		ok = "X";
	else
		ok = GREEN_CHECK;
	printf("  [%s + %s] --> %s [%s]  %s\n", str1, str2, string1, output2, ok);
	free(string1);
	free(string2);
}

void	test_merge_strings(void)
{
	print_merge_results(NULL, NULL, NULL);
	print_merge_results(NULL, "", NULL);
	print_merge_results("", NULL, NULL);
	print_merge_results("1", NULL, "1");
	print_merge_results("foobar", NULL, "foobar");
	print_merge_results(NULL, "1", "1");
	print_merge_results(NULL, "foobar", "foobar");
	print_merge_results("1", "", "1");
	print_merge_results("foobar", "", "foobar");
	print_merge_results("", "1", "1");
	print_merge_results("", "foobar", "foobar");
	print_merge_results("foo", "bar", "foobar");
}

void	test_get_next_line(void)
{
	int		fd;
	char	*line;

	fd = open("test.sh", O_RDONLY);
	if (fd > 0)
	{
		line = get_next_line(fd);
		close (fd);
	}
}
