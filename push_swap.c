#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"



int check_the_argument(int argc, char **argv)
{
    //Проверка аргументов
    //some arguments aren’t integers, some arguments arebigger than an integer, and/or there are duplicates.
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
	t_stack *begin;
	t_stack *markable;

	begin = stack;
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
	int max_num;
	int value;

	max_num = stack->num;
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

t_stack *addelem(t_stack *stack, int number, int pos)
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




t_stack *insert_into_stack(int argc, char **argv)
{
    t_stack         *stack;
    t_stack         *first_el_of_stack;
    int i;
    int pos_index;

    pos_index = 0;
    // printf("%d <- сколько аргументов\n",argc);
    stack = (t_stack *)malloc(sizeof(t_stack));
	  stack->chunk = 0;
    stack->num = atoi(argv[1]);
    stack->pos = pos_index;
	  stack->index = -1;
    stack->next = NULL; // указатель на следующий узел
    stack->prev = NULL; // указатель на предыдущий узел
    // printf("%d <- сколько аргументов\n",argc);
    i = 2;
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
      printf("{%d | %d }", p->index, p->base); // вывод значения элемента p
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
  while (len_of_the_stack-1 > 1)
  {
    if (((find_on_index(stack, len_of_the_stack-1))->num) < ((find_on_index(stack, len_of_the_stack-2))->num))
      return 0;
    len_of_the_stack--;
  }
  return 1;
}


t_stack *sort_the_little_stack(t_stack *stack_a,t_stack *stack_b)
{

  int length_the_biggest = depth(find_on_value(stack_a,find_maximum_value(stack_a))->base);
  int i = 1;
  int counter_of_operations = 0;
  
  while (length_the_biggest)
  {
    int length_of_the_stacky = detect_len_of_stack(stack_a);
    if (the_stack_is_sorted(stack_a))
      return stack_a;
    printf("%d", i);
        printf("\na:");
        listprint(stack_a);
        printf("\nb:");
        listprint(stack_b);
    while (length_of_the_stacky > 0)
    {
      printf("HERE [%d]",((stack_a->base)/ft_power(10, i-1)) % 10);

      if ((((stack_a->base)/ft_power(10, i-1)) % 10) == 0)
        
        {

        perform_command(&stack_a, &stack_b, "pb");
        counter_of_operations++;

        }
      else
      {
        perform_command(&stack_a, &stack_b, "ra");
        counter_of_operations++;
       
      }
      length_of_the_stacky--;
      printf("%d - length_of_the_stacky\n", length_of_the_stacky);
    }
    while(stack_b!= NULL)
        { 
        perform_command(&stack_a, &stack_b, "pa");
        //printf("\nafter\nb:");
        counter_of_operations++;

        if (stack_b == NULL)
          printf("KOTIK");
        }
    length_the_biggest--;
    i++;     

  }
  printf("\ncounter :%d\n", counter_of_operations);
  return stack_a;
}



// Сделать сортировку для маленьких чисел
// оптимизировать сортирку - как
// разделить на панчи по 16 штук и на порядок 

t_stack *sort_the_stack(t_stack *stack_a,t_stack *stack_b)
{
   //Here we treat A as box 1 and B as box 0
   //At the i-th digit from the right, if the i-th digit of the top number of A is 0, we perform pb to put this number in stack B. 
   //Else, we perform ra to leave it in stack A. After we perform one operation on each number, each of them is in the box that corresponds 
   //to its digit, as how we put numbers in the boxes in radix sort.
  //1) узнать длину последнего номера
  //2) пройти цикл столько раз 
  //3) узнать длину стаки и пройтись по циклу и закидывать pb /ra
  //4) все получилось алилуя

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
    if (the_stack_is_sorted(stack_a))
      return stack_a;
    printf("%d", i);
        printf("\na:");
        listprint(stack_a);
        printf("\nb:");
        listprint(stack_b);
    while (length_of_the_stacky > 0)
    {
      printf("HERE [%d]",((stack_a->base)/ft_power(10, i-1)) % 10);

      if ((((stack_a->base)/ft_power(10, i-1)) % 10) == 0)
        
        {

        perform_command(&stack_a, &stack_b, "pb");
        counter_of_operations++;

        }
      else
      {
        perform_command(&stack_a, &stack_b, "ra");
        counter_of_operations++;
       
      }
      length_of_the_stacky--;
      printf("%d - length_of_the_stacky\n", length_of_the_stacky);
    }
    while(stack_b!= NULL)
        { 
        perform_command(&stack_a, &stack_b, "pa");
        //printf("\nafter\nb:");
        counter_of_operations++;

        if (stack_b == NULL)
          printf("KOTIK");
        }
    length_the_biggest--;
    i++;     

  }
  printf("\ncounter :%d\n", counter_of_operations);
  return stack_a;
}





int main(int argc, char **argv)
{
    t_stack         *stack_a;
    t_stack         *stack_b;

    char *a[4];
    a[0] = "1";
    a[1] = "2";
    a[2] = "3";
    a[3] = "4";
    if (check_the_argument(argc, argv))
        write(1, "Error\n", 6);
    stack_a = insert_into_stack(argc, argv);
    stack_a = sort_and_index(stack_a);
    stack_a = make_base(stack_a);
    //printf("\nstack_is_sorted: %d", the_stack_is_sorted(stack_a));
    listprint(stack_a);
    stack_b = NULL;
    //stack_b = insert_into_stack(4, a);
    //stack_b = sort_and_index(stack_b);
    //stack_b = make_base(stack_b);
    stack_a = sort_the_stack(stack_a, stack_b);
    
    //  stack_b = sort_and_index(stack_b);
    //perform_command(&stack_a, &stack_b, "pa");
    printf("\nafter:");
    listprint(stack_a);
    
    
    
    // printf("\nb:");
    // listprint(stack_b);
    // printf("\n");


    // printf("\n\n\n\n\n");



    // rra(&stack_a);
    // printf("\na:");
    // listprint(stack_a);
    // printf("\nb:");
    // listprint(stack_b);
    // printf("\n");


}

//atoi
// sa :swap a- swap the first 2 elements at the top of stacka. Do nothing if thereis only one or no elements).





// pb  pops the first elememt on A and puts it on top of B
// ra  rotates stuck A up by one

// 1) Стак А в массив
// 2) отсортировать
// 45 34 1 23 6 3
// 1 3 6 23 34 45
// 3) Найти индекс миддла
// 2 индекс - 23

// 4) Я хожу по стаку А и все что меньше 23 перекидываю в стак Б
// 4.1 - 45 - не меньше чем 23 - идем ra
// 3 6 23 1 34 45 
// 4.2 - 3 - pb 
// 4.3 - 6 - pb
// 4.4 - 23 нет 45 тоже нет
// поэтому мы в топ переводим все пока не анйдем то что меньше и то что 3 элиента 
// 45 34 1 23 ra 
// 34 1 23 45
// 1 23 45 34 - pb
// 23 45 34 
// 5) Повторить то же самое с остатком (23 45 34) -> 23 34 45
// Серединка 45
// Нам повезло 23 -  меньше чем 45 
// Что у нас в стаке 45 
// (23 1 6 3) и сам миддл 34
// (34 23 1 6 3)
// 6) Делаем пока не останется 2 или меньше елементов- при необходимости сорируем
// ({45} {23} {1 6 3})
// 7)Делать то же самое только в обратном порядке
// [45] - > [34] -> [23] -> []
// 1) Еслив оставшемяся больше чем 2 чанка - то мы не можем просто делаем 
// rb -  а когда нашли то rrb - чтобы все исправить!!!!
// СДЕЛАТЬ чекер на то что чанк уже остортирован!!!!