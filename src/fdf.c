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
// 	if (keycode == 8)
// 	{
// 		printf("%f\n", param->point->x);
// 		printf("%f\n", param->point->y);
// 		param->point = param->point->next;
// 		printf("%f\n", param->point->x);
// 		printf("%f\n", param->point->y);
// 		param->point = param->point->next;
// 		printf("%f\n", param->point->x);
// 		printf("%f\n", param->point->y);
// 		mlx_pixel_put(param->mlx, param->win, param->point->x,
// 			param->point->y, 6750054);
// 		param->point = param->point->next;
// 		mlx_pixel_put(param->mlx, param->win, param->point->x,
// 			param->point->y, 6750054);
// 		param->point = param->point->next;
// 		mlx_pixel_put(param->mlx, param->win, param->point->x,
// 			param->point->y, 6750054);
// 		param->point = param->point->next;
// 	}
// 	return (0);
// }


void 	centerMap(t_ptr *p)
{
	t_point *temp;

	p->a = p->x / 2; /*the number of columns*/
	p->b = p->y / 2; /*the number of rows*/
	temp = p->point;
	while (temp)
	{
		temp->x = temp->x - p->a;
		temp->y = temp->y - p->b;
		temp = temp->next;
	}
}

void	readMap(char *map, t_ptr *p)
{	
	char *line;
	char **arr;
	t_point *begin;
	t_point *upper;

	p->fd = open(map, O_RDONLY);
	while (get_next_line(p->fd, &line) > 0)
	{
		p->i = 0;
		p->x = 0;
		arr = ft_strsplit(line, ' ');
		if (!p->y)
		{
			addPoint(&p->point, createPoint(p->x++, p->y, arr[p->i++]));
			begin = p->point;
			upper = begin;
		}
		while (arr[p->i])
			addPoint(&p->point, createPoint(p->x++, p->y, arr[p->i++]));
		ft_strdel(&line);
		ft_strdel(arr);
		p->y++;
	}
	p->point = begin;
}

void	initializePtr(t_ptr *p)
{
	p->zoom = 40;
	p->y = 0;
	p->Lz = 0.8;
	p->Lx = 1.1;
	p->point = NULL;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, SIZE_X, SIZE_Y, "FdF");
	p->color = 0xFFFFFF;
}

int		main(int argc, char **argv)
{
	t_ptr	p;

	if (argc == 2)
	{
		initializePtr(&p);
		readMap(argv[1], &p);
		centerMap(&p);
		rotateMap(&p);
		projectMap(&p);
		drawImage(&p);
		// while(p.point)
		// {
		// 	printf("%f\t", p.point->x);
		// 	printf("%f\n", p.point->nx);
		// 	p.point = p.point->next;
		// }
		// printf("%f\n", p.point->x);
		// p.mlx = mlx_init();
		// p.win = mlx_new_window(p.mlx, SIZE_X, SIZE_Y, "FdF");
		// mlx_new_image(p.mlx, p.win				
		// mlx_hook(p.win, 2, 5, handle_key, &p);
		mlx_loop(p.mlx);
		// while(newp)
		// {
		// 	printf("%f\t", point->z);
		// 	printf("%f\n", newp->z);
		// 	point = point->next;
		// 	newp = newp->next;
		// }
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
