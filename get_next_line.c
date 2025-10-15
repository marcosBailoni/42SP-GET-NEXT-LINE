/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:54:48 by maralves          #+#    #+#             */
/*   Updated: 2025/10/15 12:27:27 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_start_gnl(int fd)
{
	char *buffer;
	
	if ((read(fd, 0, 0) == -1 || BUFFER_SIZE < 1))
		return (NULL);
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	return (buffer);	
}

char *extract_line(char *stash, int i)
{
	char *new;
	
	new = malloc (sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	ft_strlcpy(new, stash, i + 2);
	return (new);
}
// "\n\0"  
char *remake_stash(char *stash, int i)
{
	char *new_stash;
	
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free (stash);
	return (new_stash);
}

char *get_next_line(int fd)
{
	char *buffer;
	static char *stash;	
	int bytes_read;
	int i;
	char *temp;
	
	temp = NULL;
	i = 0;
	bytes_read = 1;
	buffer = ft_start_gnl(fd);
	if (!buffer)
		return (NULL);
	if (stash)
    {
        while (stash[i] != '\n' && stash[i])
			i++;		
		if (stash[i] == '\n')
		{
			temp = extract_line (stash, i);
			stash = remake_stash(stash, i);
			if (!temp || !stash)
			{
				if (temp)
					free (temp);
				if (buffer)
					free (buffer);
				if (stash)
					free (stash);
				return (NULL);
			}
			if (buffer)
				free (buffer);
			return (temp);
		}
    }
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free (buffer);
			return (NULL);
		}
		i = 0;
		while (stash[i] != '\n' && stash[i])
			i++;		
		if (stash[i] == '\n')
		{
			temp = extract_line (stash, i);
			stash = remake_stash(stash, i);
			if (!temp || !stash)
			{
				free (temp);
				free (buffer);
				free (stash);
				return (NULL);
			}
			free (buffer);
			return (temp);
		}
	}
    if (bytes_read == -1)
    {
        free(buffer); 
        if (stash)
        {
            free(stash);
            stash = NULL;
        }
        return (NULL);
    }		
	if (stash && *stash)
	{
			temp = ft_strjoin(NULL, stash);
			free (buffer);
			free (stash);
			stash = NULL;
			return (temp);
	}
	
	free(buffer);
    return (NULL);
}
