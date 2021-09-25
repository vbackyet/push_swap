#include "get_next_line.h"

char	*check_remainer(char *remain, char **line)
{
	int		pos_of_back_sl;
	char	*post_remain;
	char	*tmp;

	if (ft_strchr(remain, '\n'))
	{
		post_remain = ft_strdup(ft_strchr(remain, '\n') + 1);
		pos_of_back_sl = ft_strstr(remain, "\n");
		remain[pos_of_back_sl] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, remain);
		free(tmp);
		return (post_remain);
	}
	return (remain);
}

void	str_join_with_free(char **line, char *l, int flag, int flag2)
{
	char	*tmp;
	int		temp;

	if (flag2)
	{
		temp = ft_strstr(l, "\n");
		while (l[temp] != '\0')
		{
			l[temp] = '\0';
			temp++;
		}
	}
	tmp = *line;
	*line = ft_strjoin(*line, l);
	free(tmp);
	if (flag)
		l[0] = '\0';
}

static char	*process_remain(char *remain, char **li, char *l, int curr_pointer)
{
	char	*rem_consist_n;
	char	*bef_remain;

	if (remain)
	{
		bef_remain = ft_strdup(remain);
		rem_consist_n = check_remainer(remain, li);
		if (ft_strcmp(bef_remain, rem_consist_n))
		{
			free(remain);
			free(bef_remain);
			remain = rem_consist_n;
			return (remain);
		}
		str_join_with_free(li, remain, 0, 0);
		free(remain);
		if (bef_remain)
			free(bef_remain);
		remain = NULL;
		return (remain);
	}
	l[curr_pointer] = '\0';
	return (remain);
}

static int	beggining(char **line, char *l, int fd, int curr_pointer)
{
	*line = ft_strdup("");
	l[0] = '\0';
	if (!curr_pointer)
		curr_pointer = read(fd, l, BUFFER_SIZE);
	return (curr_pointer);
}

int	get_next_line(int fd, char **line)
{
	char		l[BUFFER_SIZE + 1];
	static char	*remain;
	static int	curr_pointer;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, l, 0) < 0)
		return (-1);
	curr_pointer = beggining(line, l, fd, curr_pointer);
	while (remain || curr_pointer)
	{
		if ((curr_pointer < 0) || (curr_pointer > BUFFER_SIZE))
			return (-1);
		remain = process_remain(remain, line, l, curr_pointer);
		if (remain)
			return (1);
		if (ft_strchr(l, '\n'))
		{
			remain = ft_strdup(ft_strchr(l, '\n') + 1);
			str_join_with_free(line, l, 1, 1);
			return (1);
		}
		str_join_with_free(line, l, 1, 0);
		curr_pointer = read(fd, l, BUFFER_SIZE);
	}
	free(remain);
	return (0);
}
