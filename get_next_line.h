/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:55:12 by maralves          #+#    #+#             */
/*   Updated: 2025/10/07 23:19:41 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char *get_next_line(int fd);
char *ft_buffer_concat(char *final_str, char *buffer, int buffer_size);

#endif
