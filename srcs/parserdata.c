/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:49:10 by user42            #+#    #+#             */
/*   Updated: 2021/03/01 21:49:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_resfill(t_all all, char **words)
{
	all.y_screen = ft_atoi(words[1]);
	all.x_screen = ft_atoi(words[2]);
	if (all.y_screen < 5 || all.x_screen < 5)
	{
		printf("Resolution false or too low, x = %d, y = %d \n"\
		, all.x_screen, all.y_screen);
		all.isok +=1000;
	}
	else
		all.isok += 100;
}

int		ft_rgb(char **words, t_all all)
{
	int	i;

	i = ft_atoi(words[1]) * 65536 + ft_atoi(words[2]) * 256 \
	+ ft_atoi(words[3]);
	if (i >=0 && i <16777216)
		all.isok += 1;
	else
	{
		printf("Wrong colour code\n");
	}
	return (i);
}

char	*ft_pathfill(char **words, t_all all)
{
	char	*res;

	res = ft_strdup(words[1]);
	printf("Res: %s\n", res);
	if (open(res, O_RDONLY) < 0)
	{
		all.isok += 1000;
		printf("\nwrong path : %s\n", res);
		return (NULL);
	}
	else
		all.isok += 10;
	return (res);
}

void		ft_ispath(t_all all, char **words)
{
	if (words[0][0] == 'N' && words[0][1] == 'O' && words[0][2] == 0)
		all.no_path = ft_pathfill(words, all);
	if (words[0][0] == 'S' && words[0][1] == 'O' && words[0][2] == 0)
		all.so_path = ft_pathfill(words, all);
	if (words[0][0] == 'W' && words[0][1] == 'E' && words[0][2] == 0)
		all.we_path = ft_pathfill(words, all);
	if (words[0][0] == 'E' && words[0][1] == 'A' && words[0][2] == 0)
		all.ea_path = ft_pathfill(words, all);
	if (words[0][0] == 'S' && words[0][1] == 0)
		all.s_path = ft_pathfill(words, all);
}

int		ft_parserdata(t_all all, int fd, char *line)
{
	char	**words;

	while (get_next_line(fd, &line) == 1 && all.isok < 152)
	{
		words = ft_split(line, " ,");
		if (words[0][0] == 'R' && words[0][1] == 0)
			ft_resfill(all, words);
		ft_ispath(all, words);
		if (words[0][0] == 'F' && words[0][1] == 0)
			all.floor_rgb = ft_rgb(words, all);
		if (words[0][0] == 'C' && words[0][1] == 0)
			all.ceil_rgb = ft_rgb(words, all);
	}
	return (all.isok == 152);
}