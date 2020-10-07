#include	"../includes/cub3d.h"

static int		x_max(t_cub3d cub3d, int y)
{
    int x;

    x = 0;
    y = y / BLOCK_SIZE;
	while (cub3d.config.map_ok[y][x + 1] != '\n')
		x++;
	return(x);
}

static float	rayon_h2(t_cub3d cub3d, float ay, float ax, float ya, float xa)
{
	while (1)
    {
		(ax < 0) ? ax = 0 : 0;
		((ax / BLOCK_SIZE) > x_max(cub3d, ay)) ? ax = x_max(cub3d, ay) * BLOCK_SIZE : 0;
        if (cub3d.config.map_ok[(int)ay / BLOCK_SIZE][(int)ax / BLOCK_SIZE] == '1')
            return (sqrt(pow(cub3d.player.fposx - ax, 2) + pow(cub3d.player.fposy - ay, 2)));
        ay += ya;
        ax += xa;
    }
}

float       	rayon_h(t_cub3d cub3d, float alpha)
{
    float   ya;
    float   xa;
    float   ax;
    float   ay;

    ya = BLOCK_SIZE;
    xa = BLOCK_SIZE / tanf(alpha);
    if (alpha < M_PI && alpha > 0)
    {
        ay = (cub3d.player.fposy / BLOCK_SIZE) * (BLOCK_SIZE) - 0.001;
        ya *= -1;
    }
    else
    {
        ay = (int)(cub3d.player.fposy / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
        xa *= -1;
    }
    ax = (int)cub3d.player.fposx + ((cub3d.player.fposy - ay) / tanf(alpha));
    return (rayon_h2(cub3d, ay, ax, ya, xa));
}

static float    rayon_v2(t_cub3d cub3d, float ay, float ax, float ya, float xa)
{
	while (1)
    {
        (ay < 0) ? ay = 0 : 0;
        ((ay / BLOCK_SIZE) > cub3d.config.y_max) ? ay = cub3d.config.y_max * BLOCK_SIZE : 0;
        if (cub3d.config.map_ok[(int)ay / BLOCK_SIZE][(int)ax / BLOCK_SIZE] == '1')
            return (sqrt(pow(cub3d.player.fposx - ax, 2) + pow(cub3d.player.fposy - ay, 2)));
        ay -= ya;
        ax += xa;
    }
}

float	        rayon_v(t_cub3d cub3d, float alpha)
{
    float   ya;
    float   xa;
    float   ax;
    float   ay;

    xa = BLOCK_SIZE;
    if ((alpha > M_PI_2) && (alpha < (3 * M_PI_2)))
    {
        ax = (int)(cub3d.player.fposx / BLOCK_SIZE) * (BLOCK_SIZE) - 0.001;
        xa *= -1;
    }
    else
        ax = (int)(cub3d.player.fposx / BLOCK_SIZE) * (BLOCK_SIZE) + BLOCK_SIZE;
    ya = xa * tan(alpha);
    ay = (int)cub3d.player.fposy + ((cub3d.player.fposx - ax) * tan(alpha));
    return(rayon_v2(cub3d, ay, ax, ya, xa));
}