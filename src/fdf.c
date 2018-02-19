/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:23:41 by akorzhak          #+#    #+#             */
/*   Updated: 2018/02/18 15:23:44 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int 	handle_key(int keycode, t_ptr *param)
// {
// 	static int x = 0;
// 	static int y = 0;

// 	if (keycode == 1)
// 	{
// 		mlx_pixel_put(param->mlx, param->win, x++, y++, 6750054);
// 		mlx_pixel_put(param->mlx, param->win, x++, y++, 6750054);
// 		mlx_pixel_put(param->mlx, param->win, x++, y++, 6750054);
// 		mlx_pixel_put(param->mlx, param->win, x++, y++, 6750054);
// 	}
// 	return (0);
// }

	// int fd;
	// char *line;
	// char **arr;
	// t_point point;
	// int x = 0;
	// int y = 0;
	// int i = 0;

	// fd = open(argv[1], O_RDONLY);
	// while (get_next_line(fd, &line) > 0)
	// {
	// 	arr = ft_strsplit(line, ' ');
	// 	while (arr[i])
	// 	{
	// 		point.x = x++;
	// 		point.y = y;
	// 		point.z = ft_atoi(arr[i++]);
	// 	}
	// 	ft_strdel(&line);
	// 	ft_strdel(arr);
	// 	y++;
	// }

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	char **arr;
	t_point *point = NULL;
	int x;
	int y = 0;
	int i = 0;
	int a;
	int b;

	// if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
	// 	return (0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			x = 0;
			arr = ft_strsplit(line, ' ');
			while (arr[i])
				ft_pointadd(&point, ft_pointcreate(x++, y, arr[i++]));
			ft_strdel(&line);
			ft_strdel(arr);
			y++;
		}
		a = x; //the number of columns
		b = y; //the number of rows
		while (point->prev)
			point = point->prev;
		while (point)
		{
			printf("%d\n", point->z);
			point = point->next;
		}
	}
	return (0);
}

	// t_ptr	ptr;

	// ptr.mlx = mlx_init();
	// ptr.win = mlx_new_window(ptr.mlx, 500, 500, "FdF");
	// mlx_hook(ptr.win, 2, 5, handle_key, &ptr);
	// mlx_loop(ptr.mlx);
