/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:41:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 14:41:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	f_abs(double d)
{
	if (d >= 0)
		return (d);
	else
		return (-d);
}

int		ft_checkpath(char **words, t_all *all, char *end)
{
	int	i;

	i = ft_strlen(words[1]);
	if (words[1][i - 1] != end[3] || words[1][i - 2] != end[2] ||
	words[1][i - 3] != end[1] || words[1][i - 4] != end[0])
	{
		printf("%s is not a valid %s file\n", words[1], end);
		all->isok += 1000;
		return (1);
	}
	return (0);
}
