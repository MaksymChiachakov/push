/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:52:15 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/18 12:00:19 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define STASH_SIZE 1024

char	*get_next_line(int fd);
int		read_and_stash(char **stash, int fd);
void	add_to_stash(char **stash, char *buffer, int buf_size, int fd);
char	*extract_line(char **stash, int fd, int len);
void	clean_stash(char **stash, int fd, int len_nl);
int		is_nl(char **stash, int fd, int *len);

#endif