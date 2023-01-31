/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:13:45 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/31 19:58:00 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	find_char_pos(char *s, int c)
{
	char	a;
	int		i;
	int		j;

	if (!s)
		return (0);
	if (s[0] == '\n')
		return (1);
	a = (char )c;
	i = ft_strlen(s);
	j = 0;
	while (j < i + 1)
	{
		if (s[j] == a)
			return (++j);
		j++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		j += ft_strlen(s1);
	if (s2)
		j += ft_strlen(s2);
	str = malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	j = -1;
	if (s2)
		while (s2[++j])
			str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}