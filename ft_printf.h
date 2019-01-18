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
# define TYPES "diouxXcspf%"
# define FLAGS "#+- .0123456789hlL"
# define H 1
# define HH 2
# define L 3
# define LL 4
# define LBIG 5

typedef struct		s_prts
{
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

char				*ft_type_c(va_list ap);
char				*ft_type_s(va_list ap);
char				*ft_type_p(va_list ap);
char				*ft_type_d(va_list ap, int type);
char				*ft_type_u(va_list ap, int type);
char				*ft_type_o(va_list ap, int type);
char				*ft_type_f(va_list ap, int type);
char				*ft_type_x(va_list ap, int type, int reg);
int					ft_printf(const char *format, ...);
char				*ft_assembly(t_prts *start);
t_prts				*ft_processing(va_list ap, char **fmt);
void				ft_find_last_node(t_prts **start, t_prts **node);
t_pmts				*ft_set_flags_to_zero(void);
t_prts				*ft_valid_str_formation(va_list ap, t_pmts *params);
t_prts				*ft_invalid_str_formation(char **fmt);

#endif
