/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:08:50 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/25 14:46:28 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *h;
	const char *n;
	const char *start;
	const char *end;

	h = haystack;
	end = h + len;
	if (*needle == '\0')
		return ((char *)h);
	while(h < end && *h != '\0')
	{
		start = h;
		n = needle;
		while (h < end && *h == *n && *n != '\0')
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *)start);
		h = start + 1;
	}
	return ((void *)0);
}
