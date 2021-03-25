#include "../includes/cub3d.h"

void	ft_finalcheck(t_all *all)
{
	if (all->no_path[0] && all->ea_path[0] && 
	all->so_path[0] && all->we_path[0] && all->s_path[0] 
	&& all->floor_rgb != -1 && all->ceil_rgb != -1 && all->xpos != -1 
	&& all->ypos != -1 && f_abs(all->xdir) + f_abs(all->ydir) == 1
	&& all->x_screen > 5 && all->y_screen > 5)
		all->isok += 1000;
}

double	f_abs(double d)
{
	if (d >= 0)
		return (d);
	else
		return (-d);
}