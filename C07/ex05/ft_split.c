/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:55:19 by jchin             #+#    #+#             */
/*   Updated: 2022/02/20 13:31:03 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	count_strings(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i], charset))
			++i;
		if (str[i] && !is_in_charset(str[i], charset))
		{
			while (str[i] && !is_in_charset(str[i], charset))
				++i;
			++count;
		}
	}
	return (count);
}

char	*get_string(char *str, char *charset)
{
	char	*str_tmp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[len] && !is_in_charset(str[i], charset))
	{
		++len;
		++i;
	}
	str_tmp = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str_tmp[i] = str[i];
		++i;
	}
	str_tmp[i] = '\0';
	return (str_tmp);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * (count_strings(str, charset) + 1));
	while (*str)
	{
		while (*str && is_in_charset(*str, charset))
			++str;
		if (*str && !is_in_charset(*str, charset))
			strs[i++] = get_string(str, charset);
		while (*str && !is_in_charset(*str, charset))
			++str;
	}
	strs[i] = 0;
	return (strs);
}