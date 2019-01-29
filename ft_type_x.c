/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/09 16:02:23 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts			*ft_type_x(va_list ap, t_pmts pmts)
{
	char		*res_str;
	long long	res;
	t_prts		*node;

	res = va_arg(ap, unsigned long long);
	res = ft_cast_given_mod(pmts, res);
	res_str = ft_itoa_base_ll_ed(res, 16);
	pmts.mod = 0;
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_data(&node, res_str));
//	else
//		return (ft_handle_o(pmts, &node, res_str));
	return (NULL);
}