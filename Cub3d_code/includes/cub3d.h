#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../libft/include/libft.h"
# include "../../libft/include/get_next_line.h"
# include "../../libft/include/ft_printf.h"
# include "../../libmlx/mlx.h"

# define ESC 	65307
# define A		113
# define S		115
# define D		100
# define W		122
# define MAJ	65505

typedef	struct		s_config
{
	enum e_boolean	fsave;
	int				x;
	int				y;
	char			*textno;
	char			*textso;
	char			*textwe;
	char			*textea;
	char			*sprite;
	int				r_floor;
	int				g_floor;
	int				b_floor;
	int				r_ceiling;
	int				g_ceiling;
	int				b_ceiling;
	char			*map;
	char			**map_ok;
}					t_config;

typedef	struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
}					t_window;

typedef struct		s_player
{
	int				posx;
	int				posy;
}					t_player;

typedef	struct		s_cub3d
{
	t_config		config;
	t_window		win;
	t_player		player;
}					t_cub3d;

//rgb
void				ft_rgb_ceiling(t_config *config, char *line);
void				ft_rgb_floor(t_config *config, char *line);
void				ft_rgb(char *line, t_config *config);

//config
void				ft_init_config(t_config *config);
void				resolution(char *line, t_config *config);
int					ft_read_line(int fd, char *line, t_config *config);
void				ft_parse3d(char *line, t_config *config);

//player
int					chr_player(char **map_ok, int y, int x);
int					find_player(char **map_ok, t_cub3d *cub3d);

//window
int					window(t_cub3d cub3d);
int					ft_parse_key(int key, t_cub3d *cub3d);
int					ft_release(int key, t_cub3d *cub3d);
void				ft_mouv(int key, t_player *player);
void				ft_release_mouv(int key, t_player *player);
int					ft_exit(t_window *win);

//check_map
int					zero_verif(char **map_ok);
int					verif_map(char **map_ok);
char				**ft_parse_map(t_cub3d *cub3d);

#endif
