/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:12:05 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:54:09 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	char	*s2;

	slen = ft_strlen(s1) + 1;
	s2 = malloc(slen * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, slen);
	return (s2);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	char	*p;

	if (s == NULL)
		return (NULL);
	i = (size_t)start;
	j = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - i)
		len = slen - i;
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	while (j < len && s[i])
		p[j++] = s[i++];
	p[j] = '\0';
	return (p);
}
