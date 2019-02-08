/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_round_off(char *str, t_pmts pmts)
{
	int tmp;
	int	len;

	len = (int)ft_strlen(str) - 1;
	tmp = len;
	printf("before[%s]\n", str);
	while (str[len] == '9')
	{
		str[len] -= 9;
		len--;
		if (str[len] != '9')
		{
			str[len] += 1;
			break;
		}
	}
	printf("[%c]\n", str[tmp]);
	if (str[tmp] >= '5')
	{
		if (str[tmp - 1] == '9')
			str[tmp - 1] -= 9;
		else
			str[tmp - 1] += 1;
	}
	printf("after [%s]\n", str);
	return (str);
}

void	ft_max(long double *res, size_t *e)
{
	size_t 	val;

	val = *e - 19;
	if (val > 19)
		val = 19;
	*res /= ft_exp(10, val);
	*e = 19;
}

size_t	ft_exp(size_t nb, size_t pow)
{
	size_t	res;

	res = nb;
	if (pow < 0)
		return (0);
	if (!pow)
		return (1);
	else if (pow > 1)
		while (pow-- > 1)
			res *= nb;
	return (res);
}