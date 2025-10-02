/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:54:48 by maralves          #+#    #+#             */
/*   Updated: 2025/10/02 14:30:56 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "get_next_line.h"


char *get_next_line(int fd)
{
	char *buffer;
	int bytes_read;
	int count;
	int i;
	static int read_stop;

	buffer = malloc(sizeof(char) * 42);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 42);
		if (bytes_read < 1)
			break;
		count = 0;
		while (buffer[count] != '\n' || buffer[count] != '\0' && count < 42)
			count++;
		read_stop += count;
		if (buffer[count] == '\n')
		{
			i = 0;
			while (i <= count)
			{
				write (1, &buffer[i], 1);
				i++;
			}
		}
		else if (count == 42)
		{
			ft_putstr(buffer);
			ft_bzero(buffer);
			continue; 
		}
		else
		{
			free(buffer);
			return (NULL);
		}
					
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