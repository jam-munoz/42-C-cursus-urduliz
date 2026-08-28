/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 11:33:04 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/24 15:28:12 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_tolower(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!str)
		return (str);
	while (str[len])
		len++;
	while (i < len)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		i++;
	}
	return (str);
}
