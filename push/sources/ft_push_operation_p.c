/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operation_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:36:25 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 15:28:42 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_pa(t_stack *stack)
{
	t_dish	*buf;

	if (stack->b)
	{
		buf = stack->b->next;
		stack->b->next = stack->a;
		stack->a = stack->b;
		stack->b = buf;
	}
	ft_dprintf(STDOUT_FILENO, "pa\n");
}

void	ft_push_pb(t_stack *stack)
{
	t_dish	*buf;

	if (stack->a)
	{
		buf = stack->a->next;
		stack->a->next = stack->b;
		stack->b = stack->a;
		stack->a = buf;
	}
	ft_dprintf(STDOUT_FILENO, "pb\n");
}
