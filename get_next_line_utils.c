/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:53:22 by gsaiago           #+#    #+#             */
/*   Updated: 2022/07/12 14:06:17 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_staticptr(char *buffer);
char	*ft_returnptr(char *buffer);
char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	len++;
	ch = ((char) c);
	while (i < len)
	{
		if (*s == ch)
			return ((char *) s);
		s++;
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s1[len])
		len++;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = 0;
	while (len-- > 0)
		ptr[len] = s1[len];
	return (ptr);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	n;
	size_t	i;

	if (count == 0 || size == 0)
		return (NULL);
	i = -1;
	n = count * size;
	ptr = malloc(n);
	if (ptr == NULL)
		return (NULL);
	while (++i < n)
		((char *)ptr)[i] = 0;
	return (ptr);
}

void	*ft_memmove(void *dst,	const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src == dst || len == 0)
		return ((char *)dst);
	if (src > dst)
	{
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	if (src < dst)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	return ((char *)dst);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	if (!s2)
		return (s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	count = 0;
	str = ft_calloc((i + j + 1), 1);
	if (str == NULL)
		return (NULL);
	while (count < i)
	{
		str[count] = s1[count];
		count++;
	}
	while (--j >= 0)
		str[count + j] = s2[j];
	free(s1);
	free(s2);
	return (str);
}

char	*ft_returnptr(char *buffer)
{
	int		i;
	int		extra;
	char	*str;

	if (!buffer[0])
		return (NULL);
	extra = 1;
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		extra = 2;
	str = ft_calloc(sizeof(char), i + extra);
	i = 0;
	while (buffer[i] && (buffer[i] != '\n'))
	{
		str[i] = buffer [i];
		i++;
	}
	if (extra == 2)
		str[i] = '\n';
	return (str);
}

char	*ft_staticptr(char *buffer)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	if (ft_strchr(buffer, '\n'))
	{
		while (buffer[i] != '\n')
			i++;
		i++;
		str = ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
		while (buffer[i + j])
		{
			str[j] = buffer[i + j];
			j++;
		}
		free(buffer);
		return (str);
	}
	else
		free(buffer);
	return (NULL);
}
