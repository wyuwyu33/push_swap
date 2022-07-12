/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:36:35 by wyu               #+#    #+#             */
/*   Updated: 2022/07/13 03:57:36 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_arg *arg;
	t_arr *arr;
	t_arr *sarr;
	t_frame *frame;

	arg = ft_argv_split(argc, argv);
	ft_arg_errorcheck(arg);
	arr = ft_get_arr(arg);
	ft_clear_arg(arg);
	sarr = ft_get_sarr(arr);
	ft_arg_dupcheck(sarr);
	frame = ft_get_frame(arr, sarr);
	ft_clear_arr(arr);
	ft_clear_arr(sarr);
	if (!frame->sort)
		ft_start_sort(frame);
	ft_clear_frame(frame);
	return (0);
}