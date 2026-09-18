/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:13:26 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/18 16:34:42 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
	{
		dst_len++;
	}
	if (dst_len == size)
	{
		return (size + src_len);
	}
	dst += dst_len;
	size--;
	while (size > dst_len && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
