/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:31:39 by jchin             #+#    #+#             */
/*   Updated: 2022/02/10 15:32:33 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	src_i;
	unsigned int	des_i;

	src_i = 0;
	des_i = 0;
	while (dest[des_i])
		des_i++;
	while (src_i < nb && src[src_i])
		dest[des_i++] = src[src_i++];
	dest[des_i] = '\0';
	return (dest);
}