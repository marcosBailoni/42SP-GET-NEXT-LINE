/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:54:48 by maralves          #+#    #+#             */
/*   Updated: 2025/10/17 00:45:20 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>


char *get_next_line(int fd)
{
	char *buffer;
	static char *stash;
	char *line;
	ssize_t bytes_read;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !(ft_strchr(stash, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buffer);
			if (stash)
    		{
       			free(stash);
        		stash = NULL;
    		}
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_join_stash_buffer(stash, buffer);
	}
	free (buffer);
	line = return_line(stash);
	stash = readjust_stash(stash);
	if (!bytes_read && *line == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}


