/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 12:03:08 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 19:59:02 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
