/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:49:38 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 20:11:40 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_frame *ft_get_frame(t_arr *arr)
{
	t_frame *new_frame;

	new_frame = (t_frame *)malloc(sizeof(t_frame));
	if (!new_frame)
		ft_allocation_error("ft_get_frame");
	new_frame->deq_a = ft_get_deq_a(arr);
	new_frame->deq_b = ft_get_deq_b();
	return (new_frame);
}