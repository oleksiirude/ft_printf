/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_1st_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_case(char **fmt, t_pmts **params)
{
	(*params)->prec = 1;
	if ((*(*fmt) + 1) >= '0' || (*(*fmt) + 1) <= '9')
	{
		(*fmt)++;
		(*params)->prec_value = ft_atoi_light(fmt);
	}
}

void	ft_zero_case(char **fmt, t_pmts **params)
{
	(*params)->zero = 1;
	if ((*(*fmt) + 1) >= '0' || (*(*fmt) + 1) <= '9')
		(*params)->zero_value = ft_atoi_light(fmt);
}

void	ft_rec_params(char **fmt, t_pmts **params)
{
	if (**fmt == '.')
		ft_prec_case(fmt, params);
	else if (**fmt == '0')
		ft_zero_case(fmt, params);
	else if (**fmt == 'h')
		ft_h_or_hh_case(fmt, params);
	else if (**fmt == 'l')
		ft_l_or_ll_case(fmt, params);
	else if (**fmt >= '1' && **fmt <= '9')
		(*params)->value = ft_atoi_light(fmt);
	else if (**fmt == '#')
		(*params)->hash = 1;
	else if (**fmt == '+')
		(*params)->plus = 1;
	else if (**fmt == '-')
		(*params)->minus = 1;
	else if (**fmt == ' ')
		(*params)->space = 1;
	else if (**fmt == 'L')
		(*params)->mod = LBIG;
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
	if (**fmt == PERC)
	{
		params->type = PERC;
		return (params);
	}
	if (**fmt)
	{
		params->type = **fmt;
		return (params);
	}
	free(params);
	return (NULL);
}

t_prts	*ft_processing(va_list ap, char **fmt)
{
	t_pmts *params;

	if ((params = ft_main_parse(fmt)))
	{
		if (params->type == PERC)
			(*fmt)++;
		return (ft_valid_str_formation(ap, params));
	}
	free(params);
	return (ft_invalid_str_formation(fmt));
}
