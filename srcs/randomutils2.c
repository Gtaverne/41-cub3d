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

void	ft_rgberror(t_all *all, char *str)
{
	printf("Reformat %s\nExample : C 100,0,50\n", str);
	all->isok += 1000;
}

void	ft_countchar(char *str, char c, t_all *all)
{
	int	i;
	int	k;
	int j;

	i = -1;
	k = 0;
	j = 0;
	str = str + 2;
	while (str[++i] && is_insep(str[i], "0123456789"))
		j = 1;
	k += j;
	j = 0;
	if (str[i] == c)
		k++;
	while (str[++i] && is_insep(str[i], "0123456789"))
		j = 1;
	k += j;
	j = 0;
	if (str[i] == c)
		k++;
	while (str[++i] && is_insep(str[i], "0123456789"))
		j = 1;
	k += j;
	if (k != 5)
		ft_rgberror(all, str - 2);
}

char	*ft_strspl(char *line)
{
	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		return (" ,");
	else if (line[0] == 'R' || line[0] == 'S' || line[0] == 'W'
	|| line[0] == 'E' || line[0] == 'N')
		return (" ");
	else
		return (" \n");
}
