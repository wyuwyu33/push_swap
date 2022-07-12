/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_dupcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:14:26 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 20:17:11 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
void ft_dupcheck(t_arr *sarr)
{
	int i;

	i = -1;
	while (++i < sarr->size - 1)
	{
		if (sarr->val[i] == sarr->val[i + 1])
			ft_arg_error();
	}
}

void ft_arg_dupcheck(t_arr *arr)
{
	t_arr *sarr;

	sarr = ft_get_sarr(arr);
	ft_dupcheck(sarr);
	ft_clear_arr(sarr);
}