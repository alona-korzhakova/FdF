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
	t_point *ptr;

	ptr = p->point;
	while (ptr)
	{
		rotateMap(ptr, p);
		ptr = ptr->next;
	}
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
	p->z = 0;
	p->i = 0;
}

int 	handle_key(int keycode, t_ptr *p)
{
	if (keycode == 123)
		p->Lz += 0.2;
	if (keycode == 124)
		p->Lz -= 0.2;
	if (keycode == 126)
		p->Lx += 0.2;
	if (keycode == 125)
		p->Lx -= 0.2;
	if (keycode == 0)
		p->size_x -= 10;
	if (keycode == 2)
		p->size_x += 10;
	if (keycode == 13)
		p->size_y += 10;
	if (keycode == 1)
		p->size_y -= 10;
	if (keycode == 53)
	{
		ft_putstr("FdF has been closed.\n");
		exit(0);
	}
	if (keycode == 49)
		initializePtr(p);
	if (keycode == 35)
		p->perspective = p->perspective ? 0 : 1;
	if (keycode == 27)
		p->zoom += 5;
	if (keycode == 24)
		p->zoom -= 5;
	if (keycode == 36)
	{
		if (p->color == 0xFFFFFF)
			p->color = 0xCC0000;
		else if (p->color == 0xCC0000)
			p->color = 0xFF6600;
		else if (p->color == 0xFF6600)
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
	if (keycode == 121)
		p->z += 1;
	if (keycode == 116)
		p->z -= 1;
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
		rotateMap(temp, p);
		temp = temp->next;
	}
}

int	readMap(char *map, t_ptr *p)
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
		if (!*arr)
			return (0);		
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
	if (!p->i)
		return (0);
	p->point = begin;
	return (1);
}

int 	exitFdf(t_ptr *p)
{
	p = NULL;
	ft_putstr("FdF has been closed.\n");
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_ptr	p;

	if (argc == 2)
	{	
		p.point = NULL;
		p.y = 0;
		initializePtr(&p);
		system("leaks fdf");
		if (!readMap(argv[1], &p))
		{
			ft_putstr("error: invalid or empty file\n");
			return (-1);
		}
		centerMap(&p);		
		p.mlx = mlx_init();
		p.win = mlx_new_window(p.mlx, SIZE_X, SIZE_Y, "FdF");
		drawImage(&p);			
		mlx_hook(p.win, 2, 5, handle_key, &p);
		mlx_hook(p.win, 17, 5, exitFdf, &p);
		mlx_loop(p.mlx);
	}
	else
	{
		ft_putstr("usage: fdf input_file\n");
		return (-1);
	}
	return (0);
}
