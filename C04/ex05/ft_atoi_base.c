/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:04:34 by jchin             #+#    #+#             */
/*   Updated: 2022/02/17 15:38:23 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	return_result(char *str, char *base, int base_nbr, int cur_idx)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((str[cur_idx] >= '\t' && str[cur_idx] <= '\r') \
	|| str[cur_idx] == ' ')
		++cur_idx;
	while (str[cur_idx] == '+' || str[cur_idx] == '-')
	{
		if (str[cur_idx] == '-')
			sign *= -1;
		++cur_idx;
	}
	if (is_in_base(str[cur_idx], base, base_nbr))
		result = process(str, base, base_nbr, cur_idx);
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_nbr;

	base_nbr = 0;
	while (base[base_nbr])
		base_nbr++;
	if (checking(base, base_nbr))
		return (return_result(str, base, base_nbr, 0));
	return (0);
}