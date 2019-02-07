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

char 	*ft_get_1st_part(long double res, t_pmts pmts)
{
	size_t		len;
	long double nb;

	len = 0;
	printf("mod-> %4zu\n", pmts.mod);
	if (pmts.mod != LBIG)
		nb = (double)res;
	else
		nb = res;
	if (nb < 0.0l)
		len++;
	printf("res->%f\n", nb);
	while (nb > 1.0l)
	{
		write(1, "B\n", 2);
		nb /= 10.0l;
		len++;
	}
	printf("len->%zu\n", len);
	return (0);
}

t_prts	*ft_type_f(va_list ap, t_pmts pmts)
{
	char		*str;
	t_prts		*node;
	long double	res;

	res = va_arg(ap, long double); // или по даблу!!!!
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	str = ft_get_1st_part(res, pmts);
	return (NULL);
}
