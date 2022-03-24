/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:06:44 by jchin             #+#    #+#             */
/*   Updated: 2022/02/15 11:18:59 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 0)
		return (0);
	if (index <= 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}