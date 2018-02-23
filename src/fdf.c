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

void	displayMap(t_ptr *p)
{
	rotateMap(p);
	projectMap(p);
	drawImage(p);
}

void	initializePtr(t_ptr *p)
{
	p->zoom = 61;
	p->Lz = 0.8;
	p->Lx = 1.1;
	p->color = 0xFFFFFF;
	p->size_x = SIZE_X / 2;
	p->size_y = SIZE_Y / 2;
	p->perspective = 0;
}

int 	handle_key(int keycode, t_ptr *p)
{
	t_point *ptr;

	ptr = p->point;
	if (keycode == 83)
		p->Lz += 0.1;
	if (keycode == 84)
		p->Lz -= 0.1;
	if (keycode == 86)
		p->Lx += 0.1;
	if (keycode == 87)
		p->Lx -= 0.1;
	if (keycode == 123)
		p->size_x -= 5;
	if (keycode == 124)
		p->size_x += 5;
	if (keycode == 126)
		p->size_y += 5;
	if (keycode == 125)
		p->size_y -= 5;
	if (keycode == 53)
	{
		write(1, "Fdf has been closed.\n", 21);
		exit(0);
	}
	if (keycode == 49)
		initializePtr(p);
	if (keycode == 35)
		p->perspective = p->perspective ? 0 : 1;
	if (keycode == 115)
		p->zoom += 5;
	if (keycode == 119)
		p->zoom -= 5;
	if (keycode == 36)
	{
		if (p->color == 0xFFFFFF)
			p->color = 0xFF0000;
		else if (p->color == 0xFF0000)
			p->color = 0xFF8000;
		else if (p->color == 0xFF8000)
			p->color = 0xFFFF00;
		else if (p->color == 0xFFFF00)
			p->color = 0xBFFF00;
		else if (p->color == 0xBFFF00)
			p->color = 0x40FF00;
		else if (p->color == 0x40FF00)
			p->color = 0x4DD2FF;
		else if (p->color == 0x4DD2FF)
			p->color = 0x4D4DFF;
		else if (p->color == 0x4D4DFF)
			p->color = 0x7A00CC;
		else if (p->color == 0x7A00CC)
			p->color = 0xFF4DD2;
		else
			p->color = 0xFFFFFF;
	}
	displayMap(p);
	return (0);
}


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

int 	exitFdf(t_ptr *p)
{
	p = NULL;
	write(1, "Fdf has been closed.\n", 21);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_ptr	p;

	if (argc == 2)
	{
		p.mlx = mlx_init();
		p.win = mlx_new_window(p.mlx, SIZE_X, SIZE_Y, "FdF");
		p.point = NULL;
		p.y = 0;
		initializePtr(&p);
		readMap(argv[1], &p);
		centerMap(&p);
		displayMap(&p);			
		mlx_hook(p.win, 2, 5, handle_key, &p);
		mlx_hook(p.win, 17, 5, exitFdf, &p);
		mlx_loop(p.mlx);
	}
	return (0);
}
