/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:18:31 by abollia           #+#    #+#             */
/*   Updated: 2025/04/15 11:42:58 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	int				abovemedian;
	int				opscount;
	int				prio;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}					t_node;

typedef struct s_ops
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_ops;

//ARGUMENTS
int		ps_argcnt(char **tab);
int		ps_getargs(char **args, char **av);

//PARSING
int		ps_args_parser(char **args);
int		is_nb_valid(long nb);
int		is_nb_dup(t_node *head, int nb);

//NODE OPS
void	ps_stackinit(void);
void	ps_free_stack(t_node **head);
int		appnode(t_node **head, int content);

//SORTING
void	ps_inisort(t_node **a, t_node **b);
void	ps_microsort(t_node **head);
void	ps_atob(t_node **b, t_node **a);
void	ps_btoa(t_node **a, t_node **b);

//TARGETING
void	asstarto_a(t_node *a, t_node *b);
void	asstarto_b(t_node *a, t_node *b);

//OPS COUNTING
t_ops	count_ops(t_node *a, t_node *b, t_node *target_a, t_node *target_b);

//OPS
void	swap_a(t_node **a);
void	swap_b(t_node **b);
void	swap_swap(t_node **a, t_node **b);

void	push_a(t_node **a, t_node **b);
void	push_b(t_node **b, t_node **a);

void	rotate_a(t_node **a);
void	rotate_b(t_node **b);
void	rotate_rotate(t_node **a, t_node **b);

void	reverse_rotate_a(t_node **a);
void	reverse_rotate_b(t_node **b);
void	reverse_rotate_rotate(t_node **a, t_node **b);

//SORTING UTILS
void	lstini(t_node *a, t_node *b, char toinit);
void	assign_properties(t_node *head);

//LISTS_UTILS
int		ps_issorted(t_node *head);
int		ps_lstsize(t_node *head);
t_node	*ps_findlast(t_node *head);
t_node	*ps_findmin(t_node *head);
t_node	*ps_findmax(t_node *head);

#endif