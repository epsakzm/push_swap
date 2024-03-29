/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:58:51 by hyeopark          #+#    #+#             */
/*   Updated: 2021/06/19 17:04:26 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 300
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int					set_line(char **line, char **arr, char *buf, int fd);
int					set_line_no_read(char **line, char **arr, int fd);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
int					glue(char **arr, char *buf, int bufsize, int fd);
int					cut_set(char **arr, int index, char **line, int fd);
int					free_buf_return(int ret, char *buf);
int					line_handler(int fd, char *buf, char **arr, char **line);
void				flush_arr(char **arr, int fd, char *temp);
#endif
