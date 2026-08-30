/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:13:26 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 02:08:50 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;
	size_t	size_left;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = 0;
	while (dest_len < size && dst[dest_len])
		dest_len++;
	size_left = size - dest_len - 1;
	if (dest_len >= size)
		return (size + src_len);
	while (i < size_left && i < src_len)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
