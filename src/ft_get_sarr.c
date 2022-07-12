/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:14:34 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 19:36:32 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
void ft_merge_sarr(int *val, int *tmp, int left, int mid, int right)
{
	int ldx;
	int rdx;
	int tdx;

	ldx = left;
	rdx = mid + 1;
	tdx = left;

	while (ldx <= mid && rdx <= right)
	{
		if (val[ldx] <= val[rdx])
			tmp[tdx++] = val[ldx++];
		else
			tmp[tdx++] = val[rdx++];
	}
	while (ldx <= mid)
		tmp[tdx++] = val[ldx++];
	while (rdx <= right)
		tmp[tdx++] = val[rdx++];
	ft_memcpy(val + left, tmp + left, sizeof(int) * (right - left + 1));
}

static
void ft_merge_sarr_rec(int *val, int *tmp, int left, int right)
{
	int mid;

	if (left == right)
		return ;
	mid = (left + right) / 2;
	ft_merge_sarr_rec(val, tmp, left, mid);
	ft_merge_sarr_rec(val, tmp, mid + 1, right);
	ft_merge_sarr(val, tmp, left, mid, right);
}

static
void ft_sort_sarr(t_arr *sarr)
{
	int *tmp;

	if (sarr->size < 2)
		return ;
	tmp = (int *)malloc(sizeof(int) * sarr->size);
	if (!tmp)
		ft_allocation_error("ft_mergesort_sarr");
	ft_merge_sarr_rec(sarr->val, tmp, 0, sarr->size - 1);
	free(tmp);
}

static
void ft_init_sarr(t_arr *sarr, t_arr *arr)
{
	int i;

	i = -1;
	while (++i < arr->size)
		sarr->val[i] = arr->val[i];
	sarr->size = arr->size;
}

t_arr *ft_get_sarr(t_arr *arr)
{
	t_arr *new_sarr;

	new_sarr = (t_arr *)malloc(sizeof(t_arr));
	if (!new_sarr)
		ft_allocation_error("ft_get_sarr");
	new_sarr->val = (int *)malloc(sizeof(int) * arr->size);
	if (!new_sarr)
		ft_allocation_error("ft_get_sarr");
	ft_init_sarr(new_sarr, arr);
	ft_sort_sarr(new_sarr);
	return (new_sarr);
}