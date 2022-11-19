/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:26:14 by aennaouh          #+#    #+#             */
/*   Updated: 2022/11/15 21:19:04 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*read_check(char *str, int fd);
char	*take_line(char *str);
char	*fix_line(char *str);

#endif