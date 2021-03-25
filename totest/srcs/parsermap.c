/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:20:54 by user42            #+#    #+#             */
/*   Updated: 2021/03/18 19:07:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_firstmapline(t_all *all, int fd, char *line)
{
	while (get_next_line(fd, &line) >= 0 && line)
	{
		if (line[0] != 0)
		{
			all->map[0] = ft_strdup(line);
			all->mapwdth = ft_strlen(all->map[0]);
			all->mapheight += 1;
			free(line);
			return ;
		}
		free(line);
	}
	all->isok += 1000;
	printf("\nNo map found\n");
}

int		ft_validmap(t_all *all)
{
	int		i;
	int		j;

	i = 0;
	while (all->map[i] != 0)
	{
		j = 0;
		while (all->map[i][j] != 0)
		{
			if (is_insep(all->map[i][j], "NSWE"))
				ft_mempos(all, i, j);
			if (all->map[i][j] == '0')
			{
				if (ft_testpos(all, i, j) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	all->isok += 100;
	return (1);
}

void	ft_spacepad(t_all *all)
{
	int		i;

	i = 0;
	printf("we pad the map\n");
	while (all->map[i])
	{
		while (ft_strlen(all->map[i]) < all->mapwdth)
			all->map[i] = ft_joinofgnl(all->map[i], " ");
		i++;
	}
}

int		ft_parsermap(t_all *all, int fd, char *line)
{
//	int	i;
	int	n;

	n = 1;
//	i = 0;
	ft_firstmapline(all, fd, line);
	while (get_next_line(fd, &all->map[n]) >= 0 && n < 2046)
	{
		if (all->map[n][0] == 0 || all->map[n][0] == '\n')
		{
			free(all->map[n]);
			break ;
		}
		if (ft_strlen(all->map[n]) > all->mapwdth)
			all->mapwdth = ft_strlen(all->map[n]);
		n++;
		all->mapheight += 1;
	}
	all->map[n] = 0;
	ft_validmap(all);
	ft_spacepad(all);
	return (all->isok == 325);
}
