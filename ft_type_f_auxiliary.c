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

t_prts	*ft_handle_f_p(t_pmts p, t_prts **n, char *r)
{
	char	*tmp;
	size_t	var;

	if (p.plus || p.space)
		var = p.value - ft_strlen(r) - 1;
	else
		var = p.value - ft_strlen(r);
	tmp = ft_malloc_sz(var);
	tmp = ft_memset(tmp, 32, var);
	if (p.space)
	{
		r = ft_strjoin_free(" ", r, 2);
		p.plus = 0;
	}
	if (p.plus)
		r = ft_strjoin_free("+", r, 2);
	r = p.minus ? ft_strjoin_free(r, tmp, 3) : ft_strjoin_free(tmp, r, 3);
	(*n)->str = r;
	(*n)->len = ft_strlen(r);
	return (*n);
}

void	ft_handle_res(long double *res, va_list ap, int mod)
{
	if (mod != LBIG)
		*res = va_arg(ap, double);
	else
		*res = va_arg(ap, long double);
}

void	ft_max(long double *res, size_t *e)
{
	size_t	val;

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
	if (!pow)
		return (1);
	else if (pow > 1)
		while (pow-- > 1)
			res *= nb;
	return (res);
}

char	*ft_check_nan_and_inf(long double res, t_pmts *pmts)
{
	if (res != res)
	{
		if (pmts->zero_value)
		{
			pmts->value = pmts->zero_value;
			pmts->zero_value = 0;
			pmts->zero = 0;
		}
		return (ft_strdup("nan"));
	}
	else if (res * 2 == res && res != 0)
	{
		if (pmts->zero_value)
		{
			pmts->value = pmts->zero_value;
			pmts->zero_value = 0;
			pmts->zero = 0;
		}
		return (res < 0.0 ? ft_strdup("-inf") : ft_strdup("inf"));
	}
	return (NULL);
}
