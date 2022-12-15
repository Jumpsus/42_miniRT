#include "mini_rt.h"

/* https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-plane-and-ray-disk-intersection */
double  plane_intersect(t_point p0, t_point n, t_ray ray)
{
    double  denom;
    double  t;

    denom = vector_dot(n, ray.dir);
    if (denom > 1e-6){
        t = vector_dot(vector_subtract(p0, ray.orig), n) / denom;
        return (t);
    }
    return (-1);
}