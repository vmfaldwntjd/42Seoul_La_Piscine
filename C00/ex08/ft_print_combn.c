/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:45:12 by jchin             #+#    #+#             */
/*   Updated: 2022/02/08 14:51:40 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	g_arr[10];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int index_for_pri, int n)
{
	while (index_for_pri < n)
	{
		ft_putchar(g_arr[index_for_pri] + '0');
		index_for_pri++;
	}
	if (!(g_arr[index_for_pri - 1] == 9 &&
			g_arr[index_for_pri - 1] - g_arr[0] == n - 1))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	print_seq(int x, int len, int n)
{
	int	value;

	if (len == n)
	{
		print(0, n);
		return;
	}
	value = x;
	while (1)
	{
		if (value > 9)
			break;
		g_arr[len] = value;
		print_seq(value + 1, len + 1, n);
		value++;
	}
	return;
}

void	ft_print_combn(int n)
{
	print_seq(0, 0, n);
}