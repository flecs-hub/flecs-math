#ifndef FLECS_MATRIX_H
#define FLECS_MATRIX_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsMat3x3 {
    float data[3][3];
} EcsMat3x3;

#define ECS_MAT3X3_IDENTITY (EcsMat3x3){{{1,0,0},{0,1,0},{0,0,0}}}

FLECS_MATH_EXPORT
void ecs_mat3x3_add_rotation(
    EcsMat3x3 *matrix,
    float rad);

FLECS_MATH_EXPORT
void ecs_mat3x3_addn_rotation(
    EcsMat3x3 *matrix,
    float *rad,
    int count);

FLECS_MATH_EXPORT
void ecs_mat3x3_add_translation(
    EcsMat3x3 *matrix,
    EcsVec2 *translation);

FLECS_MATH_EXPORT
void ecs_mat3x3_addn_translation(
    EcsMat3x3 *matrix,
    EcsVec2 *translation,
    int count);

FLECS_MATH_EXPORT
void ecs_mat3x3_add_scale(
    EcsMat3x3 *matrix,
    EcsVec2 *scale);

FLECS_MATH_EXPORT
void ecs_mat3x3_transform(
    EcsMat3x3 *matrix,
    EcsVec2 *src,
    EcsVec2 *dest,
    size_t size);

FLECS_MATH_EXPORT
void ecs_mat3x3_transform_int(
    EcsMat3x3 *matrix,
    EcsVec2Int *src,
    EcsVec2Int *dest,
    size_t size);

FLECS_MATH_EXPORT
void ecs_mat3x3_mul(
    EcsMat3x3 *m1,
    EcsMat3x3 *m2,
    EcsMat3x3 *dest);

#ifdef __cplusplus
}
#endif

#endif
