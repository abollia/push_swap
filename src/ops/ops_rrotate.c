/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:18:56 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 12:50:58 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ps_reverse_rotate(t_node **head)
{
	t_node	*torotate;
	t_node	*newtail;

	if (!head || !*head || ps_lstsize(*head) == 1 || !(*head)->next)
		return ;
	torotate = ps_findlast(*head);
	newtail = torotate->prev;
	newtail->next = NULL;
	torotate->prev = NULL;
	torotate->next = *head;
	(*head)->prev = torotate;
	*head = torotate;
}

void	reverse_rotate_a(t_node **a)
{
	ps_reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_node **b)
{
	ps_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_rotate(t_node **a, t_node **b)
{
	ps_reverse_rotate(a);
	ps_reverse_rotate(b);
	ft_printf("rrr\n");
}
