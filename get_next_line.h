/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:55:12 by maralves          #+#    #+#             */
/*   Updated: 2025/10/16 23:56:09 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *full, char c);
char	*ft_join_stash_buffer(char *stash, char *buffer);
char	*readjust_stash(char *stash);
int	find_char_str(char *str, char c);
char *return_line(char *stash);
char *get_next_line(int fd);

#endif
