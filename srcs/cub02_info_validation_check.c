/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub01_info_validation_check.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:24:35 by keulee            #+#    #+#             */
/*   Updated: 2021/05/18 15:24:43 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	file_validation_check(int ac, char **av, t_game *game)
{
	game->save = OFF;
	if (ac < 2 || ac > 3)
		error_msg("ERROR : Argument Not Enough or Too Many");
	if ((ac == 2 || ac == 3) && ft_strstr_cub(av[1], ".cub") != 1)
		error_msg("ERROR : Wrong .cub Extension");
	if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		error_msg("ERROR : --save argument not corrected");
	else if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
		game->save = ON;
}

void	info_validation_check(t_game *game)
{
	if (game->info.mark == -1)
		error_msg("ERROR: Info element(s) Missing or Info not well aligned");
	if (!game->info.win_width || !game->info.win_height)
		error_msg("ERROR: Resolution Info missing");
	resolution_max_min_check(game);
	if (game->info.floor_color == -1 || game->info.ceiling_color == -1)
		error_msg("ERROR: Color Info missing");
	if (!game->info.tex_path[TEX_NORTH] || !game->info.tex_path[TEX_SOUTH]
		|| !game->info.tex_path[TEX_WEST] || !game->info.tex_path[TEX_EAST]
		|| !game->info.tex_path[TEX_SPRITE])
		error_msg("ERROR: Texture Info missing");
}

void	resolution_max_min_check(t_game *game)
{
	if (game->info.win_width > 1920)
		game->info.win_width = 1920;
	if (game->info.win_width < 640)
		game->info.win_width = 640;
	if (game->info.win_height > 1080)
		game->info.win_height = 1080;
	if (game->info.win_height < 360)
		game->info.win_height = 360;
}
/*
** linux_resolution_max_min_check(game,
** &game->info.win_width, &game->info.win_height);
** after resolution_max_min_check(game) in function info_validation_check
** after line 22
** void    linux_resolution_max_min_check(t_game *game, int *w, int *h)
** {
**     int r_width;
**     int r_height;
**
**     r_width = 0;
**     r_height = 0;
**     mlx_get_screen_size(game->mlx, &w, &h);
**     if (*w > r_width)
**         *w = r_width;
**     if (*h < r_height)
**         *h = r_height;
** }
*/
