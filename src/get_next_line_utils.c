/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:56:06 by jmorillo          #+#    #+#             */
/*   Updated: 2022/06/16 20:44:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src && n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strconcat(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc (s1_len + s2_len + 1);
	if (ptr)
	{
		ft_memcpy(ptr, s1, s1_len);
		ft_memcpy(&ptr[s1_len], s2, s2_len);
		ptr[s1_len + s2_len] = '\0';
		if (s1)
			free(s1);
	}
	return (ptr);
}

int	has_new_line(char *line)
{
	size_t	count;

	count = 0;
	while (line[count] && line[count] != 10)
		count++;
	return (line[count] != 10);
}
