/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:05:31 by aennaouh          #+#    #+#             */
/*   Updated: 2022/11/16 21:06:39 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if ((char)c == *ptr)
			return (ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	lent;
	char	*str;

	i = 0;
	lent = ft_strlen(s1);
	str = malloc((lent + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < lent)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;
	size_t	lent;

	if (!s)
		return (0);
	lent = ft_strlen(s);
	if (start > lent)
		start = lent;
	if (lent - start < len)
		len = lent - start;
	i = 0;
	tab = malloc(len + 1 * sizeof(char));
	if (!tab)
		return (NULL);
	while (i < len && start < lent)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lent;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lent = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((lent + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[j++] = '\0';
	return (free(s1), free(s2), str);
}
