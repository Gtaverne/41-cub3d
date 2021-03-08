/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:47:55 by gtaverne          #+#    #+#             */
/*   Updated: 2021/03/01 12:47:59 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_printall(t_all all)
{
	printf("\nPrint all_______________\n");
	printf("Res x: %d y%d\n", all.x_screen, all.y_screen);
	printf("Addresses:\n%s\n%s\n%s\n%s", all.no_path, all.so_path, all.we_path\
	, all.ea_path);
}

int		main (int argc, char **argv)
{
	int		fd;
	t_all	all;
	char	*line;

	if (argc != 2)
		return(0);
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	ft_parserdata(all, fd, line);
	ft_printall(all);
	return (1);
}