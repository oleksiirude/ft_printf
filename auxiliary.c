/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/09 16:02:23 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_last_node(t_prts **start, t_prts **node)
{
	*(node) = *(start);
	while ((*node)->next)
		*node = (*node)->next;
}

void	ft_set_flgs_to_zero(t_flgs *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->value = 0;
	flags->zero = 0;
	flags->zero_value = 0;
	flags->precision = 0;
	flags->precision_value = 0;
	flags->mod = 0;
	flags->type = 0;
}