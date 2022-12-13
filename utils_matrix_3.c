#include "mini_rt.h"

/* source: https://en.wikipedia.org/wiki/Rotation_matrix */
t_point  rotate_vector(t_point v, double x_rot, double y_rot, double z_rot)
{
    t_point result;

    result = create_vector(v.x, v.y * cos(x_rot) - v.z * sin(x_rot), v.y * sin(x_rot) + v.z * cos(x_rot));
    result = create_vector(v.x * cos(y_rot) + v.z * sin(y_rot), v.y, v.z * cos(y_rot) - v.x * sin(y_rot));
    result = create_vector(v.x * cos(z_rot) - v.y * sin(z_rot), v.x * sin(z_rot) + v.y * cos(z_rot), v.z);

    return (result);
}