/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/01 14:25:10 by melhadou         ###   ########.fr       */
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
	char *newbackup;
	char *idx;
	char *buf;
	int len;
	int r;

	r = 0;
	idx = ft_strchr(backup, '\n');
	if (idx != 0)
	{
		len = idx - backup + 1;
		buf = ft_substr(backup, 0, len);
		newbackup = ft_substr(backup, len, -1);
		free(backup);
		backup = newbackup;
		return (buf);
	}else
	{
		if (!(buf = malloc((sizeof(char *) * BUFFER_SIZE ) + 1)))
			return (NULL);

		len = -1;
		while (++len < BUFFER_SIZE)
			buf[len] = 0;
		while (ft_strchr(buf, '\n') == 0)
		{
			r = read(fd, buf, BUFFER_SIZE);
			if (r == -1)
			{
				free(buf);
				free(backup);
				return (NULL);
			}
			buf[BUFFER_SIZE] = '\0';
			
		}
	}

	return backup;
}

int main (int argc, char *argv[])
{
	int fd = open("./test.txt", O_RDONLY);

	char *cha = get_next_line(fd);

	printf("%s",cha);
	free(cha);
	return 0;
}
