/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 05:35:30 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 02:48:52 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_allocation_error(char *func)
{
	write(2, "Allocation error in ", ft_strlen("Allocation error in "));
	write(2, func, ft_strlen(func));
	write(2, "\n", 1);
	exit(1);
}

void ft_arg_error()
{
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(1);
}
