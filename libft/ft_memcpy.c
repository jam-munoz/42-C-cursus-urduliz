/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:35:08 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/24 15:41:34 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void dest[], const void src[], size_t n)
{
	unsigned char *d;
	const unsigned char *s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
