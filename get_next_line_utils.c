/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:13:45 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/19 17:08:06 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>
size_t	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t len;
	char* str;
	int i;
	int j;
	
	i = 0;
	j = 0;
	len = 0;
	if (!s1 && !s2)
		return NULL;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return NULL;
	if (s1)
		while (s1[i]) {
			str[i] = s1[i];
			i++;
		}
	if (s2)
		while (s2[j]) {
			str[i + j] = s2[j];
			j++;
		}
	str[i + j] = '\0';
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
