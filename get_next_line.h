/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <melhadou@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:38:03 by mohamed           #+#    #+#             */
/*   Updated: 2023/01/25 17:31:50 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*read_buffer(int fd);
char	*get_bf_newline(char *line);
char	*get_af_newline(char *line);
char	*loop(int fd, char *buf, char *line);
int	find_char_pos(char *s, int c);
int	ft_strlen(const char *str);

#endif // !GET_NEXT_LINE_H
