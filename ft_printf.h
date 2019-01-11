/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/08 17:52:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h> // MUST DELETE!!!

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./libft/libft.h"

#define PERC '%'

typedef struct		s_str
{
	char			*str;
	int				n;
	struct s_str	*next;

}					t_str;

typedef struct		s_stuff
{
	int				minus;
	int				plus;
	int				space;
	int				value;
	int				zero;
	int				value_zero;
	int				precision;
	int				value_precision;
	int 			mod;
	int 			type;
}					t_stuff;

char				*c_type(va_list ap);
char				*s_type(va_list ap);
char				*p_type(va_list ap);
char				*d_type(va_list ap, int t);
char				*u_type(va_list ap, int t);
char				*o_type(va_list ap, int t);
char				*f_type(va_list ap, int t);
char				*x_type(va_list ap, int t, int reg);
int					ft_printf(const char *format, ...);
size_t				ft_easy_str(char *fmt);

#endif