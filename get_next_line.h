/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:49:43 by gsaiago           #+#    #+#             */
/*   Updated: 2022/07/08 15:07:28 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>

char	*get_next_line(int fd);
int		ft_nchr(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst,	const void *src, size_t len);
#endif
