/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bmp_screenshot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:30:16 by keulee            #+#    #+#             */
/*   Updated: 2021/05/18 15:30:17 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_bmp_screenshot(t_game *game)
{
	int	file_size;
	int	fd;

	ray_processing(game);
	sprite_ray_processing(game);
	file_size = 14 + 40 + 3 * game->info.win_width * game->info.win_height;
	fd = open(BMP_NAME, O_RDWR | O_TRUNC | O_CREAT, 00755);
	if (fd < 0)
		error_msg("ERROR : Bmp file create failed");
	printf("Creating Bmp file...\n");
	set_bmp_header(game, file_size, fd);
	write_bmp_data(game, fd);
	printf("Bmp file saved with a file name : %s", BMP_NAME);
}

void	set_bmp_header(t_game *game, int file_size, int fd)
{
	unsigned char	bmp_header[54];

	ft_bzero(bmp_header, 54);
	bmp_header[0] = (unsigned char)'B';
	bmp_header[1] = (unsigned char)'M';
	int_to_char(bmp_header + 2, file_size);
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	int_to_char(bmp_header + 18, game->info.win_width);
	int_to_char(bmp_header + 22, game->info.win_height);
	bmp_header[26] = (unsigned char)1;
	bmp_header[28] = (unsigned char)24;
	write(fd, bmp_header, 54);
}

void	int_to_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

void	write_bmp_data(t_game *game, int fd)
{
	const unsigned char zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					pad;

	i = game->info.win_height;
	pad = (4 - (game->info.win_width * 3) % 4) % 4;
	while (i >= 0)
	{
		j = 0;
		while (j < game->info.win_width)
		{
			write(fd, &game->buf[i][j], 3);
			if (pad > 0)
				write(fd, &zero, pad);
			j++;
		}
		i--;
	}
}
