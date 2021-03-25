#include "../includes/cub3d.h"

void	ft_cleanstruct(t_all *all)
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
}