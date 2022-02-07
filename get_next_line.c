/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:11 by alessa            #+#    #+#             */
/*   Updated: 2022/02/07 13:12:51 by danisanc         ###   ########.fr       */
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

void	ft_memmove(char *dst, char *src, size_t len)
{
	while (len--)
		*dst++ = *src++;
}

char	*read_fd(int fd, char *file)
{
	char buff[BUFFER_SIZE + 1];
	int i;
	int	x;

	x = 0;
	i = 1;
	while(i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		if (i == 0 && file[0])
		{
			file = ft_strjoin(file, "\0");
			return (file);
		}
			
		if (!(ft_strchr(buff, '\n')))
		{
			if (file == NULL)
				file = ft_strdup(buff);
			else
				file = ft_strjoin(file, buff);
		}
		else
		{
			while(buff[x])
			{
				if (buff[x] == '\n')
				{
					if (file != NULL)
						file = ft_strjoin(file, buff);
					else
						file = ft_strdup(buff);
					return (file);	
				}
				x++;
			}
		}
	}
	return (NULL);
}



char	*tilnewline(char *file)
{
	char	*line;
	int		i;

	i = 0;
	while(file[i] != '\n' && file[i])
		i++;
	line = ft_strdup(file);
	line[i + 1] = '\0';
	ft_memmove(file, file + i + 1, ft_strlen(file) - i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char *file;
	char *line;
	if (fd < 0)	
		return (NULL);
	
	file = read_fd(fd, file);


	if (!(ft_strchr(file, '\n')))
	{
		line = ft_strdup(file);
		line[ft_strlen(file)] = '\0';
		free(file);
	}
	else
		line = tilnewline(file);
	return(line);
}

// int    main()
// {
//     int        fd;
//     char    *ret;

//     printf("===============================================================\n");
//     fd = open("miau.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }