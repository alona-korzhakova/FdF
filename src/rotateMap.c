
#include "fdf.h"

t_point 	*rotateMap(t_ptr *p)
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
	return (p);
}