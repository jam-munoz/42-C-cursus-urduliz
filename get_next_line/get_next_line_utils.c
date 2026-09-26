/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:24:39 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/26 19:03:39 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s != '\0')
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return ((void *)0);
}

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*dup;
	char		*p;
	const char	*l;

	l = s;
	while (*l != '\0')
		l++;
	len = l - s;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	p = dup;
	while (*s != '\0')
	{
		*p = *s;
		p++;
		s++;
	}
	*p = '\0';
	return (dup);
}

char	*ft_substr(const char *s, unsigned int start)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	i = 0;
	while (start > 0 && *s != '\0')
	{
		s++;
		start--;
	}
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (s[len] == '\n')
		len++;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int			len;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	len = 0;
	while (*s1 != '\0')
	{
		str[len] = *s1;
		len++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[len] = *s2;
		len++;
		s2++;
	}
	str[len] = '\0';
	return (str);
}
