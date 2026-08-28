/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 21:09:18 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/25 15:20:50 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(const char *s, int c)
{
	const char *start;

	start = s;
	while (*s != '\0')
		s++;
	while (s > start)
	{
		if (*s == (unsigned char)*c)
			return ((char *)s);
		s--;
	}
	return ((void *)0);
}
