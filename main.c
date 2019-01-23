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

int main(void)
{
    int res, res1;

    res = ft_printf("%s\n", "asjdhnlajsd31233A");
    res1 = printf("%s\n", "asjdhnlajsdhasdlsajldjaskdjaks;djasjd;asjdiasjd[pasjdklasmkdksopv i23poi j23 u923u40 23u4u 2394 u230u4023u40u 234 2390 r[eipke wrk;lj srj 0923 0[u3290u4");
    printf("\nmy->%d\nor->%d", res, res1);
    //printf("\n%+20 010c", 'a');
	//system("leaks ft_printf");
	return (0);
}