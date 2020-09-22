#include "../includes/cub3d.h"

static int		x_max(t_cub3d cub3d, int y)
{
    int x;

    x = 0;
	while (cub3d.config.map_ok[y][x + 1] != '\n' && cub3d.config.map_ok[y][x + 1])
		x++;
	return(x);
}

static float	rayon_h(t_cub3d cub3d, float alpha)
{
    float   ya;
    float   xa;
    float   ax;
    float   ay;

    ya = BLOCK_SIZE;
    xa = BLOCK_SIZE / tan(alpha);
    if (alpha < M_PI && alpha > 0)
    {
        ay = (cub3d.player.fposy / BLOCK_SIZE) * (BLOCK_SIZE - 0.01);
        ya *= -1;
    }
    else
        ay = (int)(cub3d.player.fposy / BLOCK_SIZE) * (BLOCK_SIZE + 64);
    ax = (int)cub3d.player.fposx + (cub3d.player.fposy - ay) / tan(alpha);
    xa = BLOCK_SIZE / tan(alpha);
    while (1)
    {
        (ay < 0) ? ay = 0 : 0;
        (ax < 0) ? ax = 0 : 0;
        ((ay / BLOCK_SIZE) > cub3d.config.y_max) ? ay = cub3d.config.y_max * BLOCK_SIZE : 0;
        ((ax / BLOCK_SIZE) > cub3d.config.x_max) ? ax = x_max(cub3d, ay) * BLOCK_SIZE : 0;
        ft_printf("%d\n", x_max(cub3d, ay));
        if (cub3d.config.map_ok[(int)ay / BLOCK_SIZE][(int)ax / BLOCK_SIZE] == '1')
            return (sqrt(pow(cub3d.player.fposx - ax, 2) + pow(cub3d.player.fposy - ay, 2)));
        ay += ya;
        ax += xa;
    }
}

static float	rayon_v(t_cub3d cub3d, float alpha)
{
    float   ya;
    float   xa;
    float   ax;
    float   ay;

    xa = BLOCK_SIZE;
    ya = BLOCK_SIZE / tan(alpha);
    if ((alpha >= (2 / M_PI)) && (alpha < (3 * (2 / M_PI))))
    {
        ax = (int)(cub3d.player.fposx / BLOCK_SIZE) * (BLOCK_SIZE - 0.01);
        xa *= -1;
    }
    else
        ax = (int)(cub3d.player.fposx / BLOCK_SIZE) * (BLOCK_SIZE + 64);
    ay = (int)cub3d.player.fposy + (cub3d.player.fposx - ax) / tan(alpha);
    ya = floor(BLOCK_SIZE / tan(alpha));
    while (1)
    {
        (ay < 0) ? ay = 0 : 0;
        (ax < 0) ? ax = 0 : 0;
        ((ay / BLOCK_SIZE) > cub3d.config.y_max) ? ay = cub3d.config.y_max * BLOCK_SIZE : 0;
        ((ax / BLOCK_SIZE) > cub3d.config.x_max) ? ax = x_max(cub3d, ay) * BLOCK_SIZE : 0;
        if (cub3d.config.map_ok[(int)ay / BLOCK_SIZE][(int)ax / BLOCK_SIZE] == '1')
            return (sqrt(pow(cub3d.player.fposx - ax, 2) + pow(cub3d.player.fposy - ay, 2)));
        ay += ya;
        ax += xa;
    }
}

static float	shortest_distance(t_cub3d cub3d, float alpha)
{
    float   rh;
    float   rv;
    float   correct;

    rh = rayon_h(cub3d, alpha);
    rv = rayon_v(cub3d, alpha);
    correct = (rh <= rv) ? rh : rv;
    //printf("rh: %f rv: %f correct: %s\n",rh, rv, (correct == rh) ? "Hori" : "Verti");
    return(correct);
}

void			scan(t_cub3d *cub3d)
{
    int     x;
    float   cons;
    float   alpha;
    float   sd;
    float   projected_wall;

    x = 0;
    cub3d->config.deep = (cub3d->win.x / 2) / tan(FOV * M_PI / 180);
    alpha = cub3d->config.POV - ((FOV * M_PI / 180) / 2);
    cons = (FOV * M_PI / 180) / cub3d->win.x;
    while (x < cub3d->win.x)
    {
        if (alpha <= 0)
            alpha += 2 * M_PI;
        sd = shortest_distance(*cub3d, alpha);
        projected_wall = (BLOCK_SIZE / sd) * cub3d->config.deep;
        //printf("%f = (%d / %f) * %f\n", projected_wall, BLOCK_SIZE, sd, cub3d->config.deep);
        display_wall(x, projected_wall, *cub3d);
        alpha += cons;
        x++;
    }
}