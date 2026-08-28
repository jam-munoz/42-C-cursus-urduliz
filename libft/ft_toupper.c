/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:58:51 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/24 15:28:12 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_toupper(char *str)
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
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= ('a' - 'A');
		i++;
	}
	return (str);
}
