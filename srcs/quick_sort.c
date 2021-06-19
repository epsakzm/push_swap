/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:59:23 by hyeopark          #+#    #+#             */
/*   Updated: 2021/06/19 17:03:17 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *array, int start, int end)
{
	int q;

	if (start < end)
	{
		q = partition(array, start, end);
		quick_sort(array, start, q - 1);
		quick_sort(array, q + 1, end);
	}
}

int		partition(int *array, int start, int end)
{
	int pivot;
	int i;
	int temp;
	int j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}
