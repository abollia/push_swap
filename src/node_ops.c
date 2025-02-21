/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:58:34 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:31:19 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_free_stack(t_node **head)
{
	t_node	*current;
	t_node	*tmp;

	if (!*head)
		return ;
	current = *head;
	while (current)
	{
		tmp = current->next;
		current->data = 0;
		free(current);
		current = tmp;
	}
	*head = NULL;
}

static t_node	*nodenew(int content)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->data = content;
	newnode->index = 0;
	newnode->abovemedian = 0;
	newnode->opscount = 0;
	newnode->prio = 0;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->target = NULL;
	return (newnode);
}

int	appnode(t_node **head, int content)
{
	t_node	*newnode;
	t_node	*tail;

	newnode = nodenew(content);
	if (!newnode)
		return (0);
	if (*head == NULL)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		tail = ps_findlast(*head);
		newnode->prev = tail;
		newnode->next = NULL;
		tail->next = newnode;
		tail = newnode;
	}
	return (1);
}
