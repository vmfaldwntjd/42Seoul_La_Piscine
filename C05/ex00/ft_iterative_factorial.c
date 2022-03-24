/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:38:06 by jchin             #+#    #+#             */
/*   Updated: 2022/02/15 11:24:20 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	mul_num;
	int	result;

	if (nb < 0)
		return (0);
	mul_num = 1;
	result = 1;
	while (mul_num <= nb)
		result *= mul_num++;
	return (result);
}