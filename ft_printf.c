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

t_prts	*ft_rec_node(char **fmt, size_t len)
{
	size_t	i;
	t_prts	*node;

	i = 0;
	node = (t_prts*)malloc(sizeof(t_prts));
	node->str = (char*)malloc(len + 1);
	node->len = len;
	node->next = NULL;
	node->str[len + 1] = 0;
	while (len--)
		node->str[i++] = *(*fmt)++;
	node->str[i] = 0;
	return (node);
}

void	ft_rec_simple_str(char **fmt, t_prts **start, t_prts **node, int sign)
{
	if (sign)
	{
		*node = *start;
		while ((*node)->next)
			*node = (*node)->next;
		(*node)->next = ft_rec_node(fmt, (ft_check_len(*fmt)));
	}
	else
		*start = ft_rec_node(fmt, (ft_check_len(*fmt)));
}

t_final	*ft_main_funct(va_list ap, char *fmt)
{
	t_prts	*start;
	t_prts	*node;

	while (*fmt)
	{
		if ((ft_check_len(fmt)))
		{
			if (!start)
				ft_rec_simple_str(&fmt, &start, &node, 0);
			else
				ft_rec_simple_str(&fmt, &start, &node, 1);
		}
		else
		{
			fmt++;
			if (!start)
				start = ft_processing(ap, &fmt);
			else
			{
				ft_find_last_node(&start, &node);
				node->next = ft_processing(ap, &fmt);
			}
		}
	}
	return (ft_assembly(start));
}

int		ft_printf(const char *format, ...)
{
	size_t	result;
	va_list ap;
	t_final *final;

	va_start(ap, format);
	final = ft_main_funct(ap, (char*)format);
	printf("myprintf[%zu]\n", final->len -  2);
	write(1, final->str, final->len);
	write(1, "\n", 1);
	result = final->len;
	free(final->str);
	free(final);
	va_end(ap);
	return ((int)result);
}
