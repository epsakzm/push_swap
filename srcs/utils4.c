/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:00:05 by hyeopark          #+#    #+#             */
/*   Updated: 2021/06/19 17:16:09 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	const char *temp;

	if (s == NULL || s == 0)
		return (0);
	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

int		cut_set(char **arr, int index, char **line, int fd)
{
	char			*temp;
	char			*node_temp;
	int				i;
	int				len;

	len = (int)ft_strlen(arr[fd]);
	if (!(temp = (char *)malloc(sizeof(char) * (index + 1))))
		return (-1);
	if (!(node_temp = (char *)malloc(sizeof(char) * (len - index))))
	{
		free(temp);
		return (-1);
	}
	i = -1;
	while (++i < index)
		temp[i] = arr[fd][i];
	temp[i++] = '\0';
	*line = temp;
	i = -1;
	while (++i < len - index - 1)
		node_temp[i] = arr[fd][i + index + 1];
	node_temp[i] = '\0';
	flush_arr(arr, fd, node_temp);
	return (1);
}

int		glue(char **arr, char *buf, int bufsize, int fd)
{
	int				len;
	char			*temp;
	unsigned int	index;
	unsigned int	r_index;
	char			*node_temp;

	len = ft_strlen(arr[fd]);
	if (!(temp = (char *)malloc(sizeof(char) * (len + bufsize + 1))))
		return (-1);
	index = 0;
	r_index = 0;
	while (len > 0 && arr[fd][index])
		temp[r_index++] = arr[fd][index++];
	index = 0;
	while (buf[index])
		temp[r_index++] = buf[index++];
	temp[r_index] = '\0';
	node_temp = arr[fd];
	arr[fd] = temp;
	free(node_temp);
	return (1);
}

void	flush_arr(char **arr, int fd, char *temp)
{
	char	*node_temp;

	node_temp = arr[fd];
	arr[fd] = temp;
	free(node_temp);
	if (ft_strlen(arr[fd]) == 0)
	{
		free(arr[fd]);
		arr[fd] = 0;
	}
}

int		free_buf_return(int ret, char *buf)
{
	free(buf);
	return (ret);
}
