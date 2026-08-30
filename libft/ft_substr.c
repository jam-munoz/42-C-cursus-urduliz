/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:43:26 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/29 03:45:03 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	end;
	char	*str;

	s += start;
	while (s[end] != '\0' && end <= len)
		end++
	str = malloc((end + 1)* sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < end)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
