/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_record_str_f(char *str, long double res, size_t e)
{
	int		i;
	size_t	nb;

	i = 0;
	if (e > 19)
		ft_max(&res, &e);
	nb = res / ft_exp(10, e);
	str[i++] = nb + '0';
	e--;
	while ((long long)e >= 0)
	{
		nb = res / ft_exp(10, e);
		nb %= 10;
		str[i++] = nb + '0';
		e--;
	}
	return (str);
}

char	*ft_prt2(long double res, t_pmts pmts)
{
	size_t	tmp;
	char	*str;
	int		prec;

	if (pmts.prec && !pmts.prec_value)
		return (ft_strdup(""));
	if (res < 0.0l)
		res *= -1.0l;
	prec = pmts.prec_value ? pmts.prec_value : 6;
	tmp = (size_t)prec;
	str = ft_malloc_sz((size_t)prec);
	str = ft_memset(str, 48, (size_t)prec);
	while (prec--)
		res *= 10.0l;
	str = ft_record_str_f(str, res, tmp - 1);
	return (str);
}

char	*ft_prt1(long double res, t_pmts pmts)
{
	int			minus;
	char		*str;
	size_t		len;
	long double nb;

	len = 0;
	minus = 0;
	if (res < 0.0l)
	{
		minus = 1;
		res *= -1.0l;
	}
	nb = res;
	while (nb > 1.0l)
	{
		nb /= 10.0l;
		len++;
	}
	len ? 0 : len++;
	str = ft_malloc_sz(len + 1);
	str = ft_memset(str, 48, len + 1);
	str[len] = pmts.prec && !pmts.prec_value ? 0 : '.';
	str = ft_record_str_f(str, res, len - 1);
	minus ? str = ft_strjoin_free("-", str, 2) : 0;
	return (str);
}

t_prts	*ft_type_f(va_list ap, t_pmts pmts)
{
	long double	res;
	int			minus;
	char		*str;
	t_prts		*node;

	ft_handle_res_minus(&res, ap, (int)pmts.mod);
	if ((!pmts.prec && !pmts.prec_value) || (pmts.prec && pmts.prec_value))
		res = ft_round_off(res, &pmts);
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if ((str = ft_check_nan_and_inf(res)))
		;
	else
		str = ft_strjoin_free(ft_prt1(res, pmts), ft_prt2(res - (long long)res, pmts), 3);
	ft_set_d_flags(&pmts, &minus, str[0], ft_strlen(str));
	if (!ft_strcmp(str, "nan"))
		pmts.plus = 0;
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_data(&node, str));
	else if (!pmts.prec && !pmts.prec_value && pmts.zero)
		return (ft_handle_d_zv(pmts, &node, str, minus));
	else if (!pmts.prec_value)
	{
//		ft_handle_d_v_helper(&str, &pmts);
		return (ft_handle_d_v(pmts, &node, str, ft_strlen(str)));
	}
	else
		return (ft_handle_d_p(pmts, &node, str, minus));
}
