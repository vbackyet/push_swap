#include "push_swap.h"

static int	ft_itoa_base_sneaky(int value, int base, int flag)
{
	char		*ref;
	static int	itog;
	int			ia;

	ref = "0123456789ABCDEF";
	itog = 0;
	if (flag)
	{
		itog = 0;
		flag = 0;
	}
	if (value < base)
	{
		ia = ref[value] - '0';
		itog = itog * 10 + ia ;
	}
	else if (value >= base)
	{
		ft_itoa_base_sneaky(value / base, base, 0);
		ft_itoa_base_sneaky(value % base, base, 0);
	}
	return (itog);
}

t_stack	*make_base(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack-> next != NULL)
	{
		stack->base = ft_itoa_base_sneaky(stack->index, 2, 1);
		stack = stack-> next;
	}
	stack->base = ft_itoa_base_sneaky(stack->index, 2, 1);
	return (tmp);
}

t_stack	*sort_little_stack(t_stack *stack_a, t_stack *stack_b, \
int len_of_the_stack)
{
	int	max;
	int	min;

	if (the_stack_is_sorted(stack_a) && (detect_len_of_stack(stack_b) == 0))
		return (stack_a);
	max = find_maximum_value(stack_a);
	min = find_minimum(stack_a);
	if_len_two_or_three(len_of_the_stack, stack_a, stack_b);
	if_len_four_or_five(len_of_the_stack, stack_a, stack_b);
	return (stack_a);
}

t_stack	*sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	big;
	int	i;
	int	length_of_the_stacky;

	i = 1;
	big = depth(find_on_value(stack_a, find_maximum_value(stack_a))->base);
	while (big)
	{
		length_of_the_stacky = detect_len_of_stack(stack_a);
		if (the_stack_is_sorted(stack_a) && (detect_len_of_stack(stack_b) == 0))
			return (stack_a);
		while (length_of_the_stacky > 0)
		{
			if ((((stack_a->base) / ft_power(10, i - 1)) % 10) == 0)
				perform_command(&stack_a, &stack_b, "pb", 1);
			else
				perform_command(&stack_a, &stack_b, "ra", 1);
			length_of_the_stacky--;
		}
		while (stack_b != NULL)
			perform_command(&stack_a, &stack_b, "pa", 1);
		big--;
		i++;
	}
	return (stack_a);
}

t_stack	*sort_the_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	len_of_the_stack;

	len_of_the_stack = detect_len_of_stack(stack_a);
	if (len_of_the_stack > 5)
		return (sort_big_stack(stack_a, stack_b));
	else
		return (sort_little_stack(stack_a, stack_b, len_of_the_stack));
}
