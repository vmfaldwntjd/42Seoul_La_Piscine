/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:21:57 by jchin             #+#    #+#             */
/*   Updated: 2022/02/10 15:19:25 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
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
	return (dest);
}