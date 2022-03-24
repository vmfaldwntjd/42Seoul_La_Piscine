/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:45:58 by jchin             #+#    #+#             */
/*   Updated: 2022/02/23 18:51:21 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"do_op.h"

int	op(int a, char *c, int b)
{
	int	result;
	int	(*op[5])(int, int);

	op[0] = ft_add;
	op[1] = ft_sub;
	op[2] = ft_mul;
	op[3] = ft_div;
	op[4] = ft_mod;
	result = 1;
	if (*c == '+')
		result = op[0](a, b);
	if (*c == '-')
		result = op[1](a, b);
	if (*c == '*')
		result = op[2](a, b);
	if (*c == '/')
		result = op[3](a, b);
	if (*c == '%')
		result = op[4](a, b);
	return (result);
}

void	do_op(char *s1, char *s2, char *s3)
{
	int	s1_to_num;
	int	s3_to_num;
	int	result;

	s1_to_num = ft_atoi(s1);
	s3_to_num = ft_atoi(s3);
	result = 1;
	if (!(*s2 == '+' || *s2 == '-' || *s2 == '/' || *s2 == '*' || *s2 == '%') \
	|| s2[1] != '\0')
		write(1, "0", 1);
	else if (*s2 == '/' && s3_to_num == 0)
		write(1, "Stop : division by zero", 23);
	else if (*s2 == '%' && s3_to_num == 0)
		write(1, "Stop : modulo by zero", 21);
	else
	{
		result *= op(s1_to_num, s2, s3_to_num);
		ft_putnbr(result);
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
		do_op(argv[1], argv[2], argv[3]);
	return (0);
}