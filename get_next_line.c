/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:44 by melhadou          #+#    #+#             */
/*   Updated: 2022/12/31 19:10:45 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *backup = "";
	char *buf;
	char *tmp;
	int r;

	// allocate for buffer size
	buf = malloc((sizeof(char *) * BUFFER_SIZE) + 1);
	if (!buf)
		return (NULL);
	// read buffer size, 
	r = read(fd, buf, BUFFER_SIZE);

	buf[10] = '\0';

	if (ft_strchr(buf, '\n') == 0)
	{
		tmp = malloc(ft_strlen(backup) + 1);
		if (!tmp)
		{
			free(buf);
			return (NULL);
		}
		tmp = ft_strjoin(buf, backup);
		free(backup);
		backup = tmp;
		free(tmp);
	}
	free(buf);
	return (backup);
}

int main (int argc, char *argv[])
{
	int fd = open("./test", O_RDONLY);

	char *cha = get_next_line(fd);

	printf("%s",cha);
	free(cha);
	return 0;
}
