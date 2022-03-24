/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:01:17 by jchin             #+#    #+#             */
/*   Updated: 2022/02/23 17:55:59 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc_count;
	int	des_count;

	asc_count = 0;
	des_count = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			++des_count;
		if (f(tab[i], tab[i + 1]) <= 0)
			++asc_count;
		++i;
	}
	if (des_count == i || asc_count == i)
		return (1);
	return (0);
}