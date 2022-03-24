/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:59:42 by jchin             #+#    #+#             */
/*   Updated: 2022/02/15 19:56:46 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
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

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	min_index;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		min_index = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[min_index], argv[j]) > 0)
				min_index = j;
			++j;
		}
		swap(&argv[min_index], &argv[i]);
		ft_putstr(argv[i]);
		++i;
	}
	return (0);
}