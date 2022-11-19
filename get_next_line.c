/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:35:43 by aennaouh          #+#    #+#             */
/*   Updated: 2022/11/18 17:56:45 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		else if (i == 0)
		{
			if (ft_strlen(str) == 0)
				return (free(buf), free(str), NULL);
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
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_check(str, fd);
	if (!str)
		return (NULL);
	ret = take_line(str);
	str = fix_line(str);
	return (ret);
}

int main ()
{
	int fd = open("fff", O_RDWR); 
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	system("leaks a.out");
	usleep(1000 * 1000);
}