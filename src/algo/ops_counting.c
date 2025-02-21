/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_counting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:59:32 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:33:26 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	count_rots_a(t_ops *ops, t_node *a, t_node *target_a)
{
	int	a_size;

	a_size = ps_lstsize(a);
	if (target_a->abovemedian)
		ops->ra = target_a->index;
	else
		ops->rra = a_size - target_a->index;
}

static void	count_rots_b(t_ops *ops, t_node *b, t_node *target_b)
{
	int	b_size;

	b_size = ps_lstsize(b);
	if (target_b->abovemedian)
		ops->rb = target_b->index;
	else
		ops->rrb = b_size - target_b->index;
}

static void	count_rots_rots(t_ops *ops)
{
	if (ops->ra > 0 && ops->rb > 0)
	{
		if (ops->ra > ops->rb)
		{
			ops->rr = ops->rb;
			ops->ra -= ops->rb;
			ops->rb = 0;
		}
		else
		{
			ops->rr = ops->ra;
			ops->rb -= ops->ra;
			ops->ra = 0;
		}
	}
}

static void	count_rev_rots_rots(t_ops *ops)
{
	if (ops->rra > 0 && ops->rrb > 0)
	{
		if (ops->rra > ops->rrb)
		{
			ops->rrr = ops->rrb;
			ops->rra -= ops->rrb;
			ops->rrb = 0;
		}
		else
		{
			ops->rrr = ops->rra;
			ops->rrb -= ops->rra;
			ops->rra = 0;
		}
	}
}

t_ops	count_ops(t_node *a, t_node *b, t_node *target_a, t_node *target_b)
{
	t_ops	ops;

	ops.ra = 0;
	ops.rb = 0;
	ops.rr = 0;
	ops.rra = 0;
	ops.rrb = 0;
	ops.rrr = 0;
	count_rots_a(&ops, a, target_a);
	count_rots_b(&ops, b, target_b);
	count_rots_rots(&ops);
	count_rev_rots_rots(&ops);
	ops.total = ops.ra + ops.rb + ops.rr + ops.rra + ops.rrb + ops.rrr;
	return (ops);
}
