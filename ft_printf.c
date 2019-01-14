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

t_prts	*ft_processing(t_prts *lst, char **fmt)
{

}

t_prts	*ft_rec_simple_str(t_prts *lst, char **fmt, size_t len)
{
	size_t i;

	i = 0;
	if (!lst)
		lst = (t_prts*)malloc(sizeof(t_prts));
	lst->str = (char*)malloc(len + 1);
	lst->len = len;
	lst->next = NULL;
	lst->str[len + 1] = 0;
	while(len--)
		lst->str[i++] = *(*fmt)++;
	return (lst);
}

size_t	ft_check_len(char *fmt)
{
	size_t len;

	len = 0;
	if (*fmt == PERC)
		return (len);
	while (*fmt != PERC && *fmt)
	{
		fmt++;
		len++;
	}
	return (len);
}

char	*ft_mainfunct(va_list ap, char *fmt)
{
	size_t 	len;
	t_prts	*lst;
	t_prts	*start;

	if (!*fmt)
		return (0);
	lst = (t_prts*)malloc(sizeof(t_prts));
	start = lst;
	while (*fmt)
	{
		if ((len = ft_check_len(fmt)))
		{
			lst = ft_rec_simple_str(lst, &fmt, len);
			lst = lst->next;
		}
		else
		{
			fmt++;
			//lst = ft_processing(lst, (&fmt + 1));
		}
	}
	return (ft_assembly(start));
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	size_t	len;
	char 	*print;

	va_start(ap, format);
	print = ft_mainfunct(ap, (char*)format);
	len = ft_strlen(print);
	if (len)
		write(1, print, len);
	else
		write(1, print, 1);
	free(print);
	va_end(ap);
	return ((int)len);
}