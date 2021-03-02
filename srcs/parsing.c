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

void	ft_resfill(t_all all, char *line)
{
	return ;
}

char	*ft_pathfill(char *line, t_all all)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (line[i] == ' ')
		i++;
	j = ft_strlen(line + i);
	res = malloc(sizeof(*res) * (j + 1));
	if (!res)
		return (NULL);
	j = -1;
	while (line[i + j + 1] != 0 && line[i + j + 1] != ' ')
		res [j++] = line[i + j];
	res[j + 1] = 0;
	if (open(res, O_RDONLY) < 0)
	{
		all.isok = all.isok + 1000;
		return (NULL);
	}
	else
		all.isok += 10;
	return (res);
}

int		ft_ispath(t_all all, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		all.NO_path = ft_pathfill(line, all);
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		all.SO_path = ft_pathfill(line, all);
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		all.WE_path = ft_pathfill(line, all);
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		all.EA_path = ft_pathfill(line, all);
	if (line[0] == 'S' && line[1] == ' ')
		all.S_path = ft_pathfill(line, all);
}

int		ft_parserdata(t_all all, int fd, char *line)
{
	int	i;

	while (get_next_line(fd, &line) == 1 && all.isok != 255)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == 'R' && line[i + 1] == ' ')
			ft_resfill(all, line + i);
		ft_ispath(all, line + i);
		if (line[i] == 'F' && line[i + 1] == ' ')
			all.floor_rgb = ft_rgb(line + i);
		if (line[i] == 'C' && line[i + 1] == ' ')
			all.ceil_rgb = ft_rgb(line + i);
	}
	return (all.isok == 255);
}