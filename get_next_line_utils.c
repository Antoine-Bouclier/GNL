/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:12 by abouclie          #+#    #+#             */
/*   Updated: 2024/12/12 15:42:02 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	count_char(char const *s)
{
	int	count;

	count = 0;
	while (*s != '\n' && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

static char	*fill_line(const char *str, int start, int end)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc((end - start + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (start <= end)
	{
		line[i] = str[start];
		i++;
		start++;
	}
	return (line);
}

static void	*ft_free(char **str, int count)
{
	int	i;
 
	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s)
{
	char	**str;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	str = malloc(3 * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < 2)
	{
		if (start == 0)
			end = start + count_char(s + start);
		else
			end = start + strlen(s + start);
		str[i] = fill_line(s, start, end);
		if (s[end] == '\n')
			end++;
		start = end;
		if (!(str[i]))
			return (ft_free(str, i));
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int main (void)
// {
// 	char	*str;
// 	char	**tab;

// 	str = "salut comment tu vas ? bien et toi ?";
// 	tab = ft_split(str);
// 	printf("%s", tab[0]);
// 	printf("%s", tab[1]);
// }