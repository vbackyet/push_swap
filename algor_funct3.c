#include "push_swap.h"

int	check_the_argument(int argc, char **argv, int flag)
{
	int	i;

	i = argc - 1;
	while (i - flag >= 0)
	{
		if (is_not_digit(argv[i]))
			return (1);
		if (is_duplicate(argc, argv[i], argv, i))
			return (2);
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (3);
		i--;
	}
	return (0);
}

void	addelem(t_stack *stack, int number, int pos)
{
	t_stack	*temp;
	t_stack	*p;

	temp = (t_stack *)malloc(sizeof(t_stack));
	p = stack->next;
	stack->next = temp;
	temp->num = number;
	temp->pos = pos;
	temp->next = p;
	temp->prev = stack;
	temp->index = -1;
	if (p != NULL)
		p->prev = temp;
}

t_stack	*insert_into_stack(int argc, char **argv, int flag)
{
	t_stack	*stack;
	t_stack	*first_el_of_stack;
	int		i;
	int		pos_index;

	pos_index = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->chunk = 0;
	stack->num = atoi(argv[flag]);
	stack->pos = pos_index;
	stack->index = -1;
	stack->next = NULL;
	stack->prev = NULL;
	i = flag + 1;
	first_el_of_stack = stack;
	while (argc > i)
	{
		pos_index++;
		addelem(stack, atoi(argv[i]), pos_index);
		i++;
		stack = stack->next;
	}
	return (first_el_of_stack);
}

int	detect_len_of_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack-> next != NULL)
	{
		i++;
		stack = stack-> next;
	}
	return (i + 1);
}

t_stack	*find_on_index(t_stack *stack_a, int index)
{
	while (index != stack_a->pos || !stack_a)
		stack_a = stack_a -> next;
	return (stack_a);
}
