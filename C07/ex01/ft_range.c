/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:22:37 by jchin             #+#    #+#             */
/*   Updated: 2022/02/16 15:08:24 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min < max)
	{
		arr = (int *)malloc(sizeof(int) * (max - min));
		i = 0;
		while (i < (max - min))
		{
			arr[i] = min + i;
			++i;
		}
		return (arr);
	}
	return (0);
}