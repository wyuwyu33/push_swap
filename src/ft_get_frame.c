/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:49:38 by wyu               #+#    #+#             */
/*   Updated: 2022/07/13 06:44:51 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_frame *ft_get_frame(t_arr *arr, t_arr *sarr)
{
	t_frame *new_frame;

	new_frame = (t_frame *)malloc(sizeof(t_frame));
	if (!new_frame)
		ft_allocation_error("ft_get_frame");
	new_frame->deq_a = ft_get_deq_a(arr);
	new_frame->deq_b = ft_get_deq_b();
	new_frame->min = sarr->val[0];
	new_frame->mid = sarr->val[(int)(sarr->size / 2)];
	new_frame->max = sarr->val[sarr->size - 1];
	new_frame->sec_max = sarr->val[sarr->size - 2];
	new_frame->sort = ft_arr_sortcheck(arr);
	return (new_frame);
}