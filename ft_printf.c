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

int		ft_printf(const char *format, ...)
{
	size_t	result;
	va_list ap;
	t_final *final;

	va_start(ap, format);
	final = ft_main_funct(ap, (char*)format);
	write(1, final->str, final->len);
	write(1, "\n", 1);
	result = final->len;
	free(final->str);
	free(final);
	va_end(ap);
	return ((int)result);
}

int		ft_fprintf(int fd, const char *format, ...)
{
	size_t	result;
	va_list ap;
	t_final *final;

	va_start(ap, format);
	final = ft_main_funct(ap, (char*)format);
	if (fd < 0 || write(fd, 0, 0) < 0)
	{
		free(final->str);
		free(final);
		return (-1);
	}
	write(fd, final->str, final->len);
	result = final->len;
	free(final->str);
	free(final);
	va_end(ap);
	return ((int)result);
}
