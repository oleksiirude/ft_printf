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

void		ft_handle_res_minus(long double *r, va_list ap, int mod)
{
	if (mod != LBIG)
		*r = va_arg(ap, double);
	else
		*r = va_arg(ap, long double);
}

long double	ft_round_off(long double res, t_pmts *pmts)
{
	int 		perc;
	int			mns;
	long double nb;

	if (pmts->prec_value < 0)
	{
		pmts->value = pmts->prec_value * -1;
		pmts->minus = 1;
		pmts->zero = 0;
		pmts->zero_value = 0;
		pmts->prec_value = 0;
	}
	perc = pmts->prec_value ? pmts->prec_value : 6;
	mns = res < 0.0l ? -1 : 1;
	if (res < 0.0l)
		res *= -1;
	nb = ft_exp(10, (size_t)perc + 1);
	if ((long long)(res * nb) % 10 >= 5)
		return ((res + (1.0l / (nb / 10.0l))) * mns);
	return (res * mns);
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
