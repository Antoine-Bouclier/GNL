/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:06 by abouclie          #+#    #+#             */
/*   Updated: 2024/12/11 16:52:29 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*nextl;
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || read(fd, buffer, BUFFER_SIZE) == -1 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	line = fill_line(fd, nextl, buffer);
	return (line);
}

static char	*fill_line(int fd, char *nextl, char *buffer)
{
	char	*line;

	read(fd, buffer, BUFFER_SIZE);
	
	return (line);
}