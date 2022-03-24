/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:45:14 by jchin             #+#    #+#             */
/*   Updated: 2022/02/20 13:43:48 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	if (size > 0)
	{
		while (i < size)
		{
			result += ft_strlen(strs[i]);
			i++;
		}
		result += ft_strlen(sep) * (size - 1);
		return (result);
	}
	return (result);
}

void	ft_strcat(char *dest, char *src)
{
	int	dest_i;
	int	src_i;

	src_i = 0;
	dest_i = 0;
	while (dest[dest_i])
		dest_i++;
	while (src[src_i])
		dest[dest_i++] = src[src_i++];
	dest[dest_i] = '\0';
}

void	init(char *s, int total_len)
{
	int	i;

	i = 0;
	while (i < total_len)
		s[i++] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		total_len;
	int		i;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	i = 0;
	total_len = get_total_len(size, strs, sep);
	s = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!s)
		return (0);
	init(s, total_len);
	while (i < size)
	{
		ft_strcat(s, strs[i]);
		if (i < size - 1)
			ft_strcat(s, sep);
		++i;
	}
	return (s);
}