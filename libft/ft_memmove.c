/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:50:11 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/24 15:50:14 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memmove(void dest[], const void src[], size_t n)
{
	unsigned char	   *d;
	const unsigned char *s;

	d = dest;
	s = src;

	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
