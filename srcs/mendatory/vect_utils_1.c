# include "vector.h"

t_point	create_vector(double x, double y, double z)
{
	t_point	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_point	vector_add(t_point a, t_point b)
{
	t_point	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_point	vector_subtract(t_point a, t_point b)
{
	t_point	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_point	vector_multiply(t_point a, double multiplier)
{
	t_point	result;

	result.x = a.x * multiplier;
	result.y = a.y * multiplier;
	result.z = a.z * multiplier;
	return (result);
}

t_point	vector_divide(t_point a, double divisor)
{   
	return (vector_multiply(a, (1 / divisor)));
}
