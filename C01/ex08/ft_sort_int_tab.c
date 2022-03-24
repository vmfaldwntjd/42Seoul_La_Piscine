/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:36:34 by jchin             #+#    #+#             */
/*   Updated: 2022/02/07 12:00:49 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		min_index = i;
		while (j < size)
		{
			if (tab[min_index] > tab[j])
			{
				min_index = j;
			}
			j++;
		}
		ft_swap(&tab[i], &tab[min_index]);
		i++;
	}
}