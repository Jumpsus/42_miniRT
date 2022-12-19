#include "mini_rt.h"

/* https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-plane-and-ray-disk-intersection */
double  hit_plane(t_object plane, t_ray ray)
{
    double  denom;
    double  t;

    denom = vector_dot(plane.norm, ray.dir);
    if (fabs(denom) > 1e-6){
        t = vector_dot(vector_subtract(plane.pos, ray.orig), plane.norm) / denom;
        return (t);
    }
    return (-1);
}
