/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 03:59:56 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 17:41:25 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *str, char c)
{
	int	word_count;

	word_count = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			word_count++;
			while (*str != c && *str != '\0')
				str++;
		}
		else
			str++;
	}
	return (word_count);
}

static char	*ft_word_split(const char *s, char c)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	i = 0;
	words = ft_word_count(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		arr[i] = ft_word_split(s, c);
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
