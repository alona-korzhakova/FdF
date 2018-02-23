
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