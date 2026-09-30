/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:14:39 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/27 22:00:19 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd_1;
	int		i;
	char	*line[1024];

	i = 1;
	fd_1 = open("empty.txt", O_RDONLY);
	while (1)
	{
		line[fd_1] = get_next_line(fd_1);
		printf("Line %d for fd %d: %s\n", i, fd_1, line[fd_1]);
		if (!line[fd_1])
			return (0);
		free(line[fd_1]);
		i++;
	}
}
