#include "mini_rt.h"

t_camera    make_camera(t_object camera, t_point forward)
{
    t_camera    cam;
    double      aspect_ratio;

    aspect_ratio = WINDOW_WIDTH/WINDOW_HEIGHT;
    cam.eye = camera.pos;
    cam.forward = unit_vector(forward);
    cam.up = unit_vector(vector_cross(forward, camera.norm));
    cam.right = vector_cross(cam.up, cam.forward);
    cam.h = tan(M_PI * 0.5 * camera.fov / 180);
    cam.w = cam.h * aspect_ratio;

    return (cam);
}

//     vector = forward + (u * cam.w) * up_vector + (v * cam.h) * right_vector;
//     u and v are cood
t_ray   make_ray(t_camera cam, double u, double v){
    t_point vector;
    
    vector = vector_add(vector_add(cam.forward, vector_multiply(cam.up, u * cam.w)), vector_multiply(cam.right, v * cam.h));
    return create_ray(cam.eye, unit_vector(vector));
}

t_ray	camera_render(t_main *data)
{
    t_camera       cam;
    t_ray          ray_cood;
    t_point        forward;

    forward = create_vector(0,0,-1);
    cam = make_camera(data->camera, forward);

    int i = 0;
    int j = 0;
    while (j < WINDOW_HEIGHT){
        i = 0;
        while (i < WINDOW_WIDTH){
            ray_cood = make_ray(cam, (2.0 * i / WINDOW_WIDTH) - 1.0, (-2.0 * j / WINDOW_HEIGHT) + 1.0);
            i++;
        }
        j++;
    }
    return (ray_cood);
}