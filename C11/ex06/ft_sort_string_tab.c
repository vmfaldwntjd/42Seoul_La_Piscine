/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:54:27 by jchin             #+#    #+#             */
/*   Updated: 2022/02/23 18:47:19 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[min_idx], tab[j]) > 0)
				min_idx = j;
			++j;
		}
		swap(&tab[min_idx], &tab[i]);
		++i;
	}
}