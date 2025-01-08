/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:06 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/07 09:25:41 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char *fill_line(int fd, char *nextl, char *buffer);
static char    *set_nextl(char *nextl);

char	*get_next_line(int fd)
{
	static char     *nextl;
    char            *line;
    char            *buffer;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(nextl);
        free(buffer);
        return (NULL);
    }
    line = fill_line(fd, nextl, buffer);
    if (!line)
    {
        free(nextl);
        return (NULL);
    }
    free(buffer);
    nextl = line;
    line = ft_strccpy(line);
    nextl = set_nextl(nextl);
    return (line);
}

static char *fill_line(int fd, char *nextl, char *buffer)
{
    ssize_t     b_read;
    char        *tmp;

    while ((b_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[b_read] = '\0';
        if (!nextl)
            nextl = ft_strdup("");
        tmp = nextl;
        nextl = ft_strjoin(tmp, buffer);
        free(tmp);
        if (ft_strchr(buffer))
            break;
    }
    if (b_read == -1)
    {
        free(nextl);
        return (NULL);
    }
    return (nextl);
}
static char    *set_nextl(char *nextl)
{
    char    *tmp;

    if (ft_strchr(nextl))
    {
        tmp = ft_strdup(ft_strchr(nextl));
        free(nextl);
        nextl = tmp;
    }
    else
    {
        free(nextl);
        nextl = NULL;
    }
    return (nextl);
}