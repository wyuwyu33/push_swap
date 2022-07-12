/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:23:17 by wyu               #+#    #+#             */
/*   Updated: 2022/07/13 00:05:14 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_sa(t_frame *frame)
{
	t_dll *dll;

	if (!frame)
		return ;
	dll = frame->deq_a->header->next->next;
	dll->prev->next = dll->next;
	dll->next->prev = dll->prev;
	dll->prev = frame->deq_a->header;
	dll->next = frame->deq_a->header->next;
	dll->prev->next = dll;
	dll->next->prev = dll;
	write(1, "sa\n", 3);
}

void ft_sb(t_frame *frame)
{
	t_dll *dll;

	if (!frame)
		return ;
	dll = frame->deq_a->header->next->next;
	dll->prev->next = dll->next;
	dll->next->prev = dll->prev;
	dll->prev = frame->deq_a->header;
	dll->next = frame->deq_a->header->next;
	dll->prev->next = dll;
	dll->next->prev = dll;
	write(1, "sb\n", 3);
}
