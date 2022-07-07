/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:23:26 by gsaiago           #+#    #+#             */
/*   Updated: 2022/07/06 18:56:38 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 30

char	*get_next_line(int fd)
{
	static char	*sptr;
	char		*auxptr;
	char		*rptr;

	auxptr = ft_calloc(BUFFER_SIZE + 1, 1);
	while (1)
	{
		read(fd, auxptr, BUFFER_SIZE);
		if (ft_strchr(sptr, '\n')) 
		// FAZER UM STRCHR QUE PROCURE POR UM /0 EM ATÉ BUFFER SIZE - 1 BYTES DENTRO DO AUXPTR
			break ;
		sptr = ft_strjoin(sptr, auxptr);
	}
	if ()
	{
		free(auxptr);
		free(sptr);
		return (NULL);
	}
	free(auxptr);
	auxptr = ft_strdup(sptr);
	rptr = ft_substr_gnl(auxptr, 0, ft_strchr(auxptr, '\n') - auxptr);
	sptr = ft_substr(sptr, (ft_strchr(sptr, '\n') - sptr) + 1, ft_strlen(sptr));
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
		return (ft_strdup(""));
	if ((start + len) > lens)
		len = lens - start;
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
	int 	i = 2;
	char	*ptr = "1";
	while (1)
	{
		ptr = get_next_line(fd);
		if (!ptr)
			break ;
		printf("%s", ptr);
	}
}

