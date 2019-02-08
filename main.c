/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c   	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/09 16:02:23 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#define FMT "[%.12f]", -5783982.9999999999999

int main(void)
{
    int res, res1;

	res = ft_printf(FMT);
    res1 = printf(FMT);
//    ft_cprintf("REDCLThis sting has red color! GRNCLAnd this is green! FATLLOLSTPC\n");
//    ft_cprintf("+usage");
    printf("\nmy[%d]\nor[%d]\n", res, res1);
//	system("leaks ft_printf -q");
	return (0);
}

//printf("minus-> %2zu\n", pmts.minus);
//printf("plus-> %3zu\n", pmts.plus);
//printf("space-> %2zu\n", pmts.space);
//printf("hash-> %3zu\n", pmts.hash);
//printf("value-> %3zu\n", pmts.value);r
//printf("zero-> %3zu\n", pmts.zero);
//printf("zero_v-> %zu\n", pmts.zero_value);
//printf("prec-> %3zu\n", pmts.prec);
//printf("prec_v-> %d\n", pmts.prec_value);
//printf("mod-> %4zu\n", pmts.mod);
//printf("type-> %3c\n", pmts.type);

//18446744073709551615