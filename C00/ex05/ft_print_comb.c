/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:23:25 by jchin             #+#    #+#             */
/*   Updated: 2022/02/08 14:48:42 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	process(char *i, char *j, char *k)
{
	*k += 1;
	if (*k > '9')
	{
		*j += 1;
		if (*j <= '8')
		{
			*k = *j + 1;
		}
		else
		{
			*i += 1;
			*j = *i + 1;
			*k = *j + 1;
		}
	}
}

void ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	j = '1';
	k = '2';
	while (!(i >= '7' && j >= '8' && k >= '9'))
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
		if (!(i == '7' && j == '8' && k == '9'))
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
		process(&i, &j, &k);
	}
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
}