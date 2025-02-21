/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:19:04 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:34:32 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ps_rotate(t_node **head)
{
	t_node	*torotate;
	t_node	*tail;

	if (!*head || !(*head)->next)
		return ;
	torotate = (*head)->next;
	tail = ps_findlast(*head);
	tail->next = *head;
	(*head)->prev = tail;
	(*head)->next = NULL;
	torotate->prev = NULL;
	*head = torotate;
}

void	rotate_a(t_node **a)
{
	ps_rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_node **b)
{
	ps_rotate(b);
	ft_printf("rb\n");
}

void	rotate_rotate(t_node **a, t_node **b)
{
	ps_rotate(a);
	ps_rotate(b);
	ft_printf("rr\n");
}
