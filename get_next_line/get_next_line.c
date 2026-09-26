/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:16:03 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/26 19:03:43 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_until_nl(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*line;
	char	*next;
	static char	*stash;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	buf[bytes_read] = '\0';
	if (stash == NULL)
		line = ft_strdup(buf);
	else
	{
		line = ft_strjoin(stash, buf);
		free(stash);
	}
	while (bytes_read > 0 && ft_strchr(next, '\n') == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buf[bytes_read] = '\0';
		next = ft_strjoin(line, buf);
		free(line);
		line = next;
	}

	//separar la linea hasta el /n
	line = ft_substr(line, 0);
	
	if (bytes_read > ft_strlen(line))
	{
		next = ft_strchr(next, '\n') + 1;
		stash = ft_strdup(next);
	}
	
	return line;
}

/*char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	// error handling
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = read_file(fd, buffer);
	if (!buf)
		return (NULL);
	line = ft_line(buffer);
	buf = ft_next(buffer);
	return (line);
}*/

int	main(void)
{
	#include <fcntl.h>
	#include <stdio.h>
	char	*file;
	int		fd;
	int		bytes_read;
	char	*line;

	file = "papa.txt";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot read file.\n");
		return (1);
	}
	for (int i = 0; i < 3; i++)
	{
		line = read_until_nl(fd);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
}
