/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:46:54 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:29:59 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_freeandjoin(char *buffer, char *aux)
{
	char	*strjoin;

	strjoin = ft_strjoin(buffer, aux);
	free(buffer);
	buffer = NULL;
	return (strjoin);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			line = ft_calloc((ft_strlen(&buffer[i])), sizeof(char));
			i++;
			j = 0;
			while (buffer[i])
				line[j++] = buffer[i++];
			free(buffer);
			buffer = 0;
			return (line);
		}
		i++;
	}
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		line = ft_calloc(i + 2, sizeof(char));
		line[i] = '\n';
	}
	else
		line = ft_calloc(i + 1, sizeof(char));
	while (--i >= 0)
		line[i] = buffer[i];
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*aux;
	int		i;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, aux, BUFFER_SIZE);
		if (i != BUFFER_SIZE)
			aux[i] = 0;
		buffer = ft_freeandjoin(buffer, aux);
		if (ft_strchr(aux, '\n'))
			break ;
	}
	free(aux);
	aux = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
