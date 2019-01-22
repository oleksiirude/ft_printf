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
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"

# define PERC '%'
# define H 1
# define HH 2
# define L 3
# define LL 4
# define LBIG 5

# define YES 1
# define NO 0

typedef struct		s_final
{
	char			*str;
	size_t			len;
}					t_final;

typedef struct		s_prts
{
	int				type_c_zero;
	char			*str;
	size_t			len;
	struct s_prts	*next;
}					t_prts;

typedef struct		s_pmts
{
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				value;
	int				zero;
	int				zero_value;
	int				prec;
	int				prec_value;
	int				mod;
	char			type;
}					t_pmts;

t_prts				*ft_type_c(va_list ap, t_pmts *pmts);
t_prts				*ft_type_s(va_list ap);
t_prts				*ft_type_p(va_list ap);
t_prts				*ft_type_d(va_list ap, int type);
t_prts				*ft_type_u(va_list ap, int type);
t_prts				*ft_type_o(va_list ap, int type);
t_prts				*ft_type_f(va_list ap, int type);
t_prts				*ft_type_x(va_list ap, int type, int reg);
int					ft_printf(const char *format, ...);
t_final				*ft_assembly(t_prts *start);
t_prts				*ft_processing(va_list ap, char **fmt);
void				ft_find_last_node(t_prts **start, t_prts **node);
t_pmts				*ft_set_flags_to_zero(void);
t_prts				*ft_valid_str_form(va_list ap, t_pmts *pmts, char **fmt);
t_prts				*ft_invalid_str_form(char **fmt, t_pmts **pmts);
int					ft_atoi_light(char **str);
void				ft_rec_params(char **fmt, t_pmts **params);

#endif
