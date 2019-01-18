/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rec_type(char *fmt, t_pmts **params)
{

}

void	ft_rec_params(char **fmt, t_pmts **params)
{

}

t_pmts	*ft_main_parse(char **fmt)
{
	t_pmts	*params;

	params = ft_set_flags_to_zero();
	while (!ft_strchr("diouxXcspf%", **fmt) && **fmt)
	{
		if (ft_strchr("#+- .0123456789hlL", **fmt))
			ft_rec_params(fmt, &params);
		else
			return (NULL);
		(*fmt)++;
	}
	if (*fmt)
	{
		ft_rec_type(*fmt, &params);
		return (params);
	}
	return (NULL);
}

t_prts	*ft_processing(va_list ap, char **fmt)
{
	t_prts *node;
	t_pmts *params;

	if ((params = ft_main_parse(fmt)))
		return (ft_valid_str_formation(ap, params));
	else
		return (ft_invalid_str_formation(fmt));
}