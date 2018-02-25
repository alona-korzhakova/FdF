#include "fdf.h"

void 	rotateMap(t_ptr *p)
{
	t_point *ptr;
	double y;

	ptr = p->point;
	while (ptr)
	{
		ptr->nx = ptr->x * cos(p->Lz) - ptr->y * sin(p->Lz);
		ptr->ny = ptr->x * sin(p->Lz) + ptr->y * cos(p->Lz);

		y = ptr->ny * cos(p->Lx) + ptr->z * sin(p->Lx);
		ptr->nz = -(ptr->ny) * sin(p->Lx) + ptr->z * cos(p->Lx);
		ptr->ny = y;
		ptr = ptr->next;
	}
}
#include "fdf.h"

void	projectMap(t_ptr *p)
{
	t_point *ptr;
	double temp;

	ptr = p->point;
	if (p->perspective)
	{
		while (ptr)
		{
			temp = SIZE_Y / (p->zoom + ptr->nz);
			ptr->nx = ptr->nx * temp + p->size_x;
			ptr->ny = ptr->ny * temp + p->size_y;
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			temp = SIZE_Y / (p->zoom);
			ptr->nx = ptr->nx * temp + p->size_x;
			ptr->ny = ptr->ny * temp + p->size_y - ptr->nz;
			ptr = ptr->next;
		}
	}
}

	while (p->point)
	{
		temp = p->point;
		p->point = p->point->next;
		free(temp);
	}