/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:37:09 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/08 18:12:35 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2, ssize_t b_read)
{
	char	*str;
	char	*res;
	ssize_t	i;

	i = 0;
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	str = malloc(ft_strlen(s1) + b_read + 1);
	if (!str)
		return (free(str), NULL);
	res = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && i < b_read)
	{
		*str++ = *s2++;
		i++;
	}
	*str = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strccpy(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	tmp = malloc(sizeof(char) * i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		tmp[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}
