/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_rec_given_str(t_prts **node, char *res)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(res);
	(*node)->len = len;
	(*node)->str = (char*)malloc(len + 1);
	len = 0;
	while (res[i])
		(*node)->str[len++] = res[i++];
	(*node)->str[len] = 0;
	return (*node);
}

t_prts	*ft_type_p(va_list ap, t_pmts pmts)
{
	unsigned long long	res;
	t_prts	*node;

	res = va_arg(ap, unsigned long long);
	pmts.plus = 0;
	pmts.space = 0;
	pmts.hash = 0;
	pmts.mod = 0;
	if (pmts.zero && pmts.value)
	{
		pmts.zero_value = pmts.value;
		pmts.value = 0;
	}
	if (!pmts.zero_value && !pmts.value)
		pmts.minus = 0;
	if (pmts.prec_value < 0)
		pmts.zero_value = 0;
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_ptr(&node, res));
	else
		return (ft_handle_p(pmts, &node, res));
}