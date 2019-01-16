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

size_t	ft_check_len(char *fmt)
{
	size_t len;

	len = 0;
	if (*fmt == PERC)
		return (len);
	while (*fmt != PERC && *fmt)
	{
		len++;
		fmt++;
	}
	return (len);
}

t_prts	*ft_rec_node(char ***fmt, size_t len)
{
	size_t	i;
	t_prts *lst;

	i = 0;
	lst = (t_prts*)malloc(sizeof(t_prts));
	lst->str = (char*)malloc(len + 1);
	lst->len = len;
	lst->next = NULL;
	lst->str[len + 1] = 0;
	while (len--)
		lst->str[i++] = *(**fmt)++;
	return (lst);
}

void	ft_auxiliary_funct(char **fmt, t_prts **start, t_prts **node, int sign)
{
	if (sign)
	{
		*(node) = *(start);
		while ((*node)->next)
			*node = (*node)->next;
		(*node)->next = ft_rec_node(&fmt, (ft_check_len(*(fmt))));
	}
	else
		*(start) = ft_rec_node(&fmt, (ft_check_len(*(fmt))));
}

char	*ft_main_funct(va_list ap, char *fmt)
{
	t_prts	*start;
	t_prts	*node;

	while (*fmt)
	{
		if ((ft_check_len(fmt)))
		{
			if (!start)
				ft_auxiliary_funct(&fmt, &start, &node, 0);
			else
				ft_auxiliary_funct(&fmt, &start, &node, 1);
		}
		else
		{
			fmt++;
			if (!start)
				start = ft_processing(ap, &fmt);
			else
			{
				node = start;
				while (node->next)
					node = node->next;
				node->next = ft_processing(ap, &fmt);
			}
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
	print = ft_main_funct(ap, (char*)format);
	len = ft_strlen(print);
	write(1, print, len);
	free(print);
	va_end(ap);
	return ((int)len);
}

//ft_printf("123%456%789");