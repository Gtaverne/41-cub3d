#include "../includes/cub3d.h"

int		ft_testview(t_all *all)
{
	//int 	i;

	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->x_screen, all->y_screen, "Dudule forever");
	mlx_loop_hook(all->mlx, raycasting, all);
	mlx_hook(all->win, 2, 1L << 0, ft_key_hook, all);

    mlx_hook(all->win, 3, 1L << 1, ft_key_unhook, all);
	all->img = mlx_new_image(all->mlx, all->x_screen, all->y_screen);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel, &all->line_length,
	 &all->endian);
	mlx_loop(all->mlx);
	return(0);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}