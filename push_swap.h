#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"get_next_line1/get_next_line.h"
typedef struct	s_stack
{
	int				num;
	int				pos;
	int				index;
	int				chunk;
	int				base;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

int						detect_len_of_stack(t_stack *stack);
void					sa(t_stack **stack_a);
void					ra(t_stack **stack_a);
void					rra(t_stack **stack_a);
void					pa(t_stack **stack_a, t_stack **stack_b);
t_stack					*find_on_index(t_stack *stack_a, int index);
t_stack					*insert_into_stack(int argc, char **argv, int flag);
void					addelem(t_stack *stack, int number, int pos);
t_stack					*reset_index(t_stack *stack_a);
// void		listprint(t_stack *lst);
int						ft_strcmp(char *s1, char *s2);
void					perform_command(t_stack **stack_a, t_stack **stack_b, \
char *command, int flag);
int						the_stack_is_sorted(t_stack *stack);
t_stack					*sort_and_index(t_stack *stack);
int						check_the_argument(int argc, char **argv, int flag);
t_stack					*sort_the_stack(t_stack *stack_a, t_stack *stack_b);
t_stack					*make_base(t_stack *stack);
int						len_of_the_args(char **my_values);
t_stack					*sort_little_stack(t_stack *stack_a, t_stack *stack_b, \
int len_of_the_stack);
// char		**ft_split(char *str, char *charset);
char					**ft_split(char const *s, char c);
int						is_not_digit(char *my_arg);
// static int				ft_itoa_base_sneaky(int value, int base, int flag);
int						is_duplicate(int argc, char *el, char **spisok, \
	int el_of_my_ind);
signed long long int	ft_atoi(const char *str);
int						ft_power(int nb, int power);
void					if_len_four_or_five(int len_of_the_stack, \
t_stack *stack_a, \
	t_stack *stack_b);
void					if_len_two_or_three(int len_of_the_stack, \
t_stack *stack_a, \
t_stack *stack_b);

int						depth(int base);
int						find_maximum(t_stack *stack, int the_index, \
int maximum);
int						find_maximum_value(t_stack *stack);
t_stack					*find_on_value(t_stack *stack_a, int value);
t_stack					*sort_and_index(t_stack *stack);

int						find_minimum(t_stack *stack);
#endif