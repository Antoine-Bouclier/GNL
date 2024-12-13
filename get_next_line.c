/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:06 by abouclie          #+#    #+#             */
/*   Updated: 2024/12/13 15:17:35 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char *fill_line(int fd, char *nextl, char *buffer);

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
    nextl = line;
    if (!line)
        return (NULL);
    free(buffer);
    line = ft_strccpy(line);
    nextl = ft_strchr(nextl) + 1;
    printf("\033[31mtest line : %s\033[0m", line);
    return (line);
}

static char *fill_line(int fd, char *nextl, char *buffer)
{
    ssize_t     b_read;

    while ((b_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        printf("\033[32mb_read : %d\033[0m\n", b_read); 
        buffer[b_read] = '\0';
        if (!nextl)
            nextl = ft_strdup("");
        nextl = ft_strjoin(nextl, buffer);
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
