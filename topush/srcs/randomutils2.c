#include "../includes/cub3d.h"

void	ft_finalcheck(t_all *all)
{
	if (all->no_path[0] && all->ea_path[0] && \
	all->so_path[0] && all->we_path[0] && all->s_path[0] \
	&& all->floor_rgb != -1 && all->ceil_rgb != -1 && all->initpos[0] != 0 \
	&& all->x_screen > 5 && all->y_screen > 5)
		all->isok += 1000;
}