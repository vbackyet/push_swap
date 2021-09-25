#include "push_swap.h"

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
