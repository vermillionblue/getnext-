/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:11 by alessa            #+#    #+#             */
/*   Updated: 2022/02/17 17:03:12 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*append(char *file, char *buff)
{
	if (file == NULL)
		file = ft_strdup(buff);
	else
		file = ft_strjoin(file, buff);
	if ((ft_strchr(buff, '\n')))
		free(buff);
	return (file);
}

char	*read_fd(int fd, char *file, char *buff)
{
	int	i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0 && file == NULL)
			break ;
		buff[i] = 0;
		if (i == 0 && file[0])
		{
			free(buff);
			return (file);
		}
		if (!(ft_strchr(buff, '\n')))
			file = append(file, buff);
		else
		{
			file = append(file, buff);
			return (file);
		}
	}
	free(buff);
	free (file);
	return (NULL);
}

char	*movefile(char *file)
{
	char	*new;
	int		k;
	int		i;

	i = 0;
	k = 0;
	if (file == NULL)
		return (NULL);
	if (!(ft_strchr(file, '\n')))
	{
		free (file);
		return (NULL);
	}
	new = malloc(ft_strlen(file) - i);
	while (file[i] != '\n' && file[i])
		i++;
	while (file[i + 1 + k])
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
	char	*line;
	int		i;

	line = NULL;
	if (line)
		free (line);
	i = 0;
	if (file == NULL)
		return (NULL);
	while (file[i] != '\n' && file[i])
		i++;
	if (!(ft_strchr(file, '\n')))
		line = ft_strdup(file);
	else
		line = copynewline(file, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;
	char		*buff;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	file = read_fd(fd, file, buff);
	line = tilnewline(file);
	file = movefile(file);
	return (line);
}
// int main()
// {
// 	int fd;
// 	fd = open("t.txt", O_RDWR);
// 	close(fd);
// 	printf("%s", get_next_line(1000));
// }