/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:08:50 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 14:32:55 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	const char	*start;
	size_t		end;

	if (*needle == '\0')
		return ((char *)haystack);
	h = haystack;
	while (len > 0 && *h != '\0')
	{
		start = h;
		n = needle;
		end = len;
		while (end > 0 && *h == *n && *n != '\0')
		{
			h++;
			n++;
			end--;
		}
		if (*n == '\0')
			return ((char *)start);
		h = start + 1;
		len--;
	}
	return ((void *)0);
}
