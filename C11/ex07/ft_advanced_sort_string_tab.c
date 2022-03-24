/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:09:18 by jchin             #+#    #+#             */
/*   Updated: 2022/02/23 18:51:36 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *s1, char *s2))
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (tab[i])
	{
		min_idx = i;
		j = i + 1;
		while (tab[j])
		{
			if (cmp(tab[min_idx], tab[j]) > 0)
				min_idx = j;
			++j;
		}
		swap(&tab[min_idx], &tab[i]);
		++i;
	}
}