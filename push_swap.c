#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"


int is_not_digit(char *my_arg)
{
  int i =0;
  if (!(ft_strcmp(my_arg,"")))
    return 1;
  while (my_arg[i])
  {
    // printf("[%c]\n", my_arg[i]);
    if ((my_arg[i] < '0' || my_arg[i] > '9') && (my_arg[i] != '-'))
      return(1);
    i++;
  }
  return(0);
}


static int   ft_itoa_base_sneaky(int value, int base, int flag)
{
    char *ref = "0123456789ABCDEF";
    static int itog = 0;
    if (flag)
    {
      itog = 0;
      flag = 0;
    }
    if (value < base)
    {
         //*str = ref[value];
      int ia = ref[value] - '0';
      itog = itog*10 + ia ;
         //str++;
    }
    else if (value >= base)
    {
        ft_itoa_base_sneaky(value/base, base,0);
        ft_itoa_base_sneaky(value % base, base, 0);
    }
	  return itog;	  
}

// int		ft_strcmp(const char *s1, const char *s2)
// {
// 	unsigned char	*ptr1;
// 	unsigned char	*ptr2;
// 	size_t			i;

// 	ptr1 = (unsigned char *)s1;
// 	ptr2 = (unsigned char *)s2;
// 	i = 0;
// 	while (ptr1[i] || ptr2[i])
// 	{
// 		if (ptr1[i] != ptr2[i])
// 			return (ptr1[i] - ptr2[i]);
// 		i++;
// 	}
// 	return (0);
// }


int is_duplicate(int argc, char *el, char **spisok, int el_of_my_ind)
{
  int i = argc - 1;
  while (i > el_of_my_ind)
  {
    // printf("(%s) (%s) %d\n", el,spisok[i],ft_strcmp(spisok[i], el));
    if (!(ft_strcmp(spisok[i],  el)))
    {
      
        return(1);
    }
    i--;
  }
  return(0);
}

signed long long int		ft_atoi(const char *str)
{
	int i;
	signed long long int nbr;
	int negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
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



int check_the_argument(int argc, char **argv, int flag)
{
    //Проверка аргументов
    //some arguments aren’t integers, some arguments arebigger than an integer, and/or there are duplicates.
  int i = argc - flag ;

  while (i > 0)
  {

    if (is_not_digit(argv[i]))
      return(1);
    if (is_duplicate(argc, argv[i], argv, i))
      return(2);
      // printf("%lli\n", ft_atoi(argv[i]));
    if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
      return(3);
    i--;
  }

  return(0);
}






t_stack *find_on_value(t_stack *stack_a, int value)
{
  while (value != stack_a->num || !stack_a)
  {
    stack_a = stack_a -> next;
    // printf("%d - %d",stack_a->pos, index);
  }
  return stack_a;
}
//  Быстрая сортировка и индексация


int find_maximum(t_stack *stack, int the_index,int maximum)
{
	t_stack *begin;
	t_stack *markable;

	begin = stack;
	while (stack->next != NULL) 
	{
		if (stack->num >= maximum && stack->index ==  -1)
		{
			maximum = stack->num;	
		}
		stack = stack-> next;
	}
	if (stack->num >= maximum && stack->index ==  -1)
	{
		maximum = stack->num;	
	}
	markable = find_on_value(begin, maximum);
	// printf("<%d %d>",markable->pos, markable->num);
	markable->index = the_index;
	return maximum;
}


int find_maximum_value(t_stack *stack)
{
	// t_stack *begin;
	// t_stack *markable;

	// begin = stack;
  int maximum = stack->num;
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
	return maximum;
}





int find_minimum(t_stack *stack)
{
	int initial_min = stack->num;
  while (stack -> next != NULL)
  {
	if (stack->num < initial_min)
		initial_min = stack->num;
    stack = stack -> next;
    // printf("%d - %d",stack_a->pos, index);
  }
	if (stack->num < initial_min)
		initial_min = stack->num;
  return initial_min;
}

t_stack *sort_and_index(t_stack *stack)
{
	int len;
	// int max_num;
	int value;

  value = 0;
  value++;
	// max_num = stack->num;
	len = detect_len_of_stack(stack);
	// printf("%d <---------",len);
	while (len != 0)
	{
		value = find_maximum(stack, len-1, find_minimum(stack));
		// max_num = find_on_value(stack, value)->num - 1;
		len--;
	}
	return stack;
}

t_stack *make_base(t_stack *stack)
{
  t_stack *tmp;

  tmp = stack;
  while (stack-> next != NULL)
  {
    stack->base = ft_itoa_base_sneaky(stack->index , 2, 1);
    stack = stack-> next;
  }
  stack->base = ft_itoa_base_sneaky(stack->index , 2, 1);

	return tmp;
}



// https://github.com/sshiling/42-push_swap

void addelem(t_stack *stack, int number, int pos)
{
  t_stack *temp, *p;
  temp = (t_stack*)malloc(sizeof(t_stack));
  p = stack->next; // сохранение указателя на следующий узел
  stack->next = temp; // предыдущий узел указывает на создаваемый
  temp->num = number; // сохранение поля данных добавляемого узла
  temp->pos = pos;
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = stack; // созданный узел указывает на предыдущий узел
  temp->index = -1;
  if (p != NULL)
    p->prev = temp;
}




t_stack *insert_into_stack(int argc, char **argv, int flag)
{
    t_stack         *stack;
    t_stack         *first_el_of_stack;
    int i;
    int pos_index;

    pos_index = 0;
    // printf("%d <- сколько аргументов\n",argc);
    // printf("%s <- какой аргумент\n",argv[0]);
    stack = (t_stack *)malloc(sizeof(t_stack));
	  stack->chunk = 0;
    stack->num = atoi(argv[flag]);
    stack->pos = pos_index;
	  stack->index = -1;
    stack->next = NULL; // указатель на следующий узел
    stack->prev = NULL; // указатель на предыдущий узел
    // printf("%d <- сколько аргументов\n",argc);
    i = flag +1;
    // printf('%d quant\n',argc);
    first_el_of_stack = stack;
    while (argc > i)
    {
      // printf("%d <- сколько аргументов\n",argc);
        pos_index++;
        addelem(stack, atoi(argv[i]), pos_index);
        i++;
        stack = stack->next;
    }

    //присоединение других узлов к превоначальному
    return(first_el_of_stack);
}


void listprint(t_stack *lst)
{
  t_stack *p;
  p = lst;
  if (p!= NULL)
  {
    while (p != NULL) 
    {
      printf("{ %d | %d  | %d| %d}",p->num, p->pos, p->base, p->index); // вывод значения элемента p
      p = p->next; // переход к следующему узлу
    }  // условие окончания обхода
  }
  else
    printf("empty chain!\n");
}

int detect_len_of_stack(t_stack *stack)
{
  int i;

  i = 0;


  if (stack == NULL)
  {
    return 0;}
  while (stack-> next != NULL)
  {
    i++;
    stack = stack-> next;
  }
  return(i + 1);
}

t_stack *find_on_index(t_stack *stack_a, int index)
{
  while (index != stack_a->pos || !stack_a)
  {
    stack_a = stack_a -> next;
    // printf("%d - %d",stack_a->pos, index);
  }
  return stack_a;
}

t_stack *reset_index(t_stack *stack_a)
{
  t_stack *tmp;
  tmp = stack_a;
  int i = 0;
  while (tmp != NULL) 
  {
    tmp -> pos = i;
    // printf("{%d | %d}",tmp->num, tmp-> pos);
    tmp = tmp->next; // переход к следующему узлу
    i++;
  }  // условие окончания обхода
  return stack_a;
}


int depth(int base)
{
  int depth;
  depth = 1;

  while (base/10 > 0)
  {
    depth++;
    base = base/10;
  }


  return depth;
}

int     ft_power(int nb, int power)
{
    if (power < 0)
        return 0;
    int tmp;
    int r;
 
    tmp = 1;
    r = 1;
    while (tmp <= power)
    {
        r = r * nb;
        tmp++;
    }
    return r;
}


int the_stack_is_sorted(t_stack *stack)
{
  int len_of_the_stack = detect_len_of_stack(stack);
  while (len_of_the_stack-1 > 0)
  {
    if (((find_on_index(stack, len_of_the_stack-1))->num) < ((find_on_index(stack, len_of_the_stack-2))->num))
      return 0;
    len_of_the_stack--;
  }
  return 1;
}


t_stack *sort_little_stack(t_stack *stack_a,t_stack *stack_b, int len_of_the_stack)
{
//   With 3 numbers, we need to sort it with not more than 3 instructions.

//   With 5 numbers, we need to sort it with not more than 12 instructions.
    if (the_stack_is_sorted(stack_a) && (detect_len_of_stack(stack_b) == 0))
    {
      // printf("YHE_STACK_IS SORTED");
      return stack_a;
    }
  int counter_of_operations = 0;
  int max = find_maximum_value(stack_a);
  int min = find_minimum(stack_a);
  if (len_of_the_stack == 2)
  {
    if (((find_on_index(stack_a, 1))->num) < ((find_on_index(stack_a, 0))->num))
    {
      perform_command(&stack_a, &stack_b, "ra", 1);
      stack_a = reset_index(stack_a);
      counter_of_operations++;
    }
  }
  if (len_of_the_stack == 3)
  {
    
    if (((find_on_index(stack_a, 0))->num) == max)
      perform_command(&stack_a, &stack_b, "ra", 1);
    if (((find_on_index(stack_a, 1))->num) == max)
      perform_command(&stack_a, &stack_b, "rra", 1);
    if (((find_on_index(stack_a, 0))->num) > ((find_on_index(stack_a, 1))->num))
      perform_command(&stack_a, &stack_b, "sa", 1);
  }
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
  // printf("\ncounter :%d\n", counter_of_operations);
        return stack_a;
}




// Сделать сортировку для маленьких чисел
// оптимизировать сортирку - как
// разделить на панчи по 16 штук и на порядок 

t_stack *sort_big_stack(t_stack *stack_a,t_stack *stack_b)
{
   //Here we treat A as box 1 and B as box 0
   //At the i-th digit from the right, if the i-th digit of the top number of A is 0, we perform pb to put this number in stack B. 
   //Else, we perform ra to leave it in stack A. After we perform one operation on each number, each of them is in the box that corresponds 
   //to its digit, as how we put numbers in the boxes in radix sort.
  //1) узнать длину последнего номера
  //2) пройти цикл столько раз 
  //3) узнать длину стаки и пройтись по циклу и закидывать pb /ra
  //4) все получилось алилуя
  int length_the_biggest = depth(find_on_value(stack_a,find_maximum_value(stack_a))->base);
  int i = 1;
  int counter_of_operations = 0;
  
  while (length_the_biggest)
  {
    int length_of_the_stacky = detect_len_of_stack(stack_a);
    if (the_stack_is_sorted(stack_a) && (detect_len_of_stack(stack_b) == 0))
    {
      // printf("YHE_STACK_IS SORTED");
      return stack_a;
    }
    // printf("%d", i);
        // printf("\na:");
        // listprint(stack_a);
        // printf("\nb:");
        // listprint(stack_b);
    while (length_of_the_stacky > 0)
    {
      // printf("HERE [%d]",((stack_a->base)/ft_power(10, i-1)) % 10);

      if ((((stack_a->base)/ft_power(10, i-1)) % 10) == 0)
        
        {

        perform_command(&stack_a, &stack_b, "pb", 1);
        counter_of_operations++;

        }
      else
      {
        perform_command(&stack_a, &stack_b, "ra", 1);
        counter_of_operations++;
       
      }
      length_of_the_stacky--;
      // printf("%d - length_of_the_stacky\n", length_of_the_stacky);
    }
    while(stack_b!= NULL)
        { 
        perform_command(&stack_a, &stack_b, "pa", 1);
        //printf("\nafter\nb:");
        counter_of_operations++;

        // if (stack_b == NULL)
          // printf("KOTIK");
        }
    length_the_biggest--;
    i++;     

  }
  // printf("\ncounter :%d\n", counter_of_operations);
  return stack_a;
}


t_stack *sort_the_stack(t_stack *stack_a,t_stack *stack_b)
{
  int len_of_the_stack =  detect_len_of_stack(stack_a);
  // printf("\n%d length of the stack\n", len_of_the_stack);
  if (len_of_the_stack > 5)
    return(sort_big_stack(stack_a,stack_b));
  else
    return(sort_little_stack(stack_a,stack_b, len_of_the_stack));
}
////
static int	ft_strchar(char to_find, char *str)
{
	char	*sptr;

	sptr = str;
	while (*sptr != '\0')
		if (to_find == *sptr++)
			return (1);
	return (0);
}

static int	ft_wc(char *str, char *charset)
{
	int		i;

	i = 0;
	while (*str)
		if (ft_strchar(*str, charset))
			++str;
		else
		{
			++i;
			++str;
			while (*str && !ft_strchar(*str, charset))
				++str;
		}
	return (i);
}

static char	*ft_split_w(char **str, char *charset)
{
	char	*bptr;
	char	*bsptr;
	char	*sptr;

	sptr = *str;
	while (ft_strchar(*sptr, charset))
		++sptr;
	*str = sptr;
	while (!ft_strchar(*sptr, charset))
		++sptr;
	bptr = malloc(sptr - *str);
	if (!bptr)
		return (NULL);
	bsptr = bptr;
	while (sptr > *str)
		*bsptr++ = *((*str)++);
	*bsptr = '\0';
	while (**str && ft_strchar(**str, charset))
		++*str;
	return (bptr);
}

char		**ft_split(char *str, char *charset)
{
	char	**buffer;
	char	**bptr;
	int		i;

	i = ft_wc(str, charset);
	if (!(buffer = malloc((i + 1) * sizeof(char *))))
		return (NULL);
	bptr = buffer;
	while (i--)
		if (!(*bptr++ = ft_split_w(&str, charset)))
			return (NULL);
	*bptr = (NULL);
	return (buffer);
}
 ////

int len_of_the_args(char **my_values)
{
  int i = 0;
  while (my_values[i])
    i++;
  return(i);
}



