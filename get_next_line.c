/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:54:48 by maralves          #+#    #+#             */
/*   Updated: 2025/10/09 19:01:34 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>


char *get_next_line(int fd)
{
	char *buffer;
	char *final_str;
	int	i;
	int count_chars_read;
	ssize_t read_size;
	ssize_t buffer_size = BUFFER_SIZE;

	final_str = NULL;

	buffer = malloc(sizeof(char) * buffer_size);
	if (!buffer)
		return (NULL);
	read_size = read (fd, buffer, buffer_size);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	// buffer[buffer_size] = '\0';

	i = 0;
	count_chars_read = 0;
	while (read_size > 0)
	{
		if (read_size < buffer_size)
			buffer_size = read_size;
		while (i < buffer_size)
		{
			
			if (buffer[i] == '\n' || buffer[i] == '\0')
				return (ft_buffer_concat(final_str, buffer, count_chars_read + 1));
			else
			{
				final_str = ft_buffer_concat(final_str, buffer, count_chars_read + 1);
			}
			i++;
			count_chars_read++;
		}
		read_size = read (fd, buffer, buffer_size);
		// buffer[buffer_size] = '\0';
		i = 0;
	}
	return (final_str);
}

// O L A \n
// ler x bytes
// ver se nesses x bytes tem \n
// se tiver, escrever até o \n, 
// o restante lido, ver se tem \n de novo
// se tiver, escrever até o \n novamente e guardar o que sobrou
// fazer isso até o restante não ter \n
// Caso não tenha, escrever, resetar o buffer e fazer o read novamente.

// Não esquecer dos malloc e free;