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

t_prts	*ft_simply_add_perc(void)
{
	t_prts	*node;

	node = (t_prts*)malloc(sizeof(t_prts));
	node->str = (char*)malloc(2);
	node->len = 1;
	node->next = NULL;
	node->str[0] = '%';
	node->str[1] = 0;
	return (node);
}

t_prts	*ft_valid_str_formation(va_list ap, t_pmts *params)
{
	if (params->type == PERC)
	{
		free(params);
		return (ft_simply_add_perc());
	}
	return (NULL);
}
