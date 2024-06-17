/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:10:44 by gudaniel          #+#    #+#             */
/*   Updated: 2024/06/13 13:27:11 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_set_line(char *line_buffer)
{
	char	*leftover;

	leftover = ft_strndup(line_buffer + ft_strclen(line_buffer, '\n')
			+ 1, ft_strclen(line_buffer, '\0') - ft_strclen(line_buffer, '\n'));
	free (line_buffer);
	if (!leftover)
		return (NULL);
	return (leftover);
}

static char	*_fill_line_buffer(int fd, char *left_c)
{
	ssize_t	b_read;
	char	*buffer;

	b_read = 1;
	buffer = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	while (b_read > 0 && !ft_strchr(buffer, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free_data(buffer, left_c));
		buffer[b_read] = '\0';
		left_c = ft_strjoin(left_c, buffer);
	}
	if (*left_c == '\0')
		return (free_data(buffer, left_c));
	free(buffer);
	return (left_c);
}

char	*free_data(char *buffer, char *left_c)
{
	free(buffer);
	free(left_c);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!left_c)
		left_c = NULL;
	left_c = _fill_line_buffer(fd, left_c);
	if (!left_c)
		return (NULL);
	line = ft_strndup(left_c, ft_strclen(left_c, '\n') + 1);
	if (!line)
		return (NULL);
	left_c = _set_line(left_c);
	if (!left_c)
		free(left_c);
	return (line);
}
