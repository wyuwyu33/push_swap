/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:06:42 by wyu               #+#    #+#             */
/*   Updated: 2022/07/15 05:10:23 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_add_front(t_deq *deq, t_dll *dll)
{
	if (!deq || !dll)
		return ;
	deq->header->next->prev = dll;
	dll->next = deq->header->next;
	deq->header->next = dll;
	dll->prev = deq->header;
	deq->size++;
}

void	ft_add_rear(t_deq *deq, t_dll *dll)
{
	if (!deq || !dll)
		return ;
	deq->trailer->prev->next = dll;
	dll->prev = deq->trailer->prev;
	deq->trailer->prev = dll;
	dll->next = deq->trailer;
	deq->size++;
}

t_dll	*ft_remove_front(t_deq *deq)
{
	t_dll	*remove_dll;

	if (!deq || !deq->size)
		return (NULL);
	remove_dll = deq->header->next;
	remove_dll->prev->next = remove_dll->next;
	remove_dll->next->prev = remove_dll->prev;
	remove_dll->prev = NULL;
	remove_dll->next = NULL;
	deq->size--;
	return (remove_dll);
}

t_dll	*ft_remove_rear(t_deq *deq)
{
	t_dll	*remove_dll;

	if (!deq || !deq->size)
		return (NULL);
	remove_dll = deq->trailer->prev;
	remove_dll->prev->next = remove_dll->next;
	remove_dll->next->prev = remove_dll->prev;
	remove_dll->prev = NULL;
	remove_dll->next = NULL;
	deq->size--;
	return (remove_dll);
}
