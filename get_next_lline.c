/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:11 by alessa            #+#    #+#             */
/*   Updated: 2022/01/25 19:04:25 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER 1024

char	*get_next_line(int fd)
{
	
	char buff[BUFFER];
	static char end[BUFFER + 1];
	ssize_t bytesn= read(fd,buff, sizeof(buff));
	buff[bytesn] = '\0';

	static int k = 0;
	printf("%d\n" , k);
	int i = 0;
	while(buff[k] != '\n')
	{
		end[i] = buff[k];
		k++;
		i++;
	}
	end[i] = '\n';
	end[i + 1] = '\0';

	
	
	printf("%d\n" , k);
	k = k + 1;
	return(end);
}

int main (void)
{
 int fd = open("miau.txt" , O_RDONLY);


 printf("%s" , get_next_line(fd));
 printf("%s" , get_next_line(fd));
 printf("%s" , get_next_line(fd));
 
}