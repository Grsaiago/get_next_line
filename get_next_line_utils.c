/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:53:22 by gsaiago           #+#    #+#             */
/*   Updated: 2022/07/08 17:50:30 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nchr(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *c);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst,	const void *src, size_t len);

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

int	ft_find_zero(const char *s, long int limit)
{
	int	i;

	i = 0;
	while (i < limit - 1)
	{
		if (!*s)
			return (1);
		s++;
		i++;
	}
	return (0);
}

int	ft_nchr(const char *s)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while(s[len])
		len++;
	len++;
	while (i < len)
	{
		if (*s == '\n')
			return (2);
		s++;
		i++;
	}
	return (1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	if (!s1)
		return (s2);
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

char	*ft_substr(char *s, unsigned int start, size_t len)
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
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	ft_memmove(str, &((char *)s)[start], len);
	return (str);
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
