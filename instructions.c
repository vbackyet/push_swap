#include "push_swap.h"
#include	"get_next_line1/get_next_line.h"

void	sa(t_stack **stack_a)
{
	int		len;
	t_stack	*tmp;

	len = detect_len_of_stack(*stack_a);
	if (len > 1)
	{
		tmp = find_on_index(*stack_a, 1);
		(*stack_a)-> next = find_on_index(*stack_a, 2);
		(*stack_a)-> prev = tmp;
		tmp -> next = *stack_a;
		tmp -> prev = 0;
		*stack_a = (*stack_a)-> prev;
		*stack_a = reset_index(*stack_a);
	}
}

void	sub_pa(t_stack **stack_a)
{
	if ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = 0;
		*stack_a = reset_index(*stack_a);
	}
	else
		(*stack_a) = NULL;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int		len2;
	t_stack	*tmp;

	len2 = detect_len_of_stack(*stack_a);
	if (len2 > 0)
	{
		tmp = find_on_index(*stack_a, 0);
		sub_pa(stack_a);
		if ((*stack_b))
		{
			(*stack_b)->prev = tmp;
			tmp->next = *stack_b;
			*stack_b = (*stack_b)->prev;
			*stack_b = reset_index(*stack_b);
		}
		else
		{
			(*stack_b) = tmp;
			(*stack_b)->next = NULL;
			*stack_b = reset_index(*stack_b);
		}
	}
}

void	ra(t_stack **stack_a)
{
	t_stack	*head;
	int		len;

	len = detect_len_of_stack(*stack_a);
	if (len < 2)
		return ;
	head = (*stack_a);
	(*stack_a) = (*stack_a)-> next;
	(*stack_a)-> prev = 0;
	head -> prev = find_on_index(*stack_a, len - 1);
	head -> next = 0;
	find_on_index(*stack_a, len - 1)->next = head;
	*stack_a = reset_index(*stack_a);
}

void	rra(t_stack **stack_a)
{
	t_stack	*tail;
	int		len;

	len = detect_len_of_stack(*stack_a);
	if (len < 2)
		return ;
	tail = find_on_index(*stack_a, len - 1);
	find_on_index(*stack_a, len - 2)->next = 0;
	tail -> prev = 0;
	tail -> next = *stack_a;
	*stack_a = tail;
	*stack_a = reset_index(*stack_a);
}
