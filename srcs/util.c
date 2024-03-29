/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:13:34 by hyeopark          #+#    #+#             */
/*   Updated: 2021/06/19 17:14:52 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putendl("Error");
	exit(1);
}

int		ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int		ft_isdigit(int c)
{
	return (c < 58 && c > 47);
}

int		ft_atoi(const char *str)
{
	long long			res;
	int					minus;
	int					dig;

	res = 0;
	minus = 1;
	dig = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		minus = 45 % *str++ - 1;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str++ - '0';
		dig++;
		if (dig > 10 || minus * res > 2147483647
			|| minus * res < (-2147483648))
			ft_error();
	}
	return (int)(minus * res);
}
