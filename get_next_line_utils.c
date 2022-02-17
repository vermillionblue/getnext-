/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:42:21 by danisanc          #+#    #+#             */
/*   Updated: 2022/02/15 22:51:51 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	free((void *)s1);
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
