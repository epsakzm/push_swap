/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:59:10 by hyeopark          #+#    #+#             */
/*   Updated: 2021/06/19 17:03:17 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		arr_separation(int ac, char **av, t_data *new)
{
	int		p;
	int		i;
	int		*buff;
	char	**mass;
	int		count_element;

	i = 1;
	while (i < ac)
	{
		p = -1;
		count_element = ft_wordcount(av[i], ' ');
		mass = ft_strsplit(av[i], ' ');
		if (!(buff = (int *)malloc(sizeof(int) * (count_element))))
			exit(1);
		while (count_element > ++p)
		{
			buff[p] = ft_atoi(mass[p]);
			free(mass[p]);
		}
		free(mass);
		stack_up(new, buff, count_element);
		i++;
	}
}

void		stack_up(t_data *new, int *buff, int count)
{
	int		i;

	i = -1;
	while (count > ++i)
		new->a[new->count_element + i] = buff[i];
	new->count_element += count;
	free(buff);
}

int			*ft_intarrcpy(int *dst, const int *src, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
