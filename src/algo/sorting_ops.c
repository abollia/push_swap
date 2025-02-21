/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:45:57 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:33:01 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	assign_properties(t_node *head)
{
	int	i;
	int	med;

	i = 0;
	med = ps_lstsize(head) / 2;
	while (head)
	{
		head->index = i;
		if (head->index <= med)
			head->abovemedian = 1;
		else
			head->abovemedian = 0;
		i++;
		head = head->next;
	}
}

static void	assign_opscount(t_node *a, t_node *b, char toass)
{
	t_ops	ops;
	t_node	*stack;

	stack = NULL;
	if (toass == 'a')
		stack = a;
	else if (toass == 'b')
		stack = b;
	while (stack)
	{
		if (stack->target)
		{
			if (toass == 'a')
				ops = count_ops(a, b, stack, stack->target);
			else if (toass == 'b')
				ops = count_ops(a, b, stack->target, stack);
			stack->opscount = ops.total;
		}
		stack = stack->next;
	}
}

static void	reset_priority(t_node *head)
{
	while (head)
	{
		head->prio = 0;
		head = head->next;
	}
}

static void	assign_priority(t_node *head)
{
	int		lowest_opscount;
	t_node	*tmp;

	lowest_opscount = INT_MAX;
	tmp = NULL;
	reset_priority(head);
	while (head)
	{
		head->prio = 0;
		if (head->opscount < lowest_opscount)
		{
			lowest_opscount = head->opscount;
			tmp = head;
		}
		head = head->next;
	}
	if (tmp)
		tmp->prio = 1;
}

void	lstini(t_node *a, t_node *b, char toinit)
{
	assign_properties(a);
	assign_properties(b);
	if (toinit == 'a')
	{
		asstarto_a(a, b);
		assign_opscount(a, b, 'a');
		assign_priority(a);
	}
	else if (toinit == 'b')
	{
		asstarto_b(a, b);
		assign_opscount(a, b, 'b');
		assign_priority(b);
	}
}
