/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_steps_running.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 03:21:01 by wyu               #+#    #+#             */
/*   Updated: 2022/07/13 05:09:28 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_steps_running(t_frame *frame, t_steps steps)
{
	while (steps.a_rotate == steps.b_rotate &&\
			steps.a_step && steps.b_step)
	{
		if (steps.a_rotate == 1)
			ft_rr(frame);
		else
			ft_rrr(frame);
		steps.a_step--;
		steps.b_step--;
	}
	while (steps.a_step--)
	{
		if (steps.a_rotate == 1)
			ft_ra(frame);
		else
			ft_rra(frame);
	}
	while (steps.b_step--)
	{
		if (steps.b_rotate == 1)
			ft_rb(frame);
		else
			ft_rrb(frame);
	}
}