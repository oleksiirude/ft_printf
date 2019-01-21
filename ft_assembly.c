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

void	ft_clean_node_and_go_next(t_prts **start)
{
	free((*start)->str);
	free(*start);
	*start = (*start)->next;
}

size_t	ft_len_sum(t_prts *start, size_t *len)
{
	size_t sum;

	sum = 0;
	while (start)
	{
		sum += start->len;
		start = start->next;
	}
	*len = sum;
	return (sum);
}

t_final	*ft_assembly(t_prts *start)
{
	size_t	i;
	t_final	*result;
	char	*zero_elem;

	i = 0;
	result = (t_final*)malloc(sizeof(t_final));
	result->str = (char*)malloc((ft_len_sum(start, &result->len) + 1));
	zero_elem = result->str;
	while (start)
	{
		if (start->sz == YES)
		{
			*result->str++ = start->str[0];
			ft_clean_node_and_go_next(&start);
		}
		while (start->str[i])
			*result->str++ = start->str[i++];
		ft_clean_node_and_go_next(&start);
		i = 0;
	}
	result->str = zero_elem;
	return (result);
}
