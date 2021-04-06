/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/06 11:26:02 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_check_duplicates(int nb, t_dish *a)
{
	t_dish	*buf;

	buf = a;
	while (buf)
	{
		if (buf->value == nb)
			return (FAILURE);
		buf = buf->next;
	}
	return (SUCCESS);
}

int	ft_check_check_arg(char **argv)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (((argv[i][0] > '9') || (argv[i][0] < '0')) && (argv[i][0] != '-'))
			return (FAILURE);
		while (argv[i][++j])
		{
			if ((argv[i][j] > '9') || (argv[i][j] < '0'))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	ssize_t		i;
	t_stack		*stack;
	t_commands	*command;
	t_list		*mem;
	int			return_value;
	int			nb;

	if (argc < 2)
		exit(ft_kema_error(NO_LIST, &mem, &free, PRINT));
	if (ft_check_check_arg(argv) != SUCCESS)
		exit(ft_kema_error(INVALID_LIST, &mem, &free, PRINT));
	stack = kemalloc_exit(&mem, 1, sizeof(t_stack), PRINT);
	i = 0;
	stack->a = NULL;
	stack->b = NULL;
	while (++i < argc)
	{
		nb = ft_atoi(argv[i]);
		if ((nb == 0) && (argv[i][0] != '0'))
			exit(ft_kema_error(INVALID_LIST, &mem, &free, PRINT));
		if (ft_check_check_duplicates(nb, stack->a) != SUCCESS)
			exit(ft_kema_error(DUPLICATE, &mem, &free, PRINT));
		ft_check_lstadd_back(&stack->a, ft_check_lstnew(mem, nb));
	}
	command = NULL;
	command = ft_check_get_commands(mem, command);
	return_value = ft_check_order(mem, stack, command);
	ft_dprintf(STDOUT_FILENO, "stack a:\n");
	ft_check_print_stack(stack->a);
	ft_dprintf(STDOUT_FILENO, "stack b:\n");
	ft_check_print_stack(stack->b);
	exit(ft_kema_error(return_value, &mem, &free, PRINT));
}
