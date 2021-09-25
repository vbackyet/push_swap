#include "push_swap.h"

t_stack	*find_on_value(t_stack *stack_a, int value)
{
	while (value != stack_a->num || !stack_a)
		stack_a = stack_a -> next;
	return (stack_a);
}

int	find_maximum(t_stack *stack, int the_index, int maximum)
{
	t_stack	*begin;
	t_stack	*markable;

	begin = stack;
	while (stack->next != NULL)
	{
		if (stack->num >= maximum && stack->index == -1)
		{
			maximum = stack->num;
		}
		stack = stack-> next;
	}
	if (stack->num >= maximum && stack->index == -1)
	{
		maximum = stack->num;
	}
	markable = find_on_value(begin, maximum);
	markable->index = the_index;
	return (maximum);
}

int	find_maximum_value(t_stack *stack)
{
	int	maximum;

	maximum = stack->num;
	while (stack->next != NULL)
	{
		if (stack->num >= maximum)
		{
			maximum = stack->num;
		}
		stack = stack-> next;
	}
	if (stack->num >= maximum)
	{
		maximum = stack->num;
	}
	return (maximum);
}

int	find_minimum(t_stack *stack)
{
	int	initial_min;

	initial_min = stack->num;
	while (stack -> next != NULL)
	{
		if (stack->num < initial_min)
			initial_min = stack->num;
		stack = stack -> next;
	}
	if (stack->num < initial_min)
		initial_min = stack->num;
	return (initial_min);
}

t_stack	*sort_and_index(t_stack *stack)
{
	int	len;
	int	value;

	value = 0;
	value++;
	len = detect_len_of_stack(stack);
	while (len != 0)
	{
		value = find_maximum(stack, len - 1, find_minimum(stack));
		len--;
	}
	return (stack);
}
