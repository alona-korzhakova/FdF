
#include "fdf.h"

void	drawPixel(int x, int y, t_ptr *p)
{
	int i;
	t_point	*ptr;

	ptr = p->point;
	if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y)
	{
		i = x * p->bpp + y * p->size_line;
		p->addr[i] = p->color;
		p->addr[++i] = p->color >> 8;
		p->addr[++i] = p->color >> 16;
	}
}

void	connectDots(t_dot *d, t_ptr *p)
{
	int x;
	int y;
	int i;

	i = 1;
	d->dx = fabs(d->x1 - d->x0);
	d->dy = fabs(d->y1 - d->y0);
	d->sx = (d->x1 >= d->x0) ? 1 : -1;
	d->sy = (d->y1 >= d->y0) ? 1 : -1;
	if (d->dy <= d->dx)
	{
		d->d = (d->dy << 1) - d->dx;
		d->d1 = d->dy << 1;
		d->d2 = (d->dy - d->dx) << 1;
		x = d->x0 + d->sx;
		y = d->y0;
		while (i <= d->dx)
		{
			if (d->d > 0)
			{
				d->d += d->d2;
				y += d->sy;
			}
			else
				d->d += d->d1;
			drawPixel(x, y, p);
			i++;
			x += d->sx;
		}
	}
	else
	{
		d->d = (d->dx << 1) - d->dy;
		d->d1 = d->dx << 1;
		d->d2 = (d->dx - d->dy) << 1;
		x = d->x0;
		y = d->y0 + d->sy;
		while (i <= d->dy)
		{
			if (d->d > 0)
			{
				d->d += d->d2;
				x += d->sx;
			}
			else
				d->d += d->d1;
			drawPixel(x, y, p);
			i++;
			y += d->sy;
		}
	}
}

void	createImage(t_ptr *p)
{
	t_dot d;
	t_point *ptr;
	t_point *upperDot;
	int i;

	i = 0;
	ptr = p->point;
	upperDot = p->point;
	while (ptr)
	{
		i++;
		d.x0 = ptr->nx;
		d.y0 = ptr->ny;
		drawPixel(d.x0, d.y0, p);
		if (i > p->x)
		{	
			d.x1 = upperDot->nx;
			d.y1 = upperDot->ny;
			connectDots(&d, p);
			upperDot = upperDot->next;
		}
		if (ptr->next)
		{
			d.x1 = ptr->next->nx;
			d.y1 = ptr->next->ny;
			if (i % (int)p->x != 0)
				connectDots(&d, p);
		}
		ptr = ptr->next;
	}
}

void	drawImage(t_ptr *p)
{
	p->img = mlx_new_image(p->mlx, SIZE_X, SIZE_Y);
	p->addr = mlx_get_data_addr(p->img, &(p->bpp), &(p->size_line), &(p->end));
	p->bpp /= 8;
	createImage(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}