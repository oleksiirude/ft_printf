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
	int i;
	size_t sum;

	sum = 0;
	i = 0;
	//printf("%s\n%s\n", start->str, start->next->str);
	while (start)
	{
		sum += start->len;
		start = start->next;
		i++;
	}
	//printf("there is %i node(s) in list\n", i);
	return (sum);
}

char 	*ft_assembly(t_prts *start)
{
	size_t	j;
	char	*final_str;
	char 	*temp;

	j = 0;
	temp = (char*)malloc((ft_len_sum(start) + 1));
	final_str = temp;
	while (start)
	{
		while(start->str[j])
			*temp++ = start->str[j++];
		start = start->next;
		j = 0;
	}
	return (final_str);
}