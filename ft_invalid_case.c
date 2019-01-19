/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_invalid_str_formation(char **fmt)
{
	size_t 	len;
	char	*tmp;
	t_prts	*node;

	len = 0;
	tmp = *fmt;
	while (*(*fmt) && *(*fmt) != PERC)
	{
		(*fmt)++;
		len++;
	}
	node = (t_prts*)malloc(sizeof(t_prts));
	node->str = (char*)malloc(len + 1);
	node->len = len;
	node->next = NULL;
	node->str[len + 1] = 0;
	len = 0;
	*fmt = tmp;
	while (*(*fmt) && *(*fmt) != PERC)
		node->str[len++] = *(*fmt)++;
	return (node);
}