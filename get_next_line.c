/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:23:26 by gsaiago           #+#    #+#             */
/*   Updated: 2022/07/05 17:47:16 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 30

size_t ft_stoplen(const char *str);

char	*get_next_line(int fd)
{
	static char	*sptr;
	char		aux[31];
	char		*auxptr;
	char		*rptr;

	while (1)
	{
		if (ft_strchr(sptr, '\n'))
			break ;
		read(fd, aux, BUFFER_SIZE);
		auxptr = ft_strjoin(sptr, aux);
	}
	sptr = ft_substr(auxptr, ft_strchr(auxptr, '\n') - sptr + 1, ft_strlen(auxptr));
	rptr = ft_substr(auxptr, 0, ft_strchr(auxptr, '\n') - auxptr);
	free (auxptr);
	return (rptr);

}

size_t ft_stoplen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
int	main(void)
{
	int		fd = open("./arquivo",O_RDONLY);

	printf("%s",get_next_line(fd));
}
