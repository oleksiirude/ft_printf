/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_auxiliary.c  	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_d_flags(t_pmts *pmts, int *minus, char c, size_t len)
{
	*minus = 0;
	if (pmts->prec_value && pmts->prec_value < (int)len)
		pmts->prec_value = (int)len;
	if (pmts->plus)
		pmts->space = 0;
	if (pmts->prec && !pmts->prec_value)
	{
		pmts->prec = 0;
		pmts->zero = 0;
		if (pmts->zero_value)
		{
			pmts->value = pmts->zero_value;
			pmts->zero_value = 0;
		}
	}
	if (pmts->prec_value && pmts->prec_value <= (int)len
		&& (pmts->zero_value || pmts->value))
	{
		pmts->prec = 0;
		if (pmts->zero_value > len)
		{
			pmts->value = pmts->zero_value;
			pmts->prec_value = 0;
			pmts->zero_value = 0;
			pmts->zero = 0;
		}
		if (pmts->value > len)
			pmts->prec_value = 0;
	}
	if (pmts->prec_value < 0)
	{
		pmts->value = pmts->prec_value * -1;
		pmts->minus = 1;
		pmts->zero = 0;
		pmts->zero_value = 0;
		pmts->prec = 0;
		pmts->prec_value = 0;
	}
	if (pmts->prec_value > (int)len && pmts->zero_value)
	{
		pmts->value = pmts->zero_value;
		pmts->zero_value = 0;
		pmts->zero = 0;
	}
	if (c == '-')
	{
		*minus = 1;
		pmts->space = 0;
		pmts->plus = 0;
	}
	pmts->hash = 0;
	pmts->mod = 0;
}