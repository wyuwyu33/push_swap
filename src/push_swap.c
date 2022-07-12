/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:36:35 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 20:20:59 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_arg *arg;
	t_arr *arr;
	t_frame *frame;

	arg = ft_argv_split(argc, argv);
	ft_arg_errorcheck(arg);
	arr = ft_get_arr(arg);
	ft_clear_arg(arg);
	ft_arg_dupcheck(arr);
	frame = ft_get_frame(arr);
	if (ft_arr_sortcheck(arr))
	{
		
	}
	
	return (0);
}