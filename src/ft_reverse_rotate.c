/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:39:35 by wyu               #+#    #+#             */
/*   Updated: 2022/07/13 03:27:59 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_rra(t_frame *frame)
{
	t_dll *dll;

	if (!frame)
		return ;
	dll = ft_remove_rear(frame->deq_a);
	ft_add_front(frame->deq_a, dll);
	write(1, "rra\n", 4);
}

void ft_rrb(t_frame *frame)
{
	t_dll *dll;

	if (!frame)
		return ;
	dll = ft_remove_rear(frame->deq_b);
	ft_add_front(frame->deq_b, dll);
	write(1, "rrb\n", 4);
}

void ft_rrr(t_frame *frame)
{
	t_dll *dll_a;
	t_dll *dll_b;

	if (!frame)
		return ;
	dll_a = ft_remove_rear(frame->deq_a);
	ft_add_front(frame->deq_a, dll_a);
	dll_b = ft_remove_rear(frame->deq_b);
	ft_add_front(frame->deq_b, dll_b);
	write(1, "rrr\n", 4);
}