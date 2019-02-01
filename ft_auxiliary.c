/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/09 16:02:23 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_cast_given_mod(t_pmts *pmts, long long res)
{
	long long value;

	if (pmts->mod == H)
		value = (short)res;
	else if (pmts->mod == HH)
		value = (char)res;
	else if (pmts->mod == L)
		value = (long)res;
	else if (pmts->mod == LL)
		value = res;
	else
	{
		if (pmts->type == 'u' || pmts->type == 'x' ||
				pmts->type == 'X' || pmts->type == 'o')
			value = (unsigned int)res;
		else
			value = (int)res;
	}
	pmts->mod = 0;
	return (value);
}

t_prts		*ft_rec_given_data(t_prts **node, char *res)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(res);
	(*node)->len = len;
	(*node)->str = (char*)malloc(len + 1);
	len = 0;
	while (res[i])
		(*node)->str[len++] = res[i++];
	(*node)->str[len] = 0;
	free(res);
	return (*node);
}

int			ft_atoi_modificated(char **fmt, int sign)
{
	size_t	res;

	res = 0;
	if (sign)
		if (**fmt == '-')
			(*fmt)++;
	while (**fmt)
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			res = 10 * res + (**fmt - '0');
			(*fmt)++;
		}
		(*fmt)--;
		if (res > 9223372036854775807)
			return (2147483647);
		return ((int)res);
	}
	return (0);
}

void		ft_find_last_node(t_prts **start, t_prts **node)
{
	*(node) = *(start);
	while ((*node)->next)
		*node = (*node)->next;
}

size_t		ft_calc_flags_sum(t_pmts pmts)
{
	size_t res;

	res = pmts.minus + pmts.plus + pmts.space +
			pmts.hash + pmts.value + pmts.zero +
			pmts.prec + pmts.mod;
	return (res);
}
