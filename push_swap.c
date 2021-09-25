#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int	is_not_digit(char *my_arg)
{
	int	i;

	i = 0;
	if (!(ft_strcmp(my_arg, "")))
		return (1);
	while (my_arg[i])
	{
		if ((my_arg[i] < '0' || my_arg[i] > '9') && (my_arg[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}

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

int	is_duplicate(int argc, char *el, char **spisok, int el_of_my_ind)
{
	int	i;

	i = argc - 1;
	while (i > el_of_my_ind)
	{
		if (!(ft_strcmp(spisok[i], el)))
			return (1);
		i--;
	}
	return (0);
}

signed long long int	ft_atoi(const char *str)
{
	int						i;
	signed long long int	nbr;
	int						negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}

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

t_stack *find_on_index(t_stack *stack_a, int index)
{
	while (index != stack_a->pos || !stack_a)
		stack_a = stack_a -> next;
	return (stack_a);
}

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

int	ft_power(int nb, int power)
{
	int	tmp;
	int	r;

	if (power < 0)
		return (0);
	tmp = 1;
	r = 1;
	while (tmp <= power)
	{
		r = r * nb;
		tmp++;
	}
	return (r);
}

int	the_stack_is_sorted(t_stack *stack)
{
	int	len_of_the_stack;

	len_of_the_stack = detect_len_of_stack(stack);
	while (len_of_the_stack - 1 > 0)
	{
		if (((find_on_index(stack, len_of_the_stack - 1))->num) < ((find_on_index(stack, len_of_the_stack - 2))->num))
			return (0);
		len_of_the_stack--;
	}
	return (1);
}

void	if_len_two_or_three(int len_of_the_stack, t_stack *stack_a, t_stack *stack_b)
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


void if_len_four_or_five(int len_of_the_stack, t_stack *stack_a, t_stack *stack_b)
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


t_stack	*sort_little_stack(t_stack *stack_a, t_stack *stack_b, int len_of_the_stack)
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

t_stack *sort_big_stack(t_stack *stack_a, t_stack *stack_b)
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

t_stack *sort_the_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	len_of_the_stack;

	len_of_the_stack = detect_len_of_stack(stack_a);
	if (len_of_the_stack > 5)
		return (sort_big_stack(stack_a, stack_b));
	else
		return (sort_little_stack(stack_a, stack_b, len_of_the_stack));
}

static int	quant_str(char const *s, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static int	lenn(char const *r, char c, int j)
{
	int	i;

	i = 0;
	while (r[j] != c && r[j] != '\0')
	{
		i++;
		j++;
	}
	return (i);
}

static void	frree(char **str, int i)
{
	while (i)
		free(str[i--]);
	free(str);
}

static char	**wr(char const *s, char **str, int kol_vo, char c)
{
	int	i;
	int	y;
	int	p;
	int	h;

	h = 0;
	i = 0;
	while (i < kol_vo)
	{
		while (s[h] == c)
			h++;
		y = lenn(s, c, h);
		str[i] = (char *)malloc(sizeof(char) * (y + 1));
		if (str[i] == NULL)
		{
			frree(str, i);
			return (NULL);
		}
		p = 0;
		while (p < y)
			str[i][p++] = s[h++];
		str[i++][p] = '\0';
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**main_k;
	int		quant;

	if (s == NULL)
		return (NULL);
	quant = quant_str(s, c);
	main_k = (char **)malloc(sizeof(char *) * (quant + 1));
	if (!main_k)
		return (NULL);
	wr(s, main_k, quant, c);
	return (main_k);
}

int len_of_the_args(char **my_values)
{
	int	i;

	i = 0;
	while (my_values[i])
		i++;
	return (i);
}
