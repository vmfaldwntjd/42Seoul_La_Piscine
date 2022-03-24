/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:49:04 by jchin             #+#    #+#             */
/*   Updated: 2022/02/13 10:50:54 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_temp;
	char	*str_idx;
	char	*find_temp;

	str_temp = str;
	if (!*to_find)
		return (str);
	while (*str_temp)
	{
		str_idx = str_temp;
		find_temp = to_find;
		while (*str_idx && *find_temp && !(*str_idx - *find_temp))
		{
			str_idx++;
			find_temp++;
		}
		if (!*find_temp)
			return (str_temp);
		str_temp++;
	}
	return (0);
}