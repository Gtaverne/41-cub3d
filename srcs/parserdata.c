/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:49:10 by user42            #+#    #+#             */
/*   Updated: 2021/03/18 18:58:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_resfill(t_all *all, char **words)
{
	all->x_screen = ft_atoi(words[1]);
	all->y_screen = ft_atoi(words[2]);
	if (all->x_screen < 5 || all->y_screen < 5)
	{
		printf("Resolution false or too low, x = %d, y = %d \n"\
		, all->x_screen, all->y_screen);
		all->isok = all->isok + 1000;
	}
	else
		all->isok += 100;
}

int		ft_rgb(char **words, t_all *all)
{
	int	i;

	i = ft_atoi(words[1]) * 65536 + ft_atoi(words[2]) * 256 \
	+ ft_atoi(words[3]);
	if (i >= 0 && i < 16777216 && words[4] == 0)
		all->isok += 10;
	else
	{
		printf("Error\nWrong colour code\n");
		all->isok += 1000;
	}
	return (i);
}

char	*ft_pathfill(char **words, t_all *all)
{
	int		fd;
	char	*res;

	printf("\nwe fill a path\n");
	res = ft_strdup(words[1]);
	fd = open(res, O_RDONLY);
	if (fd < 0 || words[2] != 0)
	{
		all->isok = all->isok + 1000;
		printf("Error\nWrong path : %s\n", res);
		free(res);
		close(fd);
		return (NULL);
	}
	else
	{
		all->isok += 1;
		close(fd);
	}
	return (res);
}

void	ft_ispath(t_all *all, char **words)
{
	if (words[0][0] == 'N' && words[0][1] == 'O' && words[0][2] == 0
	&& !all->no_path)
		all->no_path = ft_pathfill(words, all);
	else if (words[0][0] == 'S' && words[0][1] == 'O' && words[0][2] == 0
	&& !all->so_path)
		all->so_path = ft_pathfill(words, all);
	else if (words[0][0] == 'W' && words[0][1] == 'E' && words[0][2] == 0
	&& !all->we_path)
		all->we_path = ft_pathfill(words, all);
	else if (words[0][0] == 'E' && words[0][1] == 'A' && words[0][2] == 0
	&& !all->ea_path)
		all->ea_path = ft_pathfill(words, all);
	else if (words[0][0] == 'S' && words[0][1] == 0 && !all->s_path)
		all->s_path = ft_pathfill(words, all);
	else
		all->isok += 1000;
}

int		ft_parserdata(t_all *all, int fd, char *line)
{
	char	**words;

	while (get_next_line(fd, &line) == 1 && all->isok < 125)
	{
		words = ft_split(line, " ,");
		free(line);
		if (!words[0])
			;
		else if (words[0][0] == 'R' && words[0][1] == 0)
			ft_resfill(all, words);
		else if (words[0][0] == 'F' && words[0][1] == 0)
			all->floor_rgb = ft_rgb(words, all);
		else if (words[0][0] == 'C' && words[0][1] == 0)
			all->ceil_rgb = ft_rgb(words, all);
		else
			ft_ispath(all, words);
		if (all->isok >= 1000)
			printf("Check if data is valid\n");
		ft_freesplit(words);
	}
	free(line);
	if (all->isok == 125)
		return (1);
	ft_cleangnl(fd, line);
	return (0);
}
