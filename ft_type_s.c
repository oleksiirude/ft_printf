/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/23 17:12:01 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*t_prts	*ft_handle_s(t_pmts *pmts, t_prts **node, char *res)
{

	if ((pmts->plus && !pmts->zero) || !pmts->minus)
		return (ft_create_str_s(node, pmts->value, res, 0));
}*/

t_prts	*ft_rec_given_str(t_prts **node, char *res)
{
	size_t len;

	len = ft_strlen(res);
	(*node)->len = len;
	(*node)->str = (char*)malloc(sizeof(len + 1));
	len = 0;
	while (*res)
	{
		(*node)->str[len++] = *res;
		res++;
	}
	(*node)->str[len] = 0;
	(*node)->next = NULL;
	return (*node);
}

t_prts	*ft_type_s(va_list ap, t_pmts *pmts)
{
	char 	*res;
	t_prts	*node;

	res = va_arg(ap, char*);
	node = (t_prts*)malloc(sizeof(t_prts));
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_str(&node, res));
	/*if (pmts->value || pmts->zero)
		return (ft_handle_s(pmts, &node, res));*/

	return (node);
}

/*printf("minus-> %2d\n", pmts->minus);
printf("plus-> %3d\n", pmts->plus);
printf("space-> %2d\n", pmts->space);
printf("hash-> %3d\n", pmts->hash);
printf("value-> %2d\n", pmts->value);
printf("zero-> %3d\n", pmts->zero);
printf("zero_v-> %d\n", pmts->zero_value);
printf("prec-> %3d\n", pmts->prec);
printf("prec_v-> %d\n", pmts->prec_value);
printf("mod-> %4d\n", pmts->mod);
printf("type-> %3c\n", pmts->type);
printf("zero_c-> %d\n", pmts->type_c_zero_case);*/