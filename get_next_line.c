/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:11 by alessa            #+#    #+#             */
/*   Updated: 2022/02/02 23:57:09 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_strlcat( char	*dst, const char	*src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	j;

	j = 0;
	k = 0;
	i = 0;
	i = ft_strlen((char *)src);
	j = ft_strlen(dst);
	if (dstsize == 0)
		return (i);
	if (dstsize < j + 1)
		return (i + dstsize);
	while (src[k] != '\0' && (dstsize - j - 1) > 0)
	{
		dst[j + k] = src[k];
		k++;
		dstsize--;
	}
	dst[j + k] = '\0';
	return (i + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	j;

	if (!s1)
		return (0);
	j = 0;
	p = malloc(ft_strlen((char *)s2) + ft_strlen((char *)s1) + 1);
	if (p == NULL)
		return (NULL);
	while (j < ft_strlen((char *)s1))
	{
		p[j] = s1[j];
		j++;
	}
	j = 0;
	while (j < ft_strlen((char *)s2))
	{
		p[ft_strlen((char *)s1) + j] = s2[j];
		j++;
	}
	p[ft_strlen((char *)s1) + ft_strlen((char *)s2)] = '\0';
	return (p);
}


char	*ft_strchr(const char *s, int c)
{
	int			i;
	int			k;
	char		*p;

	p = (char *)s;
	k = 0;
	i = ft_strlen((char *)s) + 1;
	while (i > 0)
	{
		if (s[k] == (char)c)
			return ((p + k));
		i--;
		k++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		k;
	char	*p;

	k = 0;
	p = malloc(ft_strlen((char *)s1) + 1);
	if (!p)
		return (NULL);
	while (s1[k])
	{
		p[k] = s1[k];
		k++;
	}
	p[k] = '\0';
	return (p);
}

void copyinfo(char *buff, char* line, int i)
{
	printf("i %d", i );
	//printf("backtrack %s", buff );
	printf("\n");
}

void	*ft_memmove( void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)dst;
	p = (unsigned char *)src;
	if (!d && !p)
		return (NULL);
	if (d > p)
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			d[i] = p[i];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			d[i] = p[i];
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	int i;
	int	x;

	x = 0;
	i = 1;
	char *line;
	char *temp = NULL;
	char *temp2;
	static char buff[BUFFER_SIZE + 1];
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		line = ft_strdup(buff);
		//printf("%s____", line);
		if (ft_strchr(line, '\n'))
		{
			while (line[x])
			{
				if (line[x] == '\n')
				{
					//printf("buff1%s\n", buff);
					ft_memmove(buff + x + 1, buff, i);
					//printf("buff2%s\n", buff);
					if (temp)
					{
						
						line = ft_strjoin(temp, line);
						
						ft_memmove(buff + x + 1, buff + x + 1, i);
					
						return (line);
					}
					
					
					temp = ft_strdup(line + x + 2);
					line[x + 1] = '\0';
				
					return(line);
					

					
				}
				x++;
			}
		}
		else
		{
			if(temp != NULL)
			{
				temp2 = ft_strdup(temp);
				temp = ft_strjoin(temp2, line);
			}
			else
			{
				temp = ft_strdup(line);
			}
		}
		if (i == 0)
			break;

	}
	
	return(line);
}

int main (void)
{
 int fd = open("miau.txt" , O_RDONLY);
 
 printf("%s" , get_next_line(fd));
 printf("%s" , get_next_line(fd));
 printf("%s" , get_next_line(fd));
 printf("%s" , get_next_line(fd));


}