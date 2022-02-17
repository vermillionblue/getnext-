/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:02:14 by alessa            #+#    #+#             */
/*   Updated: 2022/02/17 16:54:23 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# define BUFFER_SIZE 2

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

char	*get_next_line(int fd);
void	ft_memmove(char *dst, char *src, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*read_fd(int fd, char *file, char *buff);
char	*tilnewline(char *file);
char	*copynewline(const char *s1, int i);

#endif