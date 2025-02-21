/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:19:06 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:34:10 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ps_push(t_node **dst, t_node **src)
{
	t_node	*topush;

	if (!*src)
		return ;
	topush = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = topush;
		topush->next = NULL;
		topush->prev = NULL;
	}
	else
	{
		topush->next = *dst;
		topush->prev = NULL;
		(*dst)->prev = topush;
		*dst = topush;
	}
}

void	push_a(t_node **a, t_node **b)
{
	ps_push(a, b);
	ft_printf("pa\n");
}

void	push_b(t_node **b, t_node **a)
{
	ps_push(b, a);
	ft_printf("pb\n");
}
