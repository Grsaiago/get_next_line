/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:23:26 by gsaiago           #+#    #+#             */
/*   Updated: 2022/07/08 17:50:35 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

char	*get_next_line(int fd)
{
	static char	*sptr;
	char		*auxptr;
	char		*rptr;
	int			valid;
	
	valid = 1;
	if (fd < 0)
		return (NULL);
	while (valid > 0)
	{
		auxptr = ft_calloc(BUFFER_SIZE + 1, 1);
		if (ft_strchr(sptr, '\n'))
		{
			free(auxptr);
			break ;
		}
		valid = read(fd, auxptr, BUFFER_SIZE);
		sptr = ft_strjoin_gnl(sptr, auxptr);
	}
	if (valid < 0)
	{
		free(auxptr);
		free(sptr);
		return (NULL);
	}
	auxptr = ft_strdup(sptr);
	rptr = ft_substr_gnl(auxptr, 0, ft_strchr(auxptr, '\n') - auxptr);
	sptr = ft_substr_gnl(sptr, (ft_strchr(sptr, '\n') - sptr) + 1, ft_strlen(sptr));
	return (rptr);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
	{
		free(s);
		return (ft_strdup(""));
	}
	if (ft_nchr(s) == 1)
		str = ft_calloc(len + 1, 1);
	else 
	{
		str = ft_calloc(len + 2, 1);
		str[len] = '\n';
	}
	if (!str)
		return (NULL);
	ft_memmove(str, &((char *)s)[start], len);
	free(s);
	return (str);
}


int	main(void)
{
	int		fd = open("./arquivo",O_RDONLY);
	char	*ptr;

	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
}

