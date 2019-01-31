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

void	ft_set_p_flags(t_pmts *pmts, size_t len)
{
	pmts->plus = 0;
	pmts->space = 0;
	pmts->hash = 0;
	pmts->mod = 0;
	if (pmts->prec && !pmts->prec_value)
		pmts->prec = 0;
	if (pmts->prec && pmts->prec_value > 0 && pmts->prec_value <= len)
	{
		pmts->prec = 0;
		pmts->prec_value = 0;
	}
	if (pmts->prec && pmts->prec_value < 0)
	{
		if (pmts->prec_value * -1 <= len + 2)
		{
			pmts->prec = 0;
			pmts->prec_value = 0;
		}
	}
}

t_prts	*ft_handle_p_zv(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res) + 2;
	if (pmts.zero_value < len)
	{
		res = ft_strjoin_free("0x", res, 2);
		return (ft_rec_given_data(node, res));
	}
	tmp = ft_malloc_sz(pmts.zero_value - len);
	tmp = ft_memset(tmp, 48, pmts.zero_value - len);
	res = ft_strjoin_free(tmp, res, 3);
	res = ft_strjoin_free("0x", res, 2);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_handle_p_v(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res) + 2;
	if (pmts.value < len)
	{
		res = ft_strjoin_free("0x", res, 2);
		return (ft_rec_given_data(node, res));
	}
	tmp = ft_malloc_sz(pmts.value - len);
	tmp = ft_memset(tmp, 32, pmts.value - len);
	res = ft_strjoin_free("0x", res, 2);
	res = pmts.minus ? ft_strjoin_free(res, tmp, 3)
			: ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

void	ft_modificate_str_2(char **str, size_t len, t_pmts *pmts, t_prts **node)
{
	char	*tmp;
	size_t	var;

	pmts->prec_value *= -1;
	if (pmts->prec_value > len + 2)
	{
		var = pmts->prec_value - len - 2;
		tmp = ft_malloc_sz(var);
		tmp = ft_memset(tmp, 32, var);
		*str = ft_strjoin_free(*str, tmp, 3);
		(*node)->len = ft_strlen(*str);
		pmts->prec = 0;
		pmts->prec_value = 0;
	}
	pmts->minus = 0;
	pmts->prec = 0;
	pmts->prec_value = 0;
}

void	ft_modificate_str_1(char **str, size_t len, t_pmts *pmts, t_prts **node)
{
	char	*tmp;
	size_t	var;

	var = pmts->prec_value - len;
	tmp = ft_malloc_sz(var);
	tmp = ft_memset(tmp, 48, var);
	*str = ft_strjoin_free(tmp, *str, 3);
	(*node)->len = ft_strlen(*str);
	pmts->prec = 0;
	pmts->prec_value = 0;
}

t_prts	*ft_type_p(va_list ap, t_pmts pmts)
{
	size_t 		len;
	char		*str;
	t_prts		*node;
	long long	res;

	res = va_arg(ap, long long);
	str = ft_itoa_base_ll_ed(res, 16);
	len = ft_strlen(str);
	ft_set_p_flags(&pmts, ft_strlen(str));
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (pmts.prec)
		if (pmts.zero_value)
		{
			pmts.value = pmts.zero_value;
			pmts.zero_value = 0;
			pmts.zero = 0;
		}
	if (pmts.prec_value > (int)len)
		ft_modificate_str_1(&str, len, &pmts, &node);
	else if (pmts.prec_value < 0)
	{
		pmts.value = (size_t)pmts.prec_value * -1;
		ft_modificate_str_2(&str, len, &pmts, &node);
	}
	if (!ft_calc_flags_sum(pmts))
	{
		if (!pmts.prec_value)
			str = ft_strjoin_free("0x", str, 2);
		return (ft_rec_given_data(&node, str));
	}
	else if (pmts.zero_value)
		return (ft_handle_p_zv(pmts, &node, str));
	else
		return (ft_handle_p_v(pmts, &node, str));
}
