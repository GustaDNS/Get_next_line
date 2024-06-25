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


/**
 * @brief Pega uma string, encontra o primeiro '\ n', copia tudo que vem dps dele para um novo buffer e libera o buffer original
 * @param leftover Usada para armazenar a "sobra" da string 'line_buffer' após um caracter espcífico
 * @return Retorna o ponteiro 'leftover' que é part da string 'line_buffer' após o '\ n'
 */
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

/**
 * @brief Lê os dados do fd em blocos do tamanho "BUFFER_SIZE" e concatena esses dados a uma string (left_c) até encontra uma quebra de linha \n ou não haver mais dados para ler
 * @param left_c Representa uma string que conterá dados da leitura anterior
 * @param b_read Armazena o número de bytes lidos pela função 'read'
 * @param buffer É um ponteiro para um buffer alocado dinamicamente que será usado para armazenar os dados lidos do fd
 * @return Retorna a string 'left_c' que agora contém os dados lidos
 */
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

/**
 * @brief Lê a próxima linha de um fd, gerencia qualquer sobra de dados entre chamadas usando uma váriavel estática
 * @param left_c Armazena qualquer sobre de dados da última chamada da função. Como é estática, ela mantém seu valor entre diferentes chamadas da função 
 * @param line Armazena a linha dada pelo fd
 * @return A linha lida
 */
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
