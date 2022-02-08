/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:11 by alessa            #+#    #+#             */
/*   Updated: 2022/02/08 20:02:32 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*copynewline(const char *s1, int i)
{
	int		k;
	char	*p;

	k = -1;
	p = malloc(i + 2);
	if (!p)
		return (NULL);
	while (s1[++k] != '\n')
		p[k] = s1[k];
	p[k] = '\n';
	p[k + 1] = '\0';
	return (p);
}

char	*append(char *file, char *buff)
{
	if (file == NULL)
		file = ft_strdup(buff);
	else
		file = ft_strjoin(file, buff);
	return (file);
}

char	*read_fd(int fd, char *file)
{
	char	buff[BUFFER_SIZE + 1];
	int		i;
	int		x;

	x = 0;
	i = 1;
	while(i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';	
		if (i == 0 && file == NULL)
			break;
		if (i == 0 && file[0])
			return (file);
		if (!(ft_strchr(buff, '\n')))
			file = append(file, buff);
		else
		{
			file = append(file, buff);
			return(file);
		}
	}
	free (file);
	return (NULL);
}

char *movefile( char *file)
{
	char *new;
	int k;
	int	i;
	
	i = 0;
	k = 0;
	if (file == NULL)
		return(NULL);
	if (!(ft_strchr(file, '\n')))
	{
		free (file);
		return (NULL);
	}
	new = malloc(ft_strlen(file) - i);
	while(file[i] != '\n' && file[i])
		i++;
	while(file[i + 1 + k])
	{
		new[k] = file[i + 1 + k];
		k++;
	}
	new[k] = '\0';
	free (file);
	return (new);
}

char	*tilnewline(char *file)
{
	char	*line = NULL;
	int		i;

	if (line)
		free (line);
	i = 0;
	if (file == NULL)
		return(NULL);
	while(file[i] != '\n' && file[i])
		i++;
	if (!(ft_strchr(file, '\n')))
		line = ft_strdup(file);
	else
		line = copynewline(file, i);
	return (line);
}



char	*get_next_line(int fd)
{
	static char *file;
	char *line = NULL;

	if (BUFFER_SIZE < 1)	
		return (NULL);
	file = read_fd(fd, file);
	line = tilnewline(file);
	file = movefile(file);
	return(line);
}

int    main()
{
    int        fd;
    char    *ret;

    printf("===============================================================\n");
    fd = open("miau.txt", O_RDONLY);
    // for (int i = 0; (ret = get_next_line(fd)) && i <= 22; i++)
    while ((ret = get_next_line(fd)))
    {
        printf(">>>>>>>>>>>>>>>> %s", ret);
        free(ret);
    }
    free(ret);
    close(fd);
    return (0);
}