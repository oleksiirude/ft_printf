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

void		ft_handle_res(long double *res, va_list ap, int mod)
{
	if (mod != LBIG)
		*res = va_arg(ap, double);
	else
		*res = va_arg(ap, long double);
}

void		ft_max(long double *res, size_t *e)
{
	size_t	val;

	val = *e - 19;
	if (val > 19)
		val = 19;
	*res /= ft_exp(10, val);
	*e = 19;
}

size_t		ft_exp(size_t nb, size_t pow)
{
	size_t	res;

	res = nb;
	if (!pow)
		return (1);
	else if (pow > 1)
		while (pow-- > 1)
			res *= nb;
	return (res);
}
