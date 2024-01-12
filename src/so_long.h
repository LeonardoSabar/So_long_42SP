/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:29:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/12 12:39:38 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>

# define WIDTH 1280
# define HEIGHT 720
# define FALSE 1
# define TRUE 0
# define MOVE 10

# define DIR_W keydata.key == MLX_KEY_W
# define DIR_S keydata.key == MLX_KEY_S
# define DIR_A keydata.key == MLX_KEY_A
# define DIR_D keydata.key == MLX_KEY_D

# define DIR_UP keydata.key == MLX_KEY_UP
# define DIR_DOWN keydata.key == MLX_KEY_DOWN
# define DIR_LEFT keydata.key == MLX_KEY_LEFT
# define DIR_RIGHT keydata.key == MLX_KEY_RIGHT

typedef struct s_main
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture0;
	mlx_texture_t	*texture1;
	mlx_texture_t	*texture2;
	mlx_texture_t	*texture3;
	mlx_texture_t	*texture4;
	int				x;
	int				y;
}	t_main;

typedef struct s_charactere
{
	mlx_image_t		*img;
	mlx_texture_t	*incial;
	mlx_texture_t	*walk_left;
	mlx_texture_t	*walk_right;
	mlx_texture_t	*walk_up;
	mlx_texture_t	*walk_down;
}	t_charactere;

typedef struct s_map
{
	mlx_image_t		*img;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
	mlx_texture_t	*enemy;
	t_charactere	*charactere;
}	t_map;



void	movement(mlx_key_data_t keydata, void* param);
int32_t	main(void);

#endif
