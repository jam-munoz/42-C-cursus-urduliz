/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:13:26 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 19:37:30 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;

	src_len	= ft_strlen(src);
	dest_len = 0;
	while (dest_len < size && dst[dest_len] != '\0')
	{
		dest_len++;
	}
	if (dest_len == size)
	{
		return (size + src_len);
	}
	dst += dest_len;
	size--;
	while (size > dest_len && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (dest_len + src_len);
}
