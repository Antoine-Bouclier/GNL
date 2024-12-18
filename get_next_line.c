/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:06 by abouclie          #+#    #+#             */
/*   Updated: 2024/12/18 18:22:58 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static void    set_nextl(char *nextl);
static ssize_t check_line(char *line);

char	*get_next_line(int fd)
{
	static char     nextl[BUFFER_SIZE + 1];
    char            *line;
    ssize_t         b_read;

    b_read = 1;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = ft_strdup(nextl);
    if (!line)
        return (NULL);
    while (b_read && check_line(line) == -1)
    {
        b_read = read(fd, nextl, BUFFER_SIZE);
        if (b_read == -1)
            return (free(line), NULL);
        line = ft_strjoin(line, nextl);
        if (ft_strchr(nextl))
            break ;
    }
    line = ft_strccpy(line);
    // printf("Avant set_nextl : %s", nextl);
    set_nextl(nextl);
    // printf("Apres set_nextl : %s", nextl);
    return (line);
}

static void    set_nextl(char *nextl)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while (nextl[i] && nextl[i] != '\n')
        i++;
    if (nextl[i] == '\n')
        i++;
    while (nextl[i + j])
    {
        nextl[j] = nextl[i + j];
        j++;
    }
    nextl[j] = '\0';
}

static ssize_t check_line(char *line)
{
    ssize_t i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '\n')
            return (1);
        i++;
    }
    return (-1);
}
