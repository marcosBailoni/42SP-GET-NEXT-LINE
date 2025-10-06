/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:54:48 by maralves          #+#    #+#             */
/*   Updated: 2025/10/05 21:31:15 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stddef.h>

char *get_next_line(int fd)
{
	static int BUFFER_SIZE;
	char *buffer;
	char *final_str;
	int	i;
	int count_chars_read;
	ssize_t read_size;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	read_size = read (fd, buffer, BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	i = 0;
	count_chars_read = 0;
	while (read_size > 0)
	{
		if (read_size < BUFFER_SIZE)
			BUFFER_SIZE = read_size;
		while (i < BUFFER_SIZE)
		{
			count_chars_read += i;
			if (buffer[i] == '\n' || buffer[i] == '\0')
			{
				final_str = malloc (sizeof(char) * (count_chars_read + 1));
				return (ft_buffer_concat(final_str, buffer, count_chars_read + 1));	
			} else 
			{
				final_str = ft_buffer_concat(final_str, buffer, count_chars_read + 1);
				i = 0;
			}
			i++;
		}
		read_size = read (fd, buffer, BUFFER_SIZE);
	}
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