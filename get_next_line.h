/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:57 by abouclie          #+#    #+#             */
/*   Updated: 2024/12/12 15:18:40 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s);
size_t	ft_strlen(const char *s);

#endif