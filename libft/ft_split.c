/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 03:59:56 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/29 04:57:26 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_word_count(const char *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			word_count++;
			while (*str != '\0' && *str != c)
				str++;
		}
		else
			str++;
	}
	return (word_count);
}

static char *ft_word_split(const char *s, char c)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
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

char **ft_split(const char *s, char c)
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
		while (*s != c)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
