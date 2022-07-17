/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:22:20 by wyu               #+#    #+#             */
/*   Updated: 2022/07/17 14:33:11 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
void	ft_emptyspace_check(char *s)
{
	int	i;
	int	s_len;

	i = -1;
	s_len = (int)ft_strlen(s);
	while (++i < s_len)
	{
		if (s[i] != ' ')
			return ;
	}
	ft_arg_error();
}

void	ft_argv_check(int argc, char **argv)
{
	int		i;
	char	*s_check;

	i = 0;
	while (++i < argc)
	{
		s_check = argv[i];
		ft_emptyspace_check(s_check);
	}
}
