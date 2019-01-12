/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/09 16:02:23 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_producer(va_list ap, char *fmt)
{
	size_t 		i;
	char		*print;
	t_prts		*lst;
	t_prts		*start;

	i = 0;
	lst = (t_prts*)malloc(sizeof(t_prts));
	lst->next = NULL;
	start = lst;
	while (fmt[i])
	{
		if (fmt[i] == PERC)
		{
			lst = ft_lst_filler(ap, lst, &fmt, (size_t)fmt + i);
			lst = lst->next;
		}
		i++;
	}
	print = ft_concat_pieces(start);
	return (print);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	size_t	len;
	char 	*print;

	va_start(ap, format);
	print = ft_producer(ap, (char*)format);
	len = ft_strlen(print);
	if (len)
		write(1, print, len);
	else
		write(1, print, 1);
	free(print);
	va_end(ap);
	return (len);
}