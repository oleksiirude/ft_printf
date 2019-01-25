/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/23 17:12:01 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t 	ft_work_with_zero_value(t_pmts *pmts, size_t len)
{
	if (pmts->prec && !pmts->prec_value)
		return ((size_t)pmts->zero_value);
	if (pmts->zero_value < pmts->prec_value && pmts->prec_value <= len)
		return ((size_t)pmts->prec_value);
	if (pmts->zero_value < len && !pmts->prec_value)
		return (len);
	if (pmts->zero_value < len && pmts->prec_value < len)
		return ((size_t)pmts->zero_value);
	if (pmts->zero_value < len && pmts->prec_value > len)
		return (len);
	if (pmts->zero_value && pmts->prec_value > len)
		return ((size_t)pmts->zero_value);
	if (pmts->zero_value && pmts->prec_value)
		return ((size_t)pmts->zero_value);
	return ((size_t)pmts->zero_value);
}

size_t 	ft_work_with_value(t_pmts *pmts, size_t len)
{
	if (pmts->prec && !pmts->prec_value)
		return ((size_t)pmts->value);
	if (pmts->value < pmts->prec_value && pmts->prec_value <= len)
		return ((size_t)pmts->prec_value);
	if (pmts->value < len && !pmts->prec_value)
		return (len);
	if (pmts->value < len && pmts->prec_value < len)
		return ((size_t)pmts->value);
	if (pmts->value < len && pmts->prec_value > len)
		return (len);
	if (pmts->value && pmts->prec_value > len)
		return ((size_t)pmts->value);
	if (pmts->value && pmts->prec_value)
		return ((size_t)pmts->value);
	return ((size_t)pmts->value);
}

size_t	ft_getting_total_len_s(t_pmts *pmts, size_t len)
{
	if (pmts->prec_value < 0)
		return ((size_t)pmts->prec_value * -1);
	if (pmts->zero && !pmts->zero_value)
		return (len);
	if (pmts->zero_value)
		return (ft_work_with_zero_value(pmts, len));
	if (pmts->value)
		return (ft_work_with_value(pmts, len));
	if (pmts->prec_value < len)
		return ((size_t)pmts->prec_value);
	else
		return (len);
}