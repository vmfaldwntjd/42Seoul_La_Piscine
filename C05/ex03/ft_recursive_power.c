/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:05:50 by jchin             #+#    #+#             */
/*   Updated: 2022/02/15 11:02:00 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursive(int nb, int power, int result)
{
	if (power <= 0)
		return (1);
	return (nb * recursive(nb, power - 1, result *= nb));
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (recursive(nb, power, 1));
}