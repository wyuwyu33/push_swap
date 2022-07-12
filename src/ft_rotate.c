/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:58:32 by wyu               #+#    #+#             */
/*   Updated: 2022/07/13 03:26:54 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_ra(t_frame *frame)
{
	t_dll *dll;

	if (!frame)
		return;
	dll = ft_remove_front(frame->deq_a);
	ft_add_rear(frame->deq_a, dll);
	write(1, "ra\n", 3);
}

void ft_rb(t_frame *frame)
{
	t_dll *dll;

	if (!frame)
		return;
	dll = ft_remove_front(frame->deq_b);
	ft_add_rear(frame->deq_b, dll);
	write(1, "rb\n", 3);
}

void ft_rr(t_frame *frame)
{
	t_dll *dll_a;
	t_dll *dll_b;

	if (!frame)
		return;
	dll_a = ft_remove_front(frame->deq_a);
	ft_add_rear(frame->deq_a, dll_a);
	dll_b = ft_remove_front(frame->deq_b);
	ft_add_rear(frame->deq_b, dll_b);
	write(1, "rr\n", 3);
}