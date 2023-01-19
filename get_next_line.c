/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/19 17:06:47 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	find_char_pos(char *s, int c)
{
	char	a;
	int		i;
	int		j;

	if (s[0] == '\n')
		return 1;
	a = (char)c;
	i = ft_strlen(s);
	j = 0;
	while (j < i + 1)
	{
		if (s[j] == a)
			return (j);
		j++;
	}
	return (0);
}

char *read_buffer(int fd)
{
	char *buf;
	char *line;
	int tmp;
	int r;

	buf = NULL;
	line = NULL;
	if (!(buf = malloc((sizeof(char) * BUFFER_SIZE) + 1)))
		return (NULL);
	while(1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		printf("\n1 -- %d",r);
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
	while(i < n)
	{
		bf_newline[i] = line[i];
		i++;
	}
	bf_newline[i] = '\0';
	return (bf_newline);
}

char *get_af_newline(char *line)
{
	int n;
	int i;
	char *af_newline;

	n = 0;
	i = 0;
	if (!line)
		return (NULL);
	n = find_char_pos(line, '\n');
	if (!n)
		return NULL;
	n = ft_strlen(line) - n;
	af_newline = malloc(sizeof(char) * n);
	if (!af_newline)
		return (NULL);
	while(line[n])
	{
		af_newline[i] = line[n];
		i++;
		n++;
	}
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
	char* line;

	while(1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		if(!line)
			break;
	}
	return 0;
}
