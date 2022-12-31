/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:13:45 by melhadou          #+#    #+#             */
/*   Updated: 2022/12/30 19:23:46 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && *str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	int i;
	int j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
}

char	*ft_strchr(char *s, int c)
{
	char	a;
	int		i;
	int		j;

	a = (char)c;
	i = ft_strlen(s);
	j = 0;
	while (j < i + 1)
	{
		if (s[j] == a)
		{
			return ((char *)s + j);
		}
		j++;
	}
	return (0);
}

static char	*ft_cpy(char const *s1, char const *s2, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s1 + i))
	{
		*(str + j) = *(s1 + i);
		j++;
		i++;
	}
	i = 0;
	while (*(s2 + i))
	{
		*(str + j) = *(s2 + i);
		j++;
		i++;
	}
	*(str + j) = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	str = NULL;
	if (s1)
		s1_len = ft_strlen((char *)s1);
	if (s2)
		s2_len = ft_strlen((char *)s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (str);
	ft_cpy(s1, s2, str);
	return (str);
}
