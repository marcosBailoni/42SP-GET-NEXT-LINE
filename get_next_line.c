/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:54:48 by maralves          #+#    #+#             */
/*   Updated: 2025/10/17 11:26:22 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*return_line(char *stash)
{
	int		index_to_stop;
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	index_to_stop = find_char_str(stash, '\n');
	line = malloc (sizeof(char) * (index_to_stop + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*readjust_stash(char *stash)
{
	char	*new_stash;
	int		index;
	int		j;

	if (!stash)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
	{
		free(stash);
		return (NULL);
	}
	index = find_char_str(stash, '\n');
	j = 0;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - index));
	if (!new_stash)
		return (NULL);
	index++;
	while (stash[index])
		new_stash[j++] = stash[index++];
	new_stash[j] = '\0';
	free (stash);
	return (new_stash);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
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
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = return_line(stash);
	stash = readjust_stash(stash);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
