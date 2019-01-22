/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2nd_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_case(char **fmt, t_pmts **params)
{
	(*params)->prec = 1;
	if ((*(*fmt) + 1) >= '0' || (*(*fmt) + 1) <= '9')
	{
		(*fmt)++;
		(*params)->prec_value = ft_atoi_light(fmt);
	}
}

void	ft_zero_case(char **fmt, t_pmts **params)
{
		if ((*params)->minus)
		{
			if ((*(*fmt) + 1) >= '0' || (*(*fmt) + 1) <= '9')
				(*params)->value = ft_atoi_light(fmt);
		}
		else
		{
			(*params)->zero = 1;
			if ((*(*fmt) + 1) >= '0' || (*(*fmt) + 1) <= '9')
				(*params)->zero_value = ft_atoi_light(fmt);
		}
}

void	ft_h_or_hh_case(char **fmt, t_pmts **params)
{
	if (*(*fmt + 1) == 'h')
	{
		(*params)->mod = HH;
		(*fmt)++;
	}
	else
		(*params)->mod = H;
}

void	ft_l_or_ll_case(char **fmt, t_pmts **params)
{
	if (*(*fmt + 1) == 'l')
	{
		(*params)->mod = LL;
		(*fmt)++;
	}
	else
		(*params)->mod = L;
}

void	ft_rec_params(char **fmt, t_pmts **params)
{
	if (**fmt == '.')
		ft_prec_case(fmt, params);
	else if (**fmt == '0')
		ft_zero_case(fmt, params);
	else if (**fmt == H)
		ft_h_or_hh_case(fmt, params);
	else if (**fmt == L)
		ft_l_or_ll_case(fmt, params);
	else if (**fmt >= '1' && **fmt <= '9')
		(*params)->value = ft_atoi_light(fmt);
	else if (**fmt == '#')
		(*params)->hash = 1;
	else if (**fmt == '+')
		(*params)->plus = 1;
	else if (**fmt == '-')
		(*params)->minus = 1;
	else if (**fmt == ' ')
		(*params)->space = 1;
	else if (**fmt == L)
		(*params)->mod = LBIG;
}

