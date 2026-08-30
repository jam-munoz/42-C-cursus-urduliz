/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:47:35 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 02:58:37 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void			*out;
	unsigned char	*p;
	size_t			len;

	if (size != 0 && n > (size_t)-1 / size)
		return (NULL);
	len = n * size;
	out = malloc(len);
	if (out == NULL)
		return (NULL);
	p = out;
	while (len--)
	{
		*p++ = 0;
	}
	return (out);
}
