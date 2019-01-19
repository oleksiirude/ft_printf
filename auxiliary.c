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

int	ft_atoi_light(char **fmt)
{
	int	res;

	res = 0;
	while (**fmt)
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			res = 10 * res + (**fmt - '0');
			(*fmt)++;
		}
		return (res);
	}
	return (0);
}

void	ft_find_last_node(t_prts **start, t_prts **node)
{
	*(node) = *(start);
	while ((*node)->next)
		*node = (*node)->next;
}

t_pmts	*ft_set_flags_to_zero(void)
{
	t_pmts	*flags;

	flags = (t_pmts*)malloc(sizeof(t_pmts));
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->value = 0;
	flags->zero = 0;
	flags->zero_value = 0;
	flags->prec = 0;
	flags->prec_value = 0;
	flags->mod = 0;
	flags->type = 0;
	return (flags);
}