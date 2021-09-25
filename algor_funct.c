#include "push_swap.h"

t_stack	*reset_index(t_stack *stack_a)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_a;
	i = 0;
	while (tmp != NULL)
	{
		tmp -> pos = i;
		tmp = tmp->next;
		i++;
	}
	return (stack_a);
}

int	depth(int base)
{
	int	depth;

	depth = 1;
	while (base / 10 > 0)
	{
		depth++;
		base = base / 10;
	}
	return (depth);
}

int	the_stack_is_sorted(t_stack *stack)
{
	int	len_of_the_stack;

	len_of_the_stack = detect_len_of_stack(stack);
	while (len_of_the_stack - 1 > 0)
	{
		if (((find_on_index(stack, len_of_the_stack - 1))->num) < \
		((find_on_index(stack, len_of_the_stack - 2))->num))
			return (0);
		len_of_the_stack--;
	}
	return (1);
}

void	if_len_two_or_three(int len_of_the_stack, t_stack *stack_a, \
t_stack *stack_b)
{
	int	min;
	int	max;

	max = find_maximum_value(stack_a);
	min = find_minimum(stack_a);
	if (len_of_the_stack == 2)
	{
		if (((find_on_index(stack_a, 1))->num) < \
		((find_on_index(stack_a, 0))->num))
		{
			perform_command(&stack_a, &stack_b, "ra", 1);
			stack_a = reset_index(stack_a);
		}
	}
	if (len_of_the_stack == 3)
	{
		if (((find_on_index(stack_a, 0))->num) == max)
			perform_command(&stack_a, &stack_b, "ra", 1);
		if (((find_on_index(stack_a, 1))->num) == max)
			perform_command(&stack_a, &stack_b, "rra", 1);
		if (((find_on_index(stack_a, 0))->num) > \
		((find_on_index(stack_a, 1))->num))
			perform_command(&stack_a, &stack_b, "sa", 1);
	}
}

void	if_len_four_or_five(int len_of_the_stack, t_stack *stack_a, \
	t_stack *stack_b)
{
	int	min;
	int	max;

	max = find_maximum_value(stack_a);
	min = find_minimum(stack_a);
	if (len_of_the_stack == 4 || len_of_the_stack == 5)
	{
		while (detect_len_of_stack(stack_b) < 2)
		{
			if (stack_a->num == max || stack_a->num == min)
				perform_command(&stack_a, &stack_b, "pb", 1);
			else
				perform_command(&stack_a, &stack_b, "ra", 1);
		}
		stack_a = sort_little_stack(stack_a, stack_b, len_of_the_stack - 2);
		perform_command(&stack_a, &stack_b, "pa", 1);
		perform_command(&stack_a, &stack_b, "pa", 1);
		if (stack_a->num == find_maximum_value(stack_a))
			perform_command(&stack_a, &stack_b, "ra", 1);
		else
		{
			perform_command(&stack_a, &stack_b, "sa", 1);
			perform_command(&stack_a, &stack_b, "ra", 1);
		}
	}
}
