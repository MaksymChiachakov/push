/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:50:48 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/18 12:00:17 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash[STASH_SIZE] = {0};
	char		*line;
	int			len;
	int			read_size;

	read_size = BUFFER_SIZE;
	while (!is_nl(stash, fd, &len) && read_size > 0)
		read_size = read_and_stash(stash, fd);
	if (read_size < 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = extract_line(stash, fd, len);
	clean_stash(stash, fd, len);
	if (line && line[0] == '\0')
	{
		free(line);
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	return (line);
}

int	read_and_stash(char **stash, int fd)
{
	char	*buffer;
	int		read_size;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (-1);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size <= 0)
	{
		free(buffer);
		return (read_size);
	}
	add_to_stash(stash, buffer, read_size, fd);
	free(buffer);
	return (read_size);
}

void	add_to_stash(char **stash, char *buffer, int buf_size, int fd)
{
	int		len_stash;
	char	*new_stash;

	len_stash = 0;
	if (stash[fd])
		while (stash[fd][len_stash])
			len_stash++;
	new_stash = (char *)malloc(len_stash + buf_size + 1);
	if (!new_stash)
		return ;
	new_stash[len_stash + (buf_size--)] = '\0';
	while (buf_size >= 0)
	{
		new_stash[len_stash + buf_size] = buffer[buf_size];
		buf_size--;
	}
	len_stash--;
	while (len_stash >= 0)
	{
		if (stash[fd])
			new_stash[len_stash] = stash[fd][len_stash];
		len_stash--;
	}
	free(stash[fd]);
	stash[fd] = new_stash;
}

char	*extract_line(char **stash, int fd, int len)
{
	char	*line;

	if (stash[fd] && stash[fd][len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	line[len--] = '\0';
	if (!stash[fd])
		return (line);
	while (len >= 0)
	{
		line[len] = stash[fd][len];
		len--;
	}
	return (line);
}

void	clean_stash(char **stash, int fd, int len_nl)
{
	int		len_stash;
	char	*new_stash;

	if (!stash[fd])
		return ;
	if (stash[fd][len_nl] == '\n')
		len_nl++;
	len_stash = len_nl;
	while (stash[fd][len_stash])
		len_stash++;
	new_stash = (char *)malloc(len_stash - len_nl + 1);
	if (!new_stash)
		return ;
	new_stash[len_stash - len_nl] = '\0';
	len_stash--;
	while (len_stash - len_nl >= 0)
	{
		new_stash[len_stash - len_nl] = stash[fd][len_stash];
		len_stash--;
	}
	free(stash[fd]);
	stash[fd] = new_stash;
}

// #include "get_next_line_utils.c"
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("line :%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
