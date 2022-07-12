/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:39:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/07/12 14:35:53 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	int			valid;
	static char	*sptr;
	char		*rptr;
	char		*auxptr;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		if (sptr)
			free(sptr);
		return (NULL);
	}
	if (!sptr)
		sptr = ft_strdup("");
	valid = 1;
	while (valid && !ft_strchr(sptr, '\n'))
	{
		auxptr = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		valid = read(fd, auxptr, BUFFER_SIZE);
		if (valid < 0)
		{
			free(auxptr);
			return (NULL);
		}
		if (valid > 0)
			sptr = ft_strjoin_gnl(sptr, auxptr);
		else
			free(auxptr);
	}
	rptr = ft_returnptr(sptr);
	sptr = ft_staticptr(sptr);
	return (rptr);
}
