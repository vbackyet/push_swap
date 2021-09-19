
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// #include <stddef.h>
# include	"get_next_line/get_next_line.h"
typedef struct		s_stack
{
	int				num; //значение
	int				pos; // порядковый номер / индекс в стаке первоначальном
	int 			index; 
 	int				chunk; // ?????
	int 			base; // переведенный в двоичную сиситему
	struct s_stack	*next; // след значение
  struct s_stack	*prev; //предыд значение
}					t_stack;
# define FT_ULONG_MAX	((unsigned long)(~0L))
# define FT_LONG_MAX	((long)(FT_ULONG_MAX >> 1))

int detect_len_of_stack(t_stack *stack);
void sa(t_stack **stack_a);
void ss(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rra(t_stack **stack_a);
t_stack *find_on_index(t_stack *stack_a, int index);
t_stack *insert_into_stack(int argc, char **argv);
void addelem(t_stack *stack, int number, int pos);
t_stack *reset_index(t_stack *stack_a);
void listprint(t_stack *lst);
int     ft_strcmp(char *s1, char *s2);
void perform_command(t_stack **stack_a,t_stack **stack_b, char *command);
int the_stack_is_sorted(t_stack *stack);
t_stack *sort_and_index(t_stack *stack);
int check_the_argument(int argc, char **argv);
t_stack *sort_the_stack(t_stack *stack_a,t_stack *stack_b);
t_stack *make_base(t_stack *stack);


// Почему два значени - сегменташн фолт
// 
#endif