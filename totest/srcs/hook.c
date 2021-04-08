/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:06 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:37:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_key_hook(int n, t_all *all)
{
	if (n == KEY_FORWARD)
		all->forward = 1;
	if (n == KEY_BACKWARD)
		all->backward = 1;
	if (n == KEY_RIGHT)
		all->right = 1;
	if (n == KEY_LEFT)
		all->left = 1;
	if (n == KEY_TURN_LEFT)
		all->turn_left = 1;
	if (n == KEY_TURN_RIGHT)
		all->turn_right = 1;
	if (n == KEY_ESCAPE)
		ft_cleanstruct(all);
	return (0);
}

int	ft_key_unhook(int n, t_all *all)
{
	if (n == KEY_FORWARD)
		all->forward = 0;
	if (n == KEY_BACKWARD)
		all->backward = 0;
	if (n == KEY_RIGHT)
		all->right = 0;
	if (n == KEY_LEFT)
		all->left = 0;
	if (n == KEY_TURN_LEFT)
		all->turn_left = 0;
	if (n == KEY_TURN_RIGHT)
		all->turn_right = 0;
	return (0);
}
