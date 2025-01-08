/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:57 by abouclie          #+#    #+#             */
/*   Updated: 2024/12/17 13:22:03 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#define RED "\033[31m"
#define RESET "\033[0m"

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strccpy(char *line);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif