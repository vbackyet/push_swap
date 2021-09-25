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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		++len;
	return (len);
}
