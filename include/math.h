#ifndef REFLECS_MATH_H
#define REFLECS_MATH_H

/* This generated file contains includes for project dependencies */
#include "bake_config.h"

#include "vector.h"
#include "matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

REFLECS_MATH_EXPORT
int ecs_clamp(
    float *v, 
    float min, 
    float max);

REFLECS_MATH_EXPORT
float ecs_random_range(
    float min,
    float max);

#ifdef __cplusplus
}
#endif

#endif
