
#include "fdf.h"

void	projectMap(t_ptr *p)
{
	t_point *ptr;
	double temp;

	ptr = p->point;
	while (ptr)
	{
		temp = SIZE_Y / (p->zoom + ptr->nz);
		ptr->nx = ptr->nx * temp + SIZE_X / 2;
		ptr->ny = ptr->ny * temp + SIZE_Y / 2;
		ptr = ptr->next;
	}
}