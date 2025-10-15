
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

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*temp_s;
	char	*new_str;
	int		i;

	i = 0;
	temp_s = (char *)s;
	while (s[i])
	{
		i++;
	}
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (temp_s[i])
	{
		new_str[i] = temp_s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		count1;
	int		count2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	new = malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	count1 = 0;
	count2 = 0;
	while (s1[count1])
	{
		new[count1] = s1[count1];
		count1++;
	}
	while (s2[count2])
	{
		new[count1] = s2[count2];
		count1++;
		count2++;
	}
	new[count1] = '\0';
	free (s1);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	chars_to_copy;
	size_t	s_len;

	if (!s)
		return (0);
	chars_to_copy = 0;
	s_len = ft_strlen((char *)s);
	if (start < s_len)
		chars_to_copy = s_len - start;
	if (chars_to_copy > len)
		chars_to_copy = len;
	new = malloc(sizeof(char) * (chars_to_copy + 1));
	if (!new)
		return (0);
	if (chars_to_copy == 0)
		new[0] = '\0';
	else
		ft_strlcpy(new, s + start, chars_to_copy + 1);
	return (new);
}

