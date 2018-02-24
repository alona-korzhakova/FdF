
#include "fdf.h"

void	projectMap(t_point *ptr, t_ptr *p)
{
	double temp;

	if (p->perspective)
	{
		temp = SIZE_Y / (p->zoom + ptr->nz);
		ptr->nx = ptr->nx * temp + p->size_x;
		ptr->ny = ptr->ny * temp + p->size_y;
	}
	else
	{
		temp = SIZE_Y / (p->zoom);
		ptr->nx = ptr->nx * temp + p->size_x;
		ptr->ny = ptr->ny * temp + p->size_y - ptr->nz;
	}
}