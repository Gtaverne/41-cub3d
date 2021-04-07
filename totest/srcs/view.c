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


int		ft_testview(t_all *all)
{
	all->mlx = mlx_init();
	if (all->save == 0)
	{
		all->win = mlx_new_window(all->mlx, all->x_screen, all->y_screen, "Dudule forever");
		mlx_loop_hook(all->mlx, raycasting, all);
		mlx_hook(all->win, 2, 1L << 0, ft_key_hook, all);
		mlx_hook(all->win, 3, 1L << 1, ft_key_unhook, all);
	}
	all->img = mlx_new_image(all->mlx, all->x_screen, all->y_screen);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel, &all->line_length,
	 &all->endian);
	ft_initext(all);
	if (all->save == 1)
		raycasting(all);
	mlx_loop(all->mlx);
	return(0);
}
