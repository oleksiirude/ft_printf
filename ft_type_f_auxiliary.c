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

void		ft_set_f_flags(t_pmts *pmts)
{
	if (!pmts->prec_value)
	{
		pmts->prec = 1;
		pmts->prec_value = 6;
	}
}

void		ft_handle_res_minus(long double *r, va_list ap, int *mns, int mod)
{
	*mns = 0;
	if (mod != LBIG)
		*r = va_arg(ap, double);
	else
		*r = va_arg(ap, long double);
	if (*r < 0.0l)
	{
		*r *= -1.0l;
		*mns = 1;
	}
}

long double	ft_round_off(long double res, int prec)
{
	long double nb;

	nb = ft_exp(10, (size_t)prec + 1);
	if ((long long)(res * nb) % 10 >= 5)
		return (res + (1.0l / (nb / 10.0l)));
	return (res);
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
