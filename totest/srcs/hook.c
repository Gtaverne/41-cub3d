#include "../includes/cub3d.h"

int     ft_key_hook(int n, t_all *all)
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
   printf("n : %d\n", n);
   (void)all;
   return (0);
}


int     ft_key_unhook(int n, t_all *all)
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
   (void)all;
   return (0);
}