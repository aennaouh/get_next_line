/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:27:31 by aennaouh          #+#    #+#             */
/*   Updated: 2022/11/18 03:08:03 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_check(char *str, int fd)
{
	int		i;
	char	*buf;

	if (!str)
		str = ft_strdup("");
	while (!ft_strchr(str, '\n'))
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (free(str), free(buf), NULL);
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (free(str), free(buf), NULL);
		if (i == 0)
		{
			if (ft_strlen(str) == 0)
			{
				return (free(str), free(buf), NULL);
			}
			return (free(buf), str);
		}
		buf[i] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*take_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ret = ft_substr(str, 0, i);
	return (ret);
}

char	*fix_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ret = ft_substr(str, i + 1, ft_strlen(str + i));
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_check(str[fd], fd);
	if (!str[fd])
		return (NULL);
	ret = take_line(str[fd]);
	str[fd] = fix_line(str[fd]);
	return (ret);
}
