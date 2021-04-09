/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:47:04 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 14:47:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_initext(t_all *all)
{
	int	i;

	all->text[0].img = mlx_xpm_file_to_image(all->mlx, all->ea_path,
	&all->text[0].width, &all->text[0].height);
	all->text[1].img = mlx_xpm_file_to_image(all->mlx, all->so_path,
	&all->text[1].width, &all->text[1].height);
	all->text[2].img = mlx_xpm_file_to_image(all->mlx, all->we_path,
	&all->text[2].width, &all->text[2].height);
	all->text[3].img = mlx_xpm_file_to_image(all->mlx, all->no_path,
	&all->text[3].width, &all->text[3].height);
	all->text[4].img = mlx_xpm_file_to_image(all->mlx, all->s_path,
	&all->text[4].width, &all->text[4].height);
	i = 0;
	while (i < 5)
	{
		all->text[i].add = mlx_get_data_addr(all->text[i].img,
		&all->text[i].bits_per_pixel, &all->text[i].line_length,
		&all->text[i].endian);
		i++;
	}
}

void	ft_checkres(t_all *all)
{
	int x;
	int y;

	mlx_get_screen_size(all->mlx, &x, &y);
	if (all->x_screen > x && all->save == 0)
		all->x_screen = x;
	if (all->y_screen > y && all->save == 0)
		all->y_screen = y;
}

int		ft_testview(t_all *all)
{
	all->mlx = mlx_init();
	ft_checkres(all);
	if (all->save == 0)
	{
		all->win = mlx_new_window(all->mlx, all->x_screen,
		all->y_screen, "On va rester SFW");
		mlx_loop_hook(all->mlx, raycasting, all);
		mlx_hook(all->win, 2, 1L << 0, ft_key_hook, all);
		mlx_hook(all->win, 33, 1L << 5, ft_cleanstruct, all);
		mlx_hook(all->win, 3, 1L << 1, ft_key_unhook, all);
	}
	all->img = mlx_new_image(all->mlx, all->x_screen, all->y_screen);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel,
	&all->line_length, &all->endian);
	ft_initext(all);
	if (all->save == 1)
		raycasting(all);
	mlx_loop(all->mlx);
	return (0);
}

int		raycasting(t_all *all)
{
	all->col = 0;
	if (all->save == 0)
		mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	while (all->col < all->x_screen)
	{
		all->xc = 2 * all->col / (double)all->x_screen - 1;
		all->xmap = (int)all->xpos;
		all->ymap = (int)all->ypos;
		all->rdirx = all->xdir + all->xcam * all->xc;
		all->rdiry = all->ydir + all->ycam * all->xc;
		if (all->rdirx == 0)
			all->deltadistx = 10000000;
		else
			all->deltadistx = f_abs(1 / all->rdirx);
		if (all->rdiry == 0)
			all->deltadisty = 10000000;
		else
			all->deltadisty = f_abs(1 / all->rdiry);
		ft_step(all);
		all->bufferdist[all->col] = all->walldist;
		all->col++;
	}
	raycasting2(all);
	return (0);
}
