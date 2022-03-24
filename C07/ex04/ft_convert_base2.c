/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:12:45 by jchin             #+#    #+#             */
/*   Updated: 2022/02/17 16:52:34 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checking(char *base, int base_num);

int	get_mal_len(int nbr, int base_num, unsigned int mal_len)
{
	unsigned int	nb;

	if (nbr < 0)
	{
		nb = (unsigned int)(nbr * (-1));
		mal_len++;
	}
	else
		nb = (unsigned int)nbr;
	while (nb >= (unsigned int)base_num)
	{
		nb /= base_num;
		mal_len++;
	}
	mal_len++;
	return (mal_len);
}

void	ft_putnbr_base(int nbr, char *base, char *dest, int base_to_len)
{
	long long	nb;
	int			i;
	int			base_idx;

	nb = (long long)nbr;
	base_idx = get_mal_len(nbr, base_to_len, 0);
	i = 0;
	if (nbr < 0)
	{
		dest[0] = '-';
		nb *= -1;
		i = 1;
	}
	--base_idx;
	while (nb >= base_to_len)
	{
		dest[base_idx] = base[nb % base_to_len];
		nb /= base_to_len;
		--base_idx;
	}
	if (nb < base_to_len)
		dest[i] = base[nb % base_to_len];
}