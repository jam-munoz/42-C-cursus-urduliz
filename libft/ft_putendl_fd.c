/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:13:06 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/03 17:01:02 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	buf[1024];
	int		i;

	i = 0;
	while (*s != '\0')
	{
		buf[i] = *s;
		s++;
		i++;
		if (i == 1024)
		{
			write(fd, buf, i);
			i = 0;
		}
	}
	buf[i++] = '\n';
	write(fd, buf, i);
}
