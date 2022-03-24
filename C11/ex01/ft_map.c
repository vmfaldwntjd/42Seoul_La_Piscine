/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:09:32 by jchin             #+#    #+#             */
/*   Updated: 2022/02/23 16:00:43 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*num;
	int	i;

	num = (int *)malloc(sizeof(int) * length);
	if (!num)
		return (0);
	i = 0;
	while (i < length)
	{
		num[i] = f(tab[i]);
		++i;
	}
	return (num);
}