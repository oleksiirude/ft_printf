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

	prec = pmts.prec_value ? pmts.prec_value + 1 : 7;
	tmp = (size_t)prec;
	str = ft_malloc_sz((size_t)prec);
	str = ft_memset(str, 48, (size_t)prec);
	while (prec--)
		res *= 10.0l;
	str = ft_record_str_f(str, res, tmp - 1);
	return (str);
}

char	*ft_prt1(long double res)
{
	char		*str;
	size_t		len;
	long double nb;

	len = 0;
	nb = res;
	while (nb > 1.0l)
	{
		nb /= 10.0l;
		len++;
	}
	if (!len)
		len++;
	str = ft_malloc_sz(len + 1);
	str = ft_memset(str, 48, len + 1);
	str[len] = '.';
	str = ft_record_str_f(str, res, len - 1);
	return (str);
}

t_prts	*ft_type_f(va_list ap, t_pmts pmts)
{
	int			prec;
	int			minus;
	char		*str;
	t_prts		*node;
	long double	res;

	prec = pmts.prec_value ? pmts.prec_value : 6;
	ft_handle_res_minus(&res, ap, &minus, (int)pmts.mod);
	res = ft_round_off(res, prec);
	ft_set_f_flags(&pmts);
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	str = ft_strjoin_free(ft_prt1(res),
			ft_prt2(res - (long long)res, pmts), 3);
	if (minus)
		str = ft_strjoin_free("-", str, 2);
	node->str = str;
	node->len = ft_strlen(str) - 1;
	return (node);
}
