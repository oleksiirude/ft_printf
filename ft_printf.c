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
	t_pieces	*pieces;

	i = -1;
	while (fmt[++i])
	{
		if (*fmt == PERC)
		{
			if (i)
				pieces = ft_nodes_filler(pieces, )

		}
		i++;
	}
	print = ft_concat_pieces(list);
	return (print);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	size_t	len;
	char 	*print;

	print = NULL;
	va_start(ap, format);
	print = ft_producer(ap, (char*)format);
	len = ft_strlen(print);
	if (len)
		write(1, print, len);
	free(print);
	va_end(ap);
	return (len);
}