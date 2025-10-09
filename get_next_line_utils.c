
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

#include <stdlib.h>
#include <stddef.h>

int	ft_strlen (char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*char_pointer_initializer(char *str)
{
	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';		
	}
	return (str);
}

char *ft_buffer_concat(char *final_str, char *buffer, int buffer_size)
{
	char *new_str;
	int i;
	int size;
	if (!final_str || !buffer)
		return (NULL);
	i = 0;
	final_str = char_pointer_initializer(final_str);
	size = ft_strlen(final_str) + buffer_size + 1;
	new_str = malloc(size);
	while (final_str[i])
	{
		new_str[i] = final_str[i];
		i++;
	}
	while (i < size - 1)
	{
		new_str[i] = *buffer;
		i++;
		buffer++;
	}
	new_str[i] = '\0';
	free(final_str);
	return (new_str);
}