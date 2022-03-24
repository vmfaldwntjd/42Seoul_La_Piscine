/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:40:55 by jchin             #+#    #+#             */
/*   Updated: 2022/02/08 14:50:38 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	print(int	i, int	j)
{
	ft_putchar(i / 10 + '0');
	ft_putchar(i % 10 + '0');
	ft_putchar(' ');
	ft_putchar(j / 10 + '0');
	ft_putchar(j % 10 + '0');
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 98)
	{
		j += 1;
		if (i < j)
		{
			print(i, j);
			if (i != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		if (j >= 99)
		{
			j = 0;
			i += 1;
		}
	}
}