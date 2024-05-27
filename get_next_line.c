/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:10:44 by gudaniel          #+#    #+#             */
/*   Updated: 2024/05/27 11:21:06 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*fill_buffer(int fd, char *left_char, char *buffer)
{
	ssize_t	rread;
	char	*temp;

	rread = 1;
	while (rread > 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		if (rread == -1)
		{
			free(left_char);
			return (NULL);
		}
		if (rread == 0)
			break ;
		buffer[rread] = 0;
		if (!left_char)
			left_char = ft_strdup("");
		temp = left_char;
		left_char = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_char);
}

static char	*set_line(char *line_buffer)
{
	ssize_t	i;
	char	*left_char;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	while (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	left_char = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - 1);
	if (*left_char == 0)
	{
		free(left_char);
		left_char = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_char);
}

char	*get_next_line(int fd)
{
	static char	*l_char;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(l_char);
		buffer = NULL;
		l_char = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_buffer(fd, l_char, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	l_char = set_line(line);
	return (line);
}
