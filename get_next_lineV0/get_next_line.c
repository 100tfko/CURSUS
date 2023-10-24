/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:25:13 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/24 10:08:01 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_get_str(int fd, char *str)
{
	int		redret;
	char	*aux;

	if (!str)
		str = ft_challoc(1);
	aux = ft_challoc(BUFFER_SIZE + 1);
	redret = 42;
	while (!ft_srchnl(aux) && redret > 0)
	{
		redret = read(fd, aux, BUFFER_SIZE);
		if (redret < 0)
			return (free(aux), free(str), NULL);
		aux[redret] = 0;
		str = ft_strjoin(str, aux);
		if (!str)
			return (free(aux), free(str), NULL);
	}
	free(aux);
	return (str);
}

static char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i += 1;
	line = ft_challoc(i + 1 + (str[i] == '\n'));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i += 1;
	}
	if (str[i])
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

static char	*ft_liberator(char *str)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i += 1;
	if (str[i] == 0)
		return (free(str), NULL);
	aux = ft_challoc(ft_strlen(str) - i);
	i += 1;
	j = 0;
	while (str[i + j])
	{
		aux[j] = str[i + j];
		j += 1;
	}
	aux[j] = 0;
	free(str);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	str = ft_get_str(fd, str);
	if (str == NULL)
		return (NULL);
	line = ft_get_line(str);
	str = ft_liberator(str);
	return (line);
}
