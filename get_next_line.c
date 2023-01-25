/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/25 17:34:01 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *loop(int fd, char *buf, char *line)
{
	int tmp;
	int r;

	while(1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			free(line);
			return (NULL);
		}
		buf[r] = '\0';
		char *temp = line;
		line = ft_strjoin(line, buf);
		free(temp);
		tmp = find_char_pos(buf, '\n');
		if (tmp || r == 0)
			break;
	}
	free(buf);
	return line;
}

char	*read_buffer(int fd)
{
	char *buf;
	char *line;

	buf = NULL;
	line = NULL;
	if (!(buf = malloc((sizeof(char) * BUFFER_SIZE) + 1)))
		return (NULL);
	line = loop(fd, buf, line);
	return line;
}

char *get_bf_newline(char *line)
{
	int n;
	int i;
	char *bf_newline;

	n = 0;
	i = 0;
	if (!line)
		return (NULL);
	n = find_char_pos(line, '\n');
	if (!n)
		return NULL;
	bf_newline = malloc(sizeof(char) * n + 1);
	if (!bf_newline)
		return (NULL);
	while(i <= n)
	{
		bf_newline[i] = line[i];
		i++;
	}
	bf_newline[i] = '\0';
	return (bf_newline);
}

char	*get_af_newline(char *line)
{
	int n;
	int i;
	char *af_newline;

	n = 0;
	if (!line)
		return (NULL);
	n = find_char_pos(line, '\n');
	if (!n)
		return NULL;
	af_newline = malloc(sizeof(char) * (n + 1));
	if (!af_newline)
		return (NULL);
	i = 0;
	n++;
	while(line[n + i])
	{
		af_newline[i] = line[n + i];
		i++;
	}
	af_newline[i] = '\0';
	return (af_newline);
}

char	*get_next_line(int fd)
{
	static char *backup;
	char *line;
	char *buf;
	char *tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_buffer(fd);
	tmp = ft_strjoin(backup, buf);
	free(backup);
	free(buf);
	line = get_bf_newline(tmp);
	backup = get_af_newline(tmp);
	free(tmp);
	return line;
}

int main (int argc, char *argv[])
{
	int fd = open("./test.txt", O_RDONLY);
	int fd2 = open("./test1.txt", O_RDONLY);

	char *line = get_next_line(fd);
	printf("%s",line);
	free(line);

	char *line2 = get_next_line(fd2);
	printf("%s",line2);
	free(line2);


	char *line3 = get_next_line(fd2);
	printf("%s",line3);
	free(line3);

	char *line1 = get_next_line(fd);
	printf("%s",line1);
	free(line1);
	return 0;
}
