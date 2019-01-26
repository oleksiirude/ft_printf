/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/23 17:12:01 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_form_case1(t_prts **node, t_pmts *pmts, char *res, size_t lfin)
{
	size_t start;

	if (!pmts->prec && !pmts->prec_value)
		start = lfin - ft_strlen(res);
	else
		start = lfin - pmts->prec_value;
	while (start < lfin)
		(*node)->str[start++] = *(res)++;
	(*node)->len = lfin;
}

void	ft_form_case2(t_prts **node, t_pmts *pmts, char *res, size_t lfin)
{
	size_t start;
	size_t len;

	(*node)->len = lfin;
	if (pmts->prec_value < 0)
		return ;
	if (!pmts->prec && !pmts->prec_value)
	{
		len = pmts->minus ? ft_strlen(res) : pmts->value;
		start = pmts->minus ? 0 : lfin - ft_strlen(res);
		while (start < lfin && start < len)
			(*node)->str[start++] = *(res)++;
	}
	else
	{
		len = pmts->minus ? (size_t)pmts->prec_value : lfin;
		start = pmts->minus ? 0 : lfin - pmts->prec_value;
		while (start < lfin && start < len)
			(*node)->str[start++] = *(res)++;
	}
}

t_prts	*ft_handle_s(t_pmts *pmts, t_prts **node, char *res)
{
	size_t	len_res;
	size_t	len_final;

	len_res = ft_strlen(res);
	len_final = ft_getting_total_len_s(pmts, len_res);
	(*node)->str = (char*)malloc(len_final + 1);
	(*node)->len = len_final;
	(*node)->str[len_final] = 0;
	if (pmts->prec_value < 0)
		pmts->value = pmts->zero_value;
	if (pmts->prec_value &&  pmts->prec_value > 0 && pmts->prec_value > len_res)
		pmts->prec_value = (int)len_res;
	if (pmts->value && pmts->value < len_res)
		pmts->value = (int)len_res;
//	printf("minus-> %2d\n", pmts->minus);
//	printf("plus-> %3d\n", pmts->plus);
//	printf("space-> %2d\n", pmts->space);
//	printf("hash-> %3d\n", pmts->hash);
//	printf("value-> %2d\n", pmts->value);
//	printf("zero-> %3d\n", pmts->zero);
//	printf("zero_v-> %d\n", pmts->zero_value);
//	printf("prec-> %3d\n", pmts->prec);
//	printf("prec_v-> %d\n", pmts->prec_value);
//	printf("mod-> %4d\n", pmts->mod);
//	printf("type-> %3c\n", pmts->type);
	if (pmts->zero_value)
	{
		(*node)->str = ft_memset((*node)->str, 48, len_final);
		ft_form_case1(node, pmts, res, len_final);
		return (*node);
	}
	if (pmts->prec_value || pmts->minus || pmts->value || pmts->prec_value < 0)
	{
		(*node)->str = ft_memset((*node)->str, 32, len_final);
		ft_form_case2(node, pmts, res, len_final);
		return (*node);
	}
	return (*node);
}

t_prts	*ft_rec_given_str(t_prts **node, char *res)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(res);
	(*node)->len = len;
	(*node)->str = (char*)malloc(len + 1);
	len = 0;
	while (res[i])
		(*node)->str[len++] = res[i++];
	(*node)->str[len] = 0;
	return (*node);
}

t_prts	*ft_type_s(va_list ap, t_pmts *pmts)
{
	char 	*res;
	t_prts	*node;

	res = va_arg(ap, char*);
	pmts->plus = 0;
	pmts->space = 0;
	pmts->hash = 0;
	pmts->mod = 0;
	if (pmts->zero && pmts->value)
	{
		pmts->zero_value = pmts->value;
		pmts->value = 0;
	}
	if (!pmts->zero_value && !pmts->value)
		pmts->minus = 0;
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (!res)
		return (ft_work_with_null(pmts, &node));
	else if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_str(&node, res));
	else
		return (ft_handle_s(pmts, &node, res));
}

//	printf("minus-> %2d\n", pmts->minus);
//	printf("plus-> %3d\n", pmts->plus);
//	printf("space-> %2d\n", pmts->space);
//	printf("hash-> %3d\n", pmts->hash);
//	printf("value-> %2d\n", pmts->value);
//	printf("zero-> %3d\n", pmts->zero);
//	printf("zero_v-> %d\n", pmts->zero_value);
//	printf("prec-> %3d\n", pmts->prec);
//	printf("prec_v-> %d\n", pmts->prec_value);
//	printf("mod-> %4d\n", pmts->mod);
//	printf("type-> %3c\n", pmts->type);