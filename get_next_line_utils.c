/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:13:45 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/13 15:10:46 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen(const char *str)
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen((char *)src);
	i = 0;
	if (size != 0)
	{
		while (*src != '\0' && i < size - 1)
		{
			*(dst + i) = *src;
			i++;
			src++;
		}
		*(dst + i) = '\0';
	}
	return (src_len);
}

int	ft_strchr(char *s, int c)
{
	char	a;
	int		i;
	int		j;

	a = (char)c;
	i = ft_strlen(s);
	j = -1;
	while (++j < i + 1)
		if (s[j] == a)
			return (j);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	int i;

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
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	--i;
	while (s2[++i - s1_len])
		str[i] = s2[i - s1_len];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		len;

	ret = NULL;
	len = ft_strlen(s);
	ret = malloc(len + 1);
	if (!ret)
		return (ret);
	if (ret)
	{
		while (*s)
		{
			*ret = *s;
			ret++;
			s++;
		}
		*ret = '\0';
	}
	return (ret - len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	ret = NULL;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	s_len = ft_strlen(s + start);
	if (!s)
		return (ft_strdup(""));
	else if (len <= s_len)
		s_len = len;
	ret = malloc(s_len + 1);
	if (!ret)
		return (ret);
	ft_strlcpy(ret, (s + start), s_len + 1);
	return (ret);
}
