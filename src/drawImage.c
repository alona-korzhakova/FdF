
#include "fdf.h"

void	drawPixel(int x, int y, t_ptr *p)
{
	int i;
	t_point	*ptr;

	ptr = p->point;
		// if (ptr->nx >= 0 && ptr->nx < SIZE_X && ptr->ny >= 0 && ptr->ny < SIZE_Y)
		// {
	i = x * p->bpp + y * p->size_line;
	p->addr[i] = p->color;
	p->addr[++i] = p->color;
	p->addr[++i] = p->color;
		// }
	ptr = ptr->next;
}

void	connectDots(t_dot *d, t_ptr *p)
{
	int x;
	int y;

	d->dx = ABS(d->x1 - d->x0);
	d->dy = ABS(d->y1 - d->y0);
	d->error = 0;
	d->derror = d->dy;
	y = d->y0;
	x = d->x0;
	if ((d->y1 - d->y0) > 0)
		d->dir = 1;
	else
		d->dir = -1;
	while (x < d->x1)
	{
		drawPixel(x, y, p);
		d->error += d->derror;
		if ((d->error << 1) >= d->dx)
		{
			y += d->dir;
			d->error -= d->dx; 
		}
		x++;
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
	upperDot = ptr;
	printf("%f\n", p->x);
	while (ptr->next)
	{
		i++;	
		d.x0 = (int)ptr->nx;
		d.y0 = (int)ptr->ny;
		if (i > p->x)
		{	
			d.x1 = (int)upperDot->nx;
			d.y1 = (int)upperDot->ny;
			connectDots(&d, p);
			upperDot = upperDot->next;
		}
		ptr = ptr->next;
		d.x1 = (int)ptr->nx;
		d.y1 = (int)ptr->ny;
		if (i % (int)p->x != 0)
			connectDots(&d, p);
		else
			drawPixel(d.x0, d.y0, p);

	}
	drawPixel(d.x1, d.y1, p);
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