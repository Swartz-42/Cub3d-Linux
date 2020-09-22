#include "../includes/cub3d.h"

static void	mouv_player_x(t_config *config, t_player *player, float value)
{
	float	posx;
	int		xmax;
	char	pos;

	xmax = 0;
	posx = player->fposx + value;
	while (config->map_ok[(int)(player->fposy / BLOCK_SIZE)][xmax] != '\n')
		xmax++;
	if (posx < (xmax * BLOCK_SIZE) && posx > BLOCK_SIZE)
	{
		pos = config->map_ok[(int)(player->fposy / BLOCK_SIZE)][(int)(posx / BLOCK_SIZE)];
		player->fposx = (pos != '1') ? posx : player->fposx;
	}

}

static void	mouv_player_y(t_config *config, t_player *player, float value)
{
	float	posy;
	char	pos;

	posy = player->fposy + value;
	if (posy < (config->y_max * BLOCK_SIZE) && posy > BLOCK_SIZE)
	{
		pos = config->map_ok[(int)(posy / BLOCK_SIZE)][(int)(player->fposx / BLOCK_SIZE)];
		player->fposy = (pos != '1') ? posy : player->fposy;
	}
}

static void	ft_mouv_player(t_config *config, t_player *player, float POV)
{
	config->map_ok[(int)player->fposy / BLOCK_SIZE][(int)player->fposx / BLOCK_SIZE] = '0';
	mouv_player_x(config, player, (cos(POV) * player->vit));
	mouv_player_y(config, player, (sin(POV) * -player->vit));
	config->map_ok[(int)player->fposy / BLOCK_SIZE][(int)player->fposx / BLOCK_SIZE] = 'N';
}

void	ft_mouv(t_player *player, t_config *config)
{
	if (player->frontward)
		ft_mouv_player(config, player, config->POV);
	if (player->backward)
		ft_mouv_player(config, player, config->POV - M_PI);
	if (player->leftward)
		ft_mouv_player(config, player, config->POV - (M_PI / 2));
	if (player->rightward)
		ft_mouv_player(config, player, config->POV + (M_PI / 2));
}