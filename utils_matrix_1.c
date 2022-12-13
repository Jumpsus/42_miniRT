#include "mini_rt.h"

t_point     create_vector(double x, double y, double z)
{
    t_point result;

    result.x = x;
    result.y = y;
    result.z = z;

    return (result);
}

t_point    vector_add(t_point a, t_point b)
{
    t_point result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    
    return (result);
}

t_point    vector_subtract(t_point a, t_point b)
{
    t_point result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    
    return (result);
}

t_point    vector_multiply(t_point a, double multiplier)
{
    t_point result;

    result.x = a.x * multiplier;
    result.y = a.y * multiplier;
    result.z = a.z * multiplier;
    
    return (result);
}

t_point    vector_divide(t_point a, double divisor)
{   
    return (vector_multiply(a, (1 / divisor)));
}

// int main() {
//     t_point p1;
//     t_point p2;
//     t_point plus;
//     t_point minus;
//     t_point multiply;
//     t_point divider;

//     p1.x = 1;
//     p1.y = 2;
//     p1.z = 3;

//     p2.x = 5;
//     p2.y = 5;
//     p2.z = 5;

//     plus = vector_add(p1, p2);
//     minus = vector_subtract(p1, p2);
//     multiply = vector_multiply(p1, 10);
//     divider = vector_divide(p1, 10);
//     printf("%f %f %f \n", plus.x, plus.y, plus.z);
//     printf("%f %f %f \n", minus.x, minus.y, minus.z);
//     printf("%f %f %f \n", multiply.x, multiply.y, multiply.z);
//     printf("%f %f %f \n", divider.x, divider.y, divider.z);
// }
