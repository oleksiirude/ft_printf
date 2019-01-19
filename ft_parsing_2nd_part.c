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
