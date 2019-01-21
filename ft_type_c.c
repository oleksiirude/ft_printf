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

t_prts	*ft_type_c(va_list ap, t_pmts **pmts)
{
	int		result;
	t_prts	*node;

	free(pmts);
	result = va_arg(ap, int);
	node = (t_prts*)malloc(sizeof(t_prts));
	node->sz = NO;
	if (!result)
		node->sz = YES;
	node->str = (char*)malloc(1);
	node->len = 1;
	node->next = NULL;
	node->str[0] = (unsigned char)result;
	return (node);
}
