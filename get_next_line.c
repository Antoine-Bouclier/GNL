/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:06 by abouclie          #+#    #+#             */
/*   Updated: 2024/12/12 15:46:04 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_buffer(int fd, char *nextl, char *buffer)
{
	int		c_read;
	char	**tstr;

	c_read = read(fd, buffer, BUFFER_SIZE);
	if (c_read == -1)
		return (NULL);
	tstr = ft_split(buffer);
	buffer = tstr[0];
	if (nextl == NULL)
		nextl = tstr[1];
	return (buffer);
}
char	*get_next_line(int fd)
{
	static char	*nextl;
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 && (read(fd, buffer, BUFFER_SIZE)) == -1 && BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	while (line[strlen(line)] != '\n')
		line = ft_strjoin(line, next_buffer(fd, nextl, buffer));
	return (line);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    char    *res;

    if (!s1)
        return ((char *)s2);
    if (!s2)
        return ((char *)s1);
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return (NULL);
    res = str;
    while (*s1)
        *str++ = *s1++;
    while (*s2)
        *str++ = *s2++;
    *str = '\0';
    return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}