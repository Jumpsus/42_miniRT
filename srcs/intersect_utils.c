#include "mini_rt.h"

double	solve_quadratic_minus(double a, double b, double c)
{
	double	discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (-DBL_MAX);
	return ((-b - sqrt(discriminant)) / (2 * a));
}

double	solve_quadratic_plus(double a, double b, double c)
{
	double	discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (-DBL_MAX);
	return ((-b + sqrt(discriminant)) / (2 * a));
}
