/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:39:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/07/12 14:36:06 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	int			valid;
	static char	*sptr[65536];
	char		*rptr;
	char		*auxptr;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(sptr[fd]);
		return (NULL);
	}
	if (!sptr[fd])
		sptr[fd] = ft_strdup("");
	valid = 1;
	while (valid && !ft_strchr(sptr[fd], '\n'))
	{
		auxptr = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		valid = read(fd, auxptr, BUFFER_SIZE);
		if (valid < 0)
		{
			free(sptr[fd]);
			free(auxptr);
			return (NULL);
		}
		if (valid > 0)
			sptr[fd] = ft_strjoin_gnl(sptr[fd], auxptr);
		else
			free(auxptr);
	}
	rptr = ft_returnptr(sptr[fd]);
	sptr[fd] = ft_staticptr(sptr[fd]);
	return (rptr);
}
