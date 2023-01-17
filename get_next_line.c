/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/15 19:09:22 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *read_buffer(int fd, char *backup)
{
	char *buf;
	char *line;
	int tmp;
	int r;

	buf = NULL;
	if (!(buf = malloc((sizeof(char *) * BUFFER_SIZE ) + 1)))
		return (NULL);
	while(1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[BUFFER_SIZE] = '\0';
		tmp = ft_strchr(buf, '\n');
		if (r == 0 || tmp == 0)
			break;
		else
		{
			line = ft_strjoin(buf, line);
		}
	}
	free(buf);
	return line;
}

char	*get_next_line(int fd)
{
	static char *backup = "";
	char *line;
	char *buf;
	int tmp;
	int r;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = read_buffer(fd, backup);
	return line;
}

int main (int argc, char *argv[])
{
	int fd = open("./test.txt", O_RDONLY);

	char *cha = get_next_line(fd);
	char *cha1 = get_next_line(fd);
	// char *cha2 = get_next_line(fd);
	// char *cha3 = get_next_line(fd);

	printf("%s",cha);
	printf("%s",cha1);
	// printf(", %s",cha2);
	// printf(", %s",cha3);
	free(cha);
	free(cha1);
	// free(cha2);
	// free(cha3);
	return 0;
}
