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
#define FMT "[%p]", 'z'

int main(void)
{
    int res, res1;

    //res = ft_printf(FMT);
    res1 = printf(FMT);
    printf("\noriginal[%d]\n", res1 - 2);
	//system("leaks ft_printf");
	return (0);
}

//	printf("minus-> %2d\n", pmts->minus);
//	printf("plus-> %3d\n", pmts->plus);
//	printf("space-> %2d\n", pmts->space);
//	printf("hash-> %3d\n", pmts->hash);
//	printf("value-> %2d\n", pmts->value);
//	printf("zero-> %3d\n", pmts->zero);
//	printf("zero_v-> %d\n", pmts->zero_value);
//	printf("prec-> %3d\n", pmts->prec);
//	printf("prec_v-> %d\n", pmts->prec_value);
//	printf("mod-> %4d\n", pmts->mod);
//	printf("type-> %3c\n", pmts->type);