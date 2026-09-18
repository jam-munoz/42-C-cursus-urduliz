/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:57:54 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/18 17:18:02 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
