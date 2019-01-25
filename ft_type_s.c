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

t_prts	*ft_handle_s(t_pmts *pmts, t_prts **node, char *res)
{
	int 	stop;
	int		tmp;
	size_t	len_res;
	size_t	len_final;

	tmp = 0;
	len_res = ft_strlen(res);
	len_final = ft_getting_total_len_s(pmts, len_res);
	printf("len_final[%zu]\n", len_final);
	(*node)->str = (char*)malloc(len_final + 1);
	(*node)->str[len_final] = 0;
	if ((size_t)pmts->prec_value > len_final)
		pmts->prec_value = (int)len_final;
	if (pmts->value && pmts->value < ft_strlen(res))
		pmts->value = (int)ft_strlen(res);
	if (pmts->zero_value && pmts->zero_value < ft_strlen(res))
		pmts->zero_value = (int)ft_strlen(res);
	if (pmts->minus || pmts->value)
		(*node)->str = ft_memset((*node)->str, 32, len_final);
	if (pmts->zero_value)
		(*node)->str = ft_memset((*node)->str, 48, len_final);
	if (!pmts->value && pmts->prec_value)
		while (tmp < len_final)
			(*node)->str[tmp++] = *(res++);
	if (pmts->value && !pmts->prec_value)
	{
		if (pmts->minus)
		{
			tmp = 0;
			stop = len_res - 1;
		}
		else
		{
			tmp = pmts->value - len_res;
			stop = (int)len_final;
		}
		if (!pmts->prec)
			while (tmp <= stop)
				(*node)->str[tmp++] = *(res++);
	}
	if (pmts->value && pmts->prec_value)
	{
		if (pmts->minus)
		{
			tmp = 0;
			stop = pmts->prec_value;
		}
		else
		{
			tmp = pmts->value - pmts->prec_value;
			stop = pmts->value;
		}
		printf("1->value[%d]\n", pmts->value);
		printf("1->len_final[%zu]\n", len_final);
		printf("1->len_res[%d]\n", len_res);
		printf("1->stop[%d]\n", stop);
		printf("1->tmp[%d]\n", tmp);
		while (++tmp < stop)
			(*node)->str[tmp] = *(res++);
	}
	if (pmts->zero_value && !pmts->prec_value)
	{
		if (pmts->minus)
		{
			tmp = 0;
			stop = len_res - 1;
		}
		else
		{
			tmp = pmts->zero_value - len_res;
			stop = (int)len_final;
		}
		if (!pmts->prec)
			while (tmp <= stop)
				(*node)->str[tmp++] = *(res++);
	}
	if (pmts->zero_value && pmts->prec_value)
	{
		if (pmts->minus)
		{
			tmp = 0;
			stop = pmts->prec_value;
		}
		else
		{
			tmp = pmts->zero_value - pmts->prec_value;
			stop = pmts->zero_value;
		}
		printf("1->value[%d]\n", pmts->value);
		printf("1->len_final[%zu]\n", len_final);
		printf("1->len_res[%d]\n", len_res);
		printf("1->stop[%d]\n", stop);
		printf("1->tmp[%d]\n", tmp);
		while (++tmp < stop)
			(*node)->str[tmp] = *(res++);
	}
	printf("[%s]\n", (*node)->str);
	return (NULL);
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
	printf("simple[%s]\n", (*node)->str);
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
	if (!pmts->zero_value && !pmts->value)
		pmts->minus = 0;
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (!ft_calc_flags_sum(pmts))
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


//		printf("1->value[%d]\n", pmts->value);
//		printf("1->len_final[%zu]\n", len_final);
//		printf("1->len_res[%d]\n", len_res);
//		printf("1->stop[%d]\n", stop);
//		printf("1->tmp[%d]\n", tmp);