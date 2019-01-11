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

char *ft_basic_work(va_list ap, char *fmt)
{
	char	*str;
	size_t	i;
	size_t 	start;

	i = 0;
	start = 0;
	while (fmt[i])
	{
		if (fmt[i] == PERC)
		{

		}
		else
			i++;
	}
	if (!fmt[i])
		str = ft_strsub(fmt, 0, i);
	return (str);
}

int	ft_printf(const char *format, ...)
{
	va_list arg;
	size_t	len;
	char 	*str;

	str = NULL;
	va_start(arg, format);
	str = ft_basic_work(arg, (char*)format);
	len = ft_strlen(str);
	if (len)
		write(1, str, len);
	free(str);
	va_end(arg);
	return (len);
}