/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 09:35:48 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 15:13:24 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(unsigned int n)
{
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	return (10);
}

char	*ft_itoa(int nb)
{
	unsigned int	n;
	int				digits;
	int				start;
	char			*str;

	n = nb;
	start = 0;
	if (nb < 0)
	{
		n = -n;
		start = 1;
	}
	digits = ft_digit_count(n) + start;
	str = malloc(digits + 1);
	if (str == NULL)
		return (NULL);
	if (nb < 0)
		str[0] = '-';
	str[digits--] = '\0';
	while (digits >= start)
	{
		str[digits--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
