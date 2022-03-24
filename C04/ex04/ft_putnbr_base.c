/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:11:54 by jchin             #+#    #+#             */
/*   Updated: 2022/02/14 20:17:30 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	check(char *base, int base_num)
{
	int	i;
	int	j;

	i = 0;
	if (base_num <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] >= '\t' \
		&& base[i] <= '\r') || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-' \
			|| base[j] == ' ' || (base[j] >= '\t' && base[j] <= '\r'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print(char *base, int nbr, int base_num)
{
	if (nbr >= 0)
	{
		if (nbr >= 0 && nbr < base_num)
		{
			write(1, &(base[nbr % base_num]), 1);
			return ;
		}
		print(base, nbr / base_num, base_num);
		write(1, &base[nbr % base_num], 1);
	}
	else
	{
		if (nbr == -2147483648)
		{
			print(base, nbr / base_num, base_num);
			write(1, &(base[-(nbr % base_num)]), 1);
		}
		else
		{
			nbr *= -1;
			write(1, "-", 1);
			print(base, nbr, base_num);
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_num;

	base_num = 0;
	while (base[base_num])
		base_num++;
	if (check(base, base_num))
	{
		print(base, nbr, base_num);
	}
}