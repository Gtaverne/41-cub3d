/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:11:31 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:11:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cleanmlx(t_all *all)
{
	int	i;

	i = -1;
	mlx_destroy_image(all->mlx, all->img);
	while (++i < 5)
		if (all->text[i].img != 0)
			mlx_destroy_image(all->mlx, all->text[i].img);
	if (all->save == 0)
		mlx_destroy_window(all->mlx, all->win);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
}

void	ft_cleangnl(int fd, char *line)
{
	while (get_next_line(fd, &line) > 0)
		free(line);
	free(line);
}

int		ft_cleanstruct(t_all *all)
{
	int	i;

	i = 0;
	if (all->no_path)
		free(all->no_path);
	if (all->so_path)
		free(all->so_path);
	if (all->ea_path)
		free(all->ea_path);
	if (all->we_path)
		free(all->we_path);
	if (all->s_path)
		free(all->s_path);
	while (all->map[i])
	{
		free(all->map[i]);
		i++;
	}
	if (all->escape == 1)
		ft_cleanmlx(all);
	printf("We clean and we close\n");
	exit(0);
	return (0);
}
