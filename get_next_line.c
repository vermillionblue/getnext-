/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:11 by alessa            #+#    #+#             */
/*   Updated: 2022/02/12 22:13:31 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		if (i == 0 && file == NULL)
			break ;
		if (i == 0 && file[0])
			return (file);
		if (!(ft_strchr(buff, '\n')))
			file = append(file, buff);
		else
		{
			file = append(file, buff);
			return (file);
		}
	}
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

	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd > _SC_OPEN_MAX)
		return (NULL);
	file = read_fd(fd, file);
	line = tilnewline(file);
	file = movefile(file);
	return (line);
}
