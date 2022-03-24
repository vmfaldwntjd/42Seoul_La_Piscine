/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:44:49 by jchin             #+#    #+#             */
/*   Updated: 2022/02/19 20:26:58 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int		get_mal_len(int nbr, int base_num, unsigned int mal_len);
void	ft_putnbr_base(int nbr, char *base, char *dest, int base_to_len);

int	checking(char *base, int base_num)
{
	int	i;
	int	j;

	i = 0;
	if (base_num <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] >= '\t' \
		&& base[i] <= '\r') || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-' \
			|| base[j] == ' ' || (base[j] >= '\t' && base[j] <= '\r'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_in_base(char c, char *base, int base_nbr)
{
	int	i;

	i = 0;
	while (i < base_nbr && base[i])
	{
		if (base[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	process(char *str, char *base, int base_nbr, int cur_idx)
{
	int	result;
	int	i;

	result = 0;
	while (is_in_base(str[cur_idx], base, base_nbr))
	{
		i = 0;
		while (base[i] && base[i] != str[cur_idx])
			++i;
		result = result * base_nbr + i;
		++cur_idx;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base, int base_nbr)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	if (checking(base, base_nbr))
	{
		while ((str[i] >= '\t' && str[i] <= '\r') \
		|| str[i] == ' ')
			++i;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			++i;
		}
		if (is_in_base(str[i], base, base_nbr))
			result = process(str, base, base_nbr, i);
		return (result * sign);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		base_from_len;
	int		base_to_len;
	int		mal_len;
	char	*dest;

	base_from_len = 0;
	base_to_len = 0;
	while (base_from[base_from_len])
		++base_from_len;
	while (base_to[base_to_len])
		++base_to_len;
	if (!(checking(base_from, base_from_len) && checking(base_to, base_to_len)))
		return (0);
	num = ft_atoi_base(nbr, base_from, base_from_len);
	mal_len = get_mal_len(num, base_to_len, 0);
	dest = (char *)malloc(sizeof(char) * (mal_len + 1));
	if (!dest)
		return (0);
	ft_putnbr_base(num, base_to, dest, base_to_len);
	dest[mal_len] = '\0';
	return (dest);
}