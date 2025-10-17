
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:55:02 by maralves          #+#    #+#             */
/*   Updated: 2025/10/05 13:41:08 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strchr(char *stash, char c)
{
	int	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == c)
			return (stash + i);
		i++;
	}
	return (NULL);
}

char	*ft_join_stash_buffer(char *stash, char *buffer)
{
	char *new;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!stash)
	{
		stash = (malloc(1));
		stash[0] = '\0';
	}
	new = malloc (sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!new)
		return (NULL);
		// talvez tenha que free no stash também. e fazer a validacao do null
	while (stash[i])
	{
		new[i] = stash[i];
		i++;
	}
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	free (stash);
	return (new);
}
char	*readjust_stash(char *stash)
{
	char *new_stash;
	int index;
	int j;

	if (!stash)
        return NULL;
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
	while(stash[index])
	{
		new_stash[j] = stash[index];
		index++;
		j++;
	}
	new_stash[j] = '\0';
	free (stash);
	return (new_stash);
}
int	find_char_str(char *str, char c)
{
	int i;

	i = 0;
	if (str)
	{		
		while (str[i])
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	}
	return (i);
}

char *return_line(char *stash)
{
	int	index_to_stop;
	char *line;
	int i;

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
