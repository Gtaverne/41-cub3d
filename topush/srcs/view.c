#include "../includes/cub3d.h"

int	ft_view(t_all *all)
{
	void	*mlx;
	void	*mlx_win;
	int		i;

	mlx = mlx_init();
	
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