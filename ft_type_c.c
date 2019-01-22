/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_create_str_c(t_prts **node, int value, int res, int sign)
{
	int i;

	i = -1;
	if (!sign)
	{
		(*node)->str = (char*)malloc((size_t)value + 1);
		(*node)->len = (size_t)value;
		(*node)->next = NULL;
		while (value > ++i)
			(*node)->str[i] = ' ';
		(*node)->str[--i] = (unsigned char)res;
		return (*node);
	}
}

t_prts	*ft_handle_c(t_pmts *pmts, t_prts **node, int res)
{
	if (pmts->minus)
		pmts->zero = 0;
	if (pmts->plus && !pmts->zero)
		return (ft_create_str_c(node, pmts->value, res, 0));
	/*else if (pmts->minus)
		return (ft_create_str_c(node, res, pmts->value, 1));
	else if (pmts->plus && pmts->zero)
		return (ft_create_str_c(node, res, pmts->zero_value, 2));*/
}

t_prts	*ft_type_c(va_list ap, t_pmts *pmts)
{
	int		res;
	t_prts	*node;

	res = va_arg(ap, int);
	node = (t_prts*)malloc(sizeof(t_prts));
	if (pmts->value || pmts->zero)
		return (ft_handle_c(pmts, &node, res));
	node->str = (char*)malloc(1);
	node->len = 1;
	node->next = NULL;
	node->str[0] = (unsigned char)res;
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