/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_create_str_perc(t_prts **node, size_t value, int sign)
{
	size_t i;

	i = -1;
	(*node)->str = (char*)malloc((size_t)value + 1);
	(*node)->len = (size_t)value;
	(*node)->next = NULL;
	if (!sign || sign == 1)
	{
		while (value > ++i)
			(*node)->str[i] = sign ? '0' : ' ';
		(*node)->str[--i] = '%';
	}
	else if (sign == 2)
	{
		(*node)->str[++i] = '%';
		while (value > ++i)
			(*node)->str[i] = ' ';
	}
	return (*node);
}

t_prts	*ft_handle_perc(t_pmts pmts, t_prts **node)
{
	if (pmts.prec_value < 0)
		return (ft_create_str_perc(node, pmts.prec_value * -1, 2));
	else if (!pmts.zero && !pmts.minus)
		return (ft_create_str_perc(node, pmts.value, 0));
	else if (pmts.zero)
		return (ft_create_str_perc(node, pmts.zero_value, 1));
	else if (pmts.minus)
		return (ft_create_str_perc(node, pmts.value, 2));
	return (NULL);
}

t_prts	*ft_type_perc(t_pmts pmts)
{
	t_prts	*node;

	node = (t_prts*)malloc(sizeof(t_prts));
	if (pmts.value || pmts.zero || pmts.prec_value < 0)
		return (ft_handle_perc(pmts, &node));
	node->str = (char*)malloc(1);
	node->len = 1;
	node->next = NULL;
	node->str[0] = '%';
	return (node);
}

t_prts	*ft_valid_str_form(va_list ap, t_pmts pmts)
{
	if (pmts.type == PERC)
		return (ft_type_perc(pmts));
	else if (pmts.type == 'c')
		return (ft_type_c(ap, pmts));
	else if (pmts.type == 's')
		return (ft_type_s(ap, pmts));
	else if (pmts.type == 'p')
		return (ft_type_p(ap, pmts));
	else if (pmts.type == 'd' || pmts.type == 'i')
		return (ft_type_d(ap, pmts));
	else if (pmts.type == 'o')
		return (ft_type_o(ap, pmts));
	else if (pmts.type == 'u')
		return (ft_type_u(ap, pmts));
	else if (pmts.type == 'x' || pmts.type == 'X')
		return (ft_type_x(ap, pmts));
	return (NULL);
}
