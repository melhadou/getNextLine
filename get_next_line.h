/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <melhadou@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:38:03 by mohamed           #+#    #+#             */
/*   Updated: 2023/01/13 15:07:54 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int	ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
// void	ft_strcpy(char *dst, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif // !GET_NEXT_LINE_H
