/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:39:29 by jchin             #+#    #+#             */
/*   Updated: 2022/02/15 21:46:32 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc > 0)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
				write(1, &argv[i][j++], 1);
			write(1, "\n", 1);
			++i;
		}
	}
	return (0);
}