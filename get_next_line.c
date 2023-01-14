/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/13 16:42:35 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *backed_up(char *backup,char *str)
{
	backup = ft_strjoin(backup, str);
	return (backup);
}

char *read_from_file(int fd)
{
	static char *backup = "";
	char *af_n;
	char *tmp;
	char *buf;
	int len;
	int r;

	r = 1;
	if (!(buf = malloc((sizeof(char *) * BUFFER_SIZE ) + 1)))
		return (NULL);
	len = -1;
	while (++len < BUFFER_SIZE)
		buf[len] = 0;
	while (ft_strchr(buf, '\n') == 0 && r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			free(backup);
			return (NULL);
		}
		buf[BUFFER_SIZE] = '\0';
		len = ft_strchr(buf, '\n');
		if (len == 0)
		{
			backup = backed_up(backup, buf);
		}
		else
		{
			break;
		}
	}
	af_n = ft_substr(buf, len + 1, -1);
	tmp = ft_strjoin(backup, ft_substr(buf, 0, len + 1));
	backup = af_n;
	return (tmp);
}

char	*get_next_line(int fd)
{
	char *line;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = read_from_file(fd);
	return line;
}

int main (int argc, char *argv[])
{
	int fd = open("./test.txt", O_RDONLY);

	char *cha = get_next_line(fd);
	char *cha1 = get_next_line(fd);
	char *cha2 = get_next_line(fd);
	char *cha3 = get_next_line(fd);

	printf("%s",cha);
	printf("%s",cha1);
	printf("%s",cha2);
	printf("%s",cha3);
	free(cha);
	free(cha1);
	free(cha2);
	free(cha3);
	return 0;
}
