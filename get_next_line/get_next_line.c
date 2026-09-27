/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:16:03 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/27 16:47:47 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*get_stash(int fd, char *stash)
{
	char	*buf;
	char	*p;
	int		bytes_read;

	bytes_read = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		p = stash;
		stash = ft_strjoin(stash, buf);
		free(p);
		if (ft_strchr(buf, '\n') != NULL)
			break;
	}
	free(buf);
	return (stash);
}

static char	*ft_get_line(char *stash, char **p)
{
	char	*line;
	size_t	len;

	*p = ft_strchr(stash, '\n');
	if (*p != NULL)
	{
		len = *p - stash + 1;
		line = ft_strdup(stash, len);
	}
	else
	{
		line = ft_strdup(stash, ft_strlen(stash));
	}
	return (line);
}

static char	*ft_next_line(char *stash, char **p)
{
	char	*next;

	if (*p != NULL)
	{
		*p = *p + 1;
		next = ft_strdup(*p, ft_strlen(*p));
	}
	else
	{
		next = NULL;
	}
	free(stash);
	stash = NULL;
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*p;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc(1);
		*stash = '\0';
	}
	stash = get_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_get_line(stash, &p);
	stash = ft_next_line(stash, &p);
	return (line);
}

/*int	main(void)
{
	#include <fcntl.h>
	#include <stdio.h>
	char	*file;
	int		fd;
	char	*line;

	file = "papa.txt";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot read file.\n");
		return (1);
	}
	for (int i = 0; i < 1; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
}*/
