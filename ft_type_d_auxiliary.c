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

void	ft_set_d_flags_according_to_input(t_pmts *pmts, int *minus, char c)
{
	*minus = 0;
	if (pmts->plus)
		pmts->space = 0;
	if (c == '-')
	{
		*minus = 1;
		pmts->space = 0;
		pmts->plus = 0;
	}
	pmts->hash = 0;
	pmts->mod = 0;
}