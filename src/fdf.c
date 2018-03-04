/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:23:41 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:33 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_ptr(t_ptr *p)
{
	p->zoom = 61;
	p->lz = 0.8;
	p->lx = 1.1;
	p->color = 0xFFFFFF;
	p->size_x = SIZE_X / 2;
	p->size_y = SIZE_Y / 2;
	p->perspective = 0;
	p->z = 0;
	p->i = 0;
	p->minz = 0;
}

int		main(int argc, char **argv)
{
	t_ptr	p;

	if (argc == 2)
	{
		p.y = 0;
		p.point = NULL;
		initialize_ptr(&p);
		if (!read_map(argv[1], &p))
			return (ft_error());
		center_map(&p);
		p.mlx = mlx_init();
		p.win = mlx_new_window(p.mlx, SIZE_X, SIZE_Y, "FdF");
		draw_image(&p);
		mlx_hook(p.win, 2, 5, handle_key, &p);
		mlx_hook(p.win, 17, 5, exit_fdf, &p);
		mlx_loop(p.mlx);
	}
	else
		return (ft_usage());
	return (0);
}
