/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:51:59 by vboxuser          #+#    #+#             */
/*   Updated: 2025/10/17 11:27:37 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *full, char c);
char	*ft_join_stash_buffer(char *stash, char *buffer);
int		find_char_str(char *str, char c);
char	*return_line(char *stash);
char	*readjust_stash(char *stash);
char	*read_file(int fd, char *stash);
char	*get_next_line(int fd);

#endif