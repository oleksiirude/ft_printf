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

t_prts	*ft_form_case1(t_prts **node, char *res, size_t lfin)
{
	size_t i;
	size_t zero;

	i = 0;
	zero = lfin - ft_strlen(res);
	(*node)->str[i] = '0';
	(*node)->str[i + 1] = 'x';
	lfin = 0;
	while (res[lfin])
		(*node)->str[zero++] = res[lfin++];
	free(res);
	return (*node);
}

t_prts	*ft_form_case2(t_prts **node, t_pmts pmts, char *res, size_t lfin)
{
	char	*tmp;
	size_t	start;

	res = ft_strjoin_free("0x", res, 1);
	tmp = res;
	start = pmts.minus ? 0 : lfin - ft_strlen(res);
	while (*res)
		(*node)->str[start++] = *res++;
	free(tmp);
	return (*node);
}

t_prts	*ft_handle_p(t_pmts pmts, t_prts **node, char *res)
{
	size_t	len_res;
	size_t	len_final;

	if (!ft_calc_flags_sum(pmts))
		return (ft_put_ptr_adr_whithout_flags(res, node));
	len_res = ft_strlen(res);
	len_final = (ft_getting_total_len_p(&pmts, len_res));
	(*node)->str = (char*)malloc(len_final + 1);
	(*node)->len = len_final;
	if ((pmts.zero_value && pmts.zero_value <= len_res + 2) ||
		(pmts.value && pmts.value <= len_res + 2))
		return (ft_put_ptr_adr_whithout_flags(res, node));
	if (pmts.zero_value)
	{
		(*node)->str = ft_memset((*node)->str, 48, len_final);
		return (ft_form_case1(node, res, len_final));
	}
	if (pmts.value)
	{
		(*node)->str = ft_memset((*node)->str, 32, len_final);
		return (ft_form_case2(node, pmts, res, len_final));
	}
	return (NULL);
}

t_prts	*ft_type_p(va_list ap, t_pmts pmts)
{
	char	*itoa_res;
	t_prts				*node;
	long long	res;

	res = va_arg(ap, long long);
	itoa_res = ft_itoa_base_ll_ed(res, 16);
	pmts.plus = 0;
	pmts.space = 0;
	pmts.hash = 0;
	pmts.mod = 0;
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	return (ft_handle_p(pmts, &node, itoa_res));
}
