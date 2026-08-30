/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:43:26 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 16:02:42 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	while (start > 0 && *s != '\0')
	{
		s++;
		start--;
	}
	i = 0;
	while (i < len && s[i] != '\0')
	{
		i++;
	}
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
