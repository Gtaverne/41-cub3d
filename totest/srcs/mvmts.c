#include "../includes/cub3d.h"

void    ft_forward(t_all *all)
{
    int     i;

    i = 0;
    printf("On avance: xpos %i ypos %i\n", (int)all->xpos, (int)all->ypos);
    printf("case de la map : %c\n", all->map[(int)(all->ypos)]
        [(int)(all->xpos)]);
    while (i < MVSPEED)
    {
        if (is_insep(all->map[(int)(all->ypos + all->ydir / PACE)]
        [(int)(all->xpos + all->xdir / PACE)], "0"))
        {
            all->xpos += all->xdir / PACE;
            all->ypos += all->ydir / PACE;
        }
        else if (is_insep(all->map[(int)(all->ypos + all->ydir / PACE)]
        [(int)(all->xpos)], "0"))
            all->ypos += all->ydir / PACE;
        else if (is_insep(all->map[(int)(all->ypos)]
        [(int)(all->xpos + all->xdir / PACE)], "0"))
            all->xpos += all->xdir / PACE;
        else
            break ;
        i++;
    }
}

void    ft_side(t_all *all)
{
    double i;

    printf("On va sur un coté\n");
    i = (double)(all->right - all->left) / PACE;
    if (i == 0)
        return ;
    if (is_insep(all->map[(int)(all->ypos + i * all->xdir)]
    [(int)(all->xpos - i * all->ydir)], "0"))
    {
        all->xpos += - i * all->ydir;
        all->ypos += i * all->xdir;
    }
    else if (is_insep(all->map[(int)(all->ypos)]
    [(int)(all->xpos - i * all->ydir)], "0"))
        all->xpos += - i * all->ydir;
    else if (is_insep(all->map[(int)(all->ypos + i * all->xdir)]
    [(int)(all->xpos)], "0"))
        all->ypos += i * all->xdir;
    else
        return ;
}

void    ft_back(t_all *all)
{
    printf("On recule\n");
    if (is_insep(all->map[(int)(all->ypos - all->ydir / PACE)]
    [(int)(all->xpos - all->xdir / PACE)], "0"))
    {
        all->xpos -= all->xdir / PACE;
        all->ypos -= all->ydir / PACE;
    }
    else if (is_insep(all->map[(int)(all->ypos - all->ydir / PACE)]
    [(int)(all->xpos)], "0"))
        all->ypos -= all->ydir / PACE;
    else if (is_insep(all->map[(int)(all->ypos)]
    [(int)(all->xpos - all->xdir / PACE)], "0"))
        all->xpos -= all->xdir / PACE;
    else
        return ;
}

void    ft_turn(t_all *all)
{
    double     i;
    double  temp;

    i = (double)(all->turn_right - all->turn_left) / PACE;
    if (i == 0)
        return ;
    temp = all->xdir;
    all->xdir = cos(i * ANGLE) * all->xdir - sin(i * ANGLE) * all->ydir;
    all->ydir = sin(i * ANGLE) * temp + cos(i * ANGLE) * all->ydir;
    printf("xdir: %f ydir: %f \n", all->xdir, all->ydir);
}

void    ft_mvt(t_all *all)
{
    if (all->forward)
        ft_forward(all);
    if (all->backward)
        ft_back(all);
    if (all->left || all->right)
        ft_side(all);
    if (all->turn_left || all->turn_right)
        ft_turn(all);
}