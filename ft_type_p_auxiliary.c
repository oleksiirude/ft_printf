/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/23 17:12:01 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_put_ptr_adr_whithout_flags(char *res, t_prts **node)
{
	size_t i;

	i = 0;
	(*node)->str = (char*)malloc(ft_strlen(res) + 3);
	(*node)->str[i] = '0';
	(*node)->str[i + 1] = 'x';
	(*node)->str += 2;
	(*node)->str = ft_strcpy((*node)->str, res);
	(*node)->str -= 2;
	(*node)->len = ft_strlen(res) + 2;
	return (*node);
}

size_t	ft_getting_total_len_p(t_pmts *pmts, size_t len)
{
	if (pmts->zero_value && pmts->zero_value <= len)
	{
		pmts->zero = 0;
		pmts->zero_value = 0;
		pmts->value = (int)len;
		return (len);
	}
	if (pmts->zero_value && pmts->zero_value > len)
		return ((size_t)pmts->zero_value);
	if (pmts->value && pmts->value <= len)
	{
		pmts->minus = 0;
		return (len);
	}
	if (pmts->value && pmts->value > len)
		return ((size_t)pmts->value);
}
