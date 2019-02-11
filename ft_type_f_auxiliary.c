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

long double	ft_round_off(long double res, t_pmts *pmts)
{
	long long 	tmp;
	int 		prec;
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
	prec = pmts->prec_value ? pmts->prec_value: 6;
	if (pmts->prec && !pmts->prec_value)
		prec = 0;
	if (prec == 1)
	{
		prec += 1;
		res += 0.01;
	}
	mns = res < 0.0 ? -1 : 1;
	if (res < 0.0)
		res *= -1;
	nb = ft_exp(10, (size_t)prec + 1);
	tmp = (long long)((double)res * nb) % 10;
	if (tmp == 9)
		tmp = 0;
	if (tmp >= 5)
		return ((res + (1.0 / (nb / 10.0))) * mns);
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
