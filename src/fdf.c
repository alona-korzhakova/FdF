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

int 	handle_key(int keycode, t_ptr *param)
{
	if (keycode == 8)
	{
		printf("%f\n", param->point->x);
		printf("%f\n", param->point->y);
		param->point = param->point->next;
		printf("%f\n", param->point->x);
		printf("%f\n", param->point->y);
		param->point = param->point->next;
		printf("%f\n", param->point->x);
		printf("%f\n", param->point->y);
		mlx_pixel_put(param->mlx, param->win, param->point->x,
			param->point->y, 6750054);
		param->point = param->point->next;
		mlx_pixel_put(param->mlx, param->win, param->point->x,
			param->point->y, 6750054);
		param->point = param->point->next;
		mlx_pixel_put(param->mlx, param->win, param->point->x,
			param->point->y, 6750054);
		param->point = param->point->next;
	}
	return (0);
}


t_point 	*centerMap(t_point *point, t_ptr *p)
{
	t_point *begin;

	p->a = p->x / 2; /*the number of columns*/
	p->b = p->y / 2; /*the number of rows*/
	begin = point;
	while (point)
	{
		point->x = point->x - p->a + SIZE_X / 2;
		point->y = point->y - p->b + SIZE_Y / 2;
		point = point->next;
	}
	return (begin);
}

t_point 	*readMap(char *map, t_ptr *p)
{	
	char *line;
	char **arr;
	t_point *point = NULL;
	t_point *begin;

	p->fd = open(map, O_RDONLY);
	while (get_next_line(p->fd, &line) > 0)
	{
		p->i = 0;
		p->x = 0;
		arr = ft_strsplit(line, ' ');
		if (!p->y)
		{
			addPoint(&point, createPoint(p->x++, p->y, arr[p->i++]));
			begin = point;
		}
		while (arr[p->i])
			addPoint(&point, createPoint(p->x++, p->y, arr[p->i++]));
		ft_strdel(&line);
		ft_strdel(arr);
		p->y++;
	}
	return (begin);	
}

int		main(int argc, char **argv)
{
	t_point *point;
	t_point	*rot;
	t_ptr	p;

	if (argc == 2)
	{
		p.y = 0;
		point = readMap(argv[1], &p);
		point = centerMap(point, &p);
		rot = rotateMap(point, rot, &p);
		p.point = point;
		// printf("%f\n", p.point->x);
		p.mlx = mlx_init();
		p.win = mlx_new_window(p.mlx, SIZE_X, SIZE_Y, "FdF");
		mlx_new_image(p.m				
		mlx_hook(p.win, 2, 5, handle_key, &p);
		mlx_loop(p.mlx);

		// printf("fd: %d\n", param.ptr.fd);
		// printf("x: %f\n", param.ptr.x);
		// printf("x: %f\n", param.point->x);


	// printf("a: %d\n", p.a);
	// printf("b: %d\n", p.b);
	
		
		// while (point)
		// {
		// 	printf("%f\n", point->x);
		// 	point = point->next;
		// }
	}	
	return (0);
}

	// t_ptr	ptr;

	// 
	// ptr.win = mlx_new_window(ptr.mlx, 500, 500, "FdF");
	// mlx_hook(ptr.win, 2, 5, handle_key, &ptr);
	// mlx_loop(ptr.mlx);
