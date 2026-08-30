/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 21:18:33 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 11:28:04 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	const unsigned char	*end;

	p = s;
	end = p + n;
	while (p < end)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return ((void *)0);
}
