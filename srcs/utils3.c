/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:59:43 by hyeopark          #+#    #+#             */
/*   Updated: 2021/06/19 17:15:55 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		set_line_no_read(char **line, char **arr, int fd)
{
	unsigned int	index;

	index = 0;
	while (arr[fd][index])
	{
		if (arr[fd][index] == '\n')
		{
			if (cut_set(arr, index, line, fd))
				return (1);
			else
				return (-1);
		}
		index++;
	}
	if (cut_set(arr, index, line, fd))
		return (0);
	return (-1);
}

int		set_line(char **line, char **arr, char *buf, int fd)
{
	unsigned int	index;
	int				bufsize;

	index = 0;
	bufsize = (int)ft_strlen(buf);
	if (!glue(arr, buf, bufsize, fd))
		return (-1);
	while (arr[fd][index])
	{
		if (arr[fd][index] == '\n')
		{
			if (cut_set(arr, index, line, fd))
				return (1);
			else
				return (-1);
		}
		index++;
	}
	return (2);
}

int		line_handler(int fd, char *buf, char **arr, char **line)
{
	int		ret;

	while (1)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (free_buf_return(-1, buf));
		if (ret == 0)
		{
			if (ft_strlen(arr[fd]) == 0)
			{
				if (!(*line = (char *)malloc(sizeof(char))))
					return (free_buf_return(-1, buf));
				*line[0] = '\0';
				return (free_buf_return(0, buf));
			}
			return (free_buf_return(set_line_no_read(line, arr, fd), buf));
		}
		else if (ret > 0)
		{
			buf[ret] = '\0';
			if ((ret = set_line(line, arr, buf, fd)) == 2)
				continue ;
			return (free_buf_return(ret, buf));
		}
	}
}

int		get_next_line(int fd, char **line)
{
	static char		*arr[OPEN_MAX];
	char			*buf;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	return (line_handler(fd, buf, arr, line));
}
