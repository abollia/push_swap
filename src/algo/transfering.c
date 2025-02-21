/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfering.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:10:25 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:33:45 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static t_node	*get_prio(t_node *head)
{
	while (head)
	{
		if (head->prio == 1)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	ps_align(t_node **stack, t_node *prio, char toalign)
{
	if (!stack || !*stack || !prio)
		return ;
	while (*stack != prio)
	{
		if (toalign == 'a')
		{
			if (prio->abovemedian)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (toalign == 'b')
		{
			if (prio->abovemedian)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

void	ps_atob(t_node **b, t_node **a)
{
	t_node	*prio;
	t_ops	ops;

	prio = get_prio(*a);
	if (!prio)
		return ;
	if (!prio->target)
		return (ps_align(a, prio, 'a'), push_b(b, a));
	ops = count_ops(*a, *b, prio, prio->target);
	while (ops.rr-- > 0)
		rotate_rotate(a, b);
	while (ops.rrr-- > 0)
		reverse_rotate_rotate(a, b);
	while (ops.ra-- > 0)
		rotate_a(a);
	while (ops.rb-- > 0)
		rotate_b(b);
	while (ops.rra-- > 0)
		reverse_rotate_a(a);
	while (ops.rrb-- > 0)
		reverse_rotate_b(b);
	push_b(b, a);
}

void	ps_btoa(t_node **a, t_node **b)
{
	t_node	*prio;
	t_ops	ops;

	prio = get_prio(*b);
	if (!prio)
		return ;
	if (!prio->target)
		return (ps_align(b, prio, 'b'), push_a(a, b));
	ops = count_ops(*a, *b, prio->target, prio);
	while (ops.rr-- > 0)
		rotate_rotate(a, b);
	while (ops.rrr-- > 0)
		reverse_rotate_rotate(a, b);
	while (ops.ra-- > 0)
		rotate_a(a);
	while (ops.rb-- > 0)
		rotate_b(b);
	while (ops.rra-- > 0)
		reverse_rotate_a(a);
	while (ops.rrb-- > 0)
		reverse_rotate_b(b);
	push_a(a, b);
}
