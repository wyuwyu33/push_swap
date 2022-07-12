/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:51:15 by wyu               #+#    #+#             */
/*   Updated: 2022/07/13 00:04:03 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_pa(t_frame *frame)
{
	t_dll *dll;

	if (!frame)
		return ;
	dll = ft_remove_front(frame->deq_b);
	ft_add_front(frame->deq_a, dll);
	write(1, "pa\n", 3);
}

void ft_pb(t_frame *frame)
{
	t_dll *dll;

	if (!frame)
		return ;
	dll = ft_remove_front(frame->deq_a);
	ft_add_front(frame->deq_b, dll);
	write(1, "pb\n", 3);
}