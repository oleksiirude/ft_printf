/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assembly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/09 16:02:23 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t 	ft_len_sum(t_prts *start)
{
	size_t sum;

	sum = 0;
	while (start->next)
	{
		sum += start->len;
		start = start->next;
	}
	return (sum);
}

char 	*ft_assembly(t_prts *start)
{
	size_t	i;
	char	*final_str;

	i = 0;
	final_str = (char*)malloc(ft_len_sum(start));
	while (start->next)
	{
		while(start->str[i])
			*final_str++ = start->str[i++];
		start = start->next;
		i = 0;
	}
	return (final_str);
}