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
# define LBIG -1
# define HH 1
# define H 2
# define L 3
# define LL 4

typedef struct		s_final
{
	char			*str;
	size_t			len;
}					t_final;

typedef struct		s_prts
{
	char			*str;
	size_t			len;
	struct s_prts	*next;
}					t_prts;

typedef struct		s_pmts
{
	size_t			minus;
	size_t			plus;
	size_t			space;
	size_t			hash;
	size_t			value;
	size_t			zero;
	size_t			zero_value;
	size_t			prec;
	int				prec_value;
	int				mod;
	char			type;
}					t_pmts;

t_prts				*ft_type_c(va_list ap, t_pmts pmts);
t_prts				*ft_type_s(va_list ap, t_pmts pmts);
t_prts				*ft_type_p(va_list ap, t_pmts pmts);
t_prts				*ft_type_d(va_list ap, t_pmts pmts);
t_prts				*ft_type_o(va_list ap, t_pmts pmts);
t_prts				*ft_type_u(va_list ap, t_pmts pmts);
t_prts				*ft_type_x(va_list ap, t_pmts pmts);
t_prts				*ft_type_f(va_list ap, int type);
int					ft_printf(const char *format, ...);
t_final				*ft_assembly(t_prts *start);
t_prts				*ft_processing(va_list ap, char **fmt);
void				ft_find_last_node(t_prts **start, t_prts **node);
t_pmts				ft_set_flags_to_zero(void);
t_prts				*ft_valid_str_form(va_list ap, t_pmts pmts);
t_prts				*ft_invalid_str_form(char **fmt, t_pmts pmts);
int					ft_atoi_modificated(char **str, int sign);
void				ft_rec_params(char **fmt, t_pmts **params);
size_t				ft_calc_flags_sum(t_pmts pmts);
size_t				ft_getting_total_len_s(t_pmts *pmts, size_t len);
size_t				ft_getting_total_len_p(t_pmts *pmts, size_t len);
t_prts				*ft_put_ptr_adr_whithout_flags(char *res, t_prts **node);
long long           ft_cast_given_mod(t_pmts pmts, long long res);
t_prts				*ft_rec_given_data(t_prts **node, char *res);
void				ft_set_d_flags(t_pmts *pmts, int *minus, char c, size_t len);

#endif
