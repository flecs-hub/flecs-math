#include <flecs_math.h>

int ecs_clamp(
    float *v, 
    float min, 
    float max)
{
    int result; 
    if (*v < min) {*v = min; result = -1;}
    else if (*v > max) {*v = max; result = 1;}
    else result = 0;
    return result;
}

float ecs_randf(float max) {
    return (float)rand() / (float)RAND_MAX * max;
}

float ecs_random_range(
    float min,
    float max)
{
    float result = (float)rand() / (float)RAND_MAX;
    return result * (max - min) + min;
}