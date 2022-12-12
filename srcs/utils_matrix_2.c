#include "mini_rt.h"

double  matrix_square_length(t_point a)
{
    return (a.x * a.x + a.y * a.y + a.z * a.z);
}

double  matrix_length(t_point a)
{
    return (sqrt(matrix_square_length(a)));
}

double  matrix_dot(t_point a, t_point b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point  matrix_cross(t_point a, t_point b)
{
    t_point result;

    result.x = (a.y * b.z) - (a.z * b.y);
    result.y = (a.z * b.x) - (a.x * b.z);
    result.z = (a.x * b.y) - (a.y * b.x);

    return (result);
}

t_point  unit_vector(t_point a)
{
    t_point result;

    result.x = a.x / matrix_length(a);
    result.y = a.y / matrix_length(a);
    result.z = a.z / matrix_length(a);

    return (result);
}