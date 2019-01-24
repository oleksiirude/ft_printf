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

size_t	ft_count_total_strlen(t_pmts *pmts, char *res)
{
 	size_t	sum;

 	sum = 0;
 	if (pmts->prec && pmts->prec_value)
		sum += pmts->prec_value;
	if (pmts->value || pmts->zero_value)
 	{
 		if (ft_strlen(res) < pmts->prec_value)
 			pmts->prec_value = (int)ft_strlen(res);
		if (pmts->value)
 			sum += pmts->value - pmts->prec_value;
		else
			sum += pmts->zero_value - pmts->prec_value;
 	}
	return (sum);
}

t_prts	*ft_handle_s(t_pmts *pmts, t_prts **node, char *res)
{
	int 	stop;
	int		tmp;
	size_t	len;
	int	len_res;

	len_res = (int)ft_strlen(res);
	len = ft_strlen(res);
	if ((size_t)pmts->prec_value > len)
		pmts->prec_value = (int)len;
	len = ft_count_total_strlen(pmts, res);
	(*node)->str = (char*)malloc(len + 1);
	if (pmts->minus || pmts->value)
		(*node)->str = ft_memset((*node)->str, 32, len);
	if (pmts->zero && pmts->zero_value)
		(*node)->str = ft_memset((*node)->str, 48, len);
	if (pmts->value && !pmts->prec_value)
	{
		if (len_res > pmts->value)
			pmts->value = len_res;
		if (pmts->minus)
		{
			tmp = 0;
			stop = len_res;
		}
		else
		{
			tmp = pmts->value - len_res;
			stop = (int)len;
		}
		while (tmp < stop)
			(*node)->str[tmp++] = *(res++);
		printf("[%s]\n", (*node)->str);
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
		while (tmp < stop)
			(*node)->str[tmp++] = *(res++);
		printf("[%s]\n", (*node)->str);
	}
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
	return (*node);
}

t_prts	*ft_type_s(va_list ap, t_pmts *pmts)
{
	char 	*res;
	t_prts	*node;

	printf("minus-> %2d\n", pmts->minus);
	printf("plus-> %3d\n", pmts->plus);
	printf("space-> %2d\n", pmts->space);
	printf("hash-> %3d\n", pmts->hash);
	printf("value-> %2d\n", pmts->value);
	printf("zero-> %3d\n", pmts->zero);
	printf("zero_v-> %d\n", pmts->zero_value);
	printf("prec-> %3d\n", pmts->prec);
	printf("prec_v-> %d\n", pmts->prec_value);
	printf("mod-> %4d\n", pmts->mod);
	printf("type-> %3c\n\n", pmts->type);
	res = va_arg(ap, char*);
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_str(&node, res));
	else
		return (ft_handle_s(pmts, &node, res));
	return (NULL);
}

/*printf("minus-> %2d\n", pmts->minus);
printf("plus-> %3d\n", pmts->plus);
printf("space-> %2d\n", pmts->space);
printf("hash-> %3d\n", pmts->hash);
printf("value-> %2d\n", pmts->value);
printf("zero-> %3d\n", pmts->zero);
printf("zero_v-> %d\n", pmts->zero_value);
printf("prec-> %3d\n", pmts->prec);
printf("prec_v-> %d\n", pmts->prec_value);
printf("mod-> %4d\n", pmts->mod);
printf("type-> %3c\n", pmts->type);*/

/*len = ft_strlen(res);
 	if (pmts->prec && pmts->prec_value)
 	{
 		if ((size_t)pmts->prec_value > len)
 			pmts->prec_value = (int)len;
 		temp = (char*)malloc((size_t)pmts->prec_value);
 		while (++i < pmts->prec_value)
 			temp[i] = res[i];
		temp[i] = 0;
 	}
	if (pmts->prec && pmts->prec_value && pmts->zero_value)
	{
		pmts->zero_value -= pmts->prec_value;
		temp2 = (char*)malloc((size_t)pmts->prec_value + 1);
		temp2[pmts->prec_value] = 0;
		temp2 = ft_memset(temp2, 48, (size_t)pmts->zero_value);
		temp2[pmts->zero_value] = 0;
		temp2 = ft_strjoin(temp2, temp);
	}
	if (pmts->prec && pmts->prec_value && pmts->minus && pmts->value)
	{
		pmts->value -= pmts->prec_value;
		temp2 = (char*)malloc((size_t)pmts->value + 1);
		temp2[pmts->value] = 0;
		temp2 = ft_memset(temp2, 32, (size_t)pmts->value);
		temp2[pmts->value] = 0;
		temp2 = ft_strjoin(temp, temp2);
	}
	if (pmts->prec && pmts->prec_value && pmts->value)
	{
		if (!pmts->minus)
			pmts->value -= pmts->prec_value;
		else
			pmts->value -= 0;
		temp2 = (char*)malloc((size_t)pmts->value + 1);
		temp2[pmts->value] = 0;
		temp2 = ft_memset(temp2, 32, (size_t)pmts->value);
		temp2[pmts->value] = 0;
		if (!pmts->minus)
			temp2 = ft_strjoin(temp2, temp);
		else
			temp2 = ft_strjoin(temp, temp2);
	}*/