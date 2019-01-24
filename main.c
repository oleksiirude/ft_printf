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
#define FMT "[%-222.22s]\n", "string"

int main(void)
{
    int res, res1;

    //res = ft_printf("%s\n", "String");
    //res1 = printf("%s\n", "String");
    //printf("\nmy->%d\nor->%d", res, res1);
	ft_printf(FMT);
    printf(FMT);
	//system("leaks ft_printf");
	return (0);
}