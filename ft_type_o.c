/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:57:16 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/29 15:42:41 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts			*ft_type_o(va_list ap, t_pmts pmts)
{
	char		*res_str;
	long long	res;
	t_prts		*node;

	res = va_arg(ap, unsigned long long);
	res = ft_cast_given_mod(pmts, res);
	res_str = ft_itoa_base_ll_ed(res, 8);
	pmts.mod = 0;
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_data(&node, res_str));
//	else
//		return (ft_handle_o(pmts, &node, res_str));
	return (NULL);
}