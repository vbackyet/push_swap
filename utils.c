#include "push_swap.h"
#include "stdio.h"
#include	"get_next_line1/get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		++len;
	return (len);
}

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

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sa(stack_b);
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

void continue_perform_command(t_stack **stack_a, t_stack **stack_b, char *command, int flag)
{
	if (ft_strcmp(command, "rra") == 0)
		rra(stack_a);
	if (ft_strcmp(command, "rrb") == 0)
		rra(stack_b);
	if (ft_strcmp(command, "rrr") == 0)
	{		
		rra(stack_a);
		rra(stack_b);
	}
	if (ft_strcmp(command, "pb") == 0)
		pa(stack_a, stack_b);
	if (ft_strcmp(command, "pa") == 0)
		pa(stack_b, stack_a);
	if (flag)
	{
		write(1, command, ft_strlen(command));
		write(1, "\n", 1);
	}
}


void	perform_command(t_stack **stack_a, t_stack **stack_b, char *command, int flag)
{
	if (ft_strcmp(command, "ra") == 0)
		ra(stack_a);
	if (ft_strcmp(command, "rb") == 0)
		ra(stack_b);
	if (ft_strcmp(command, "sa") == 0)
		sa(stack_a);
	if (ft_strcmp(command, "sb") == 0)
		sa(stack_b);
	if (ft_strcmp(command, "ss") == 0)
		ss(stack_a, stack_b);
	if (ft_strcmp(command, "rr") == 0)
	{
		ra(stack_a);
		ra(stack_b);
	}
	else
		continue_perform_command(stack_a, stack_b, command, flag);
}

