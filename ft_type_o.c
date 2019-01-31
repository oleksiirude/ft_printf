/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:57:16 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/29 15:42:41 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_get_str_o_wtht_flgs(char *res, t_prts **node)
{
	(*node)->str = (char*)malloc(ft_strlen(res) + 3);
	(*node)->str = ft_strcpy((*node)->str, res);
	(*node)->len = ft_strlen(res);
	free(res);
	return (*node);
}

size_t	ft_getting_total_len_o(t_pmts *pmts, size_t len)
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
	else
		return (len);
}

void	ft_set_o_flags(t_pmts *pmts)
{
	pmts->plus = 0;
	pmts->space = 0;
	pmts->mod = 0;
	if (pmts->prec && !pmts->prec_value)
		pmts->prec = 0;
	if (pmts->prec && pmts->prec_value && pmts->prec_value > 0)
	{
		pmts->zero = 1;
		pmts->zero_value = (size_t)pmts->prec_value;
		pmts->prec = 0;
		pmts->prec_value = 0;
	}
	if (pmts->prec && pmts->prec_value < 0)
	{
		pmts->value = (size_t)pmts->prec_value * -1;
		pmts->minus = 1;
		pmts->prec = 0;
		pmts->prec_value = 0;
	}
}

t_prts	*ft_handle_o_zv(t_prts **node, char *res, size_t lfin)
{
	size_t zero;

	zero = lfin - ft_strlen(res);
	lfin = 0;
	while (res[lfin])
		(*node)->str[zero++] = res[lfin++];
	free(res);
	return (*node);
}

t_prts	*ft_handle_o_v(t_prts **node, t_pmts pmts, char *res, size_t lfin)
{
	char	*tmp;
	size_t	start;

	tmp = res;
	start = pmts.minus ? 0 : lfin - ft_strlen(res);
	while (*res)
		(*node)->str[start++] = *res++;
	free(tmp);
	return (*node);
}

t_prts	*ft_handle_o(t_pmts pmts, t_prts **node, char *res)
{
	size_t	len_res;
	size_t	len_final;

	if (!ft_calc_flags_sum(pmts))
		return (ft_get_str_o_wtht_flgs(res, node));
	len_res = ft_strlen(res);
	len_final = (ft_getting_total_len_o(&pmts, len_res));
	(*node)->str = (char*)malloc(len_final + 1);
	(*node)->len = len_final;
	if ((pmts.zero_value && pmts.zero_value <= len_res) ||
		(pmts.value && pmts.value <= len_res))
		return (ft_get_str_o_wtht_flgs(res, node));
	if (pmts.zero_value)
	{
		(*node)->str = ft_memset((*node)->str, 48, len_final);
		return (ft_handle_o_zv(node, res, len_final));
	}
	if (pmts.value)
	{
		(*node)->str = ft_memset((*node)->str, 32, len_final);
		return (ft_handle_o_v(node, pmts, res, len_final));
	}
	return (NULL);
}

t_prts	*ft_type_o(va_list ap, t_pmts pmts)
{
	char		*str;
	t_prts		*node;
	long long	res;

	res = va_arg(ap, long long);
	str = ft_itoa_base_ll_ed(res, 8);
	ft_set_o_flags(&pmts);
//	printf("minus-> %2zu\n", pmts.minus);
//printf("plus-> %3zu\n", pmts.plus);
//printf("space-> %2zu\n", pmts.space);
//printf("hash-> %3zu\n", pmts.hash);
//printf("value-> %2zu\n", pmts.value);
//printf("zero-> %3zu\n", pmts.zero);
//printf("zero_v-> %zu\n", pmts.zero_value);
//printf("prec-> %3zu\n", pmts.prec);
//printf("prec_v-> %d\n", pmts.prec_value);
//printf("mod-> %4zu\n", pmts.mod);
//printf("type-> %3c\n", pmts.type);
	if (pmts.hash && pmts.zero_value > ft_strlen(str))
		str = ft_strjoin_free("", str, 2);
	else if (pmts.hash && pmts.zero_value <= ft_strlen(str))
	{
		pmts.hash = 0;
		str = ft_strjoin_free("0", str, 2);
	}
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	return (ft_handle_o(pmts, &node, str));
}
