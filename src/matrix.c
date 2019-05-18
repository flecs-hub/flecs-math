#include "include/math.h"
#include <math.h>

#define MATRIX_GET(matrix, x, y) ((*matrix)[x][y])

void ecs_mat3x3_add_rotation(
    EcsMat3x3 *matrix,
    float rad)
{
    float c = cos(rad);
    float s = sin(rad);

    float m0_0 = matrix->data[0][0];
    float m0_1 = matrix->data[0][1];

    float m1_0 = matrix->data[1][0];
    float m1_1 = matrix->data[1][1];

    float m2_0 = matrix->data[2][0];
    float m2_1 = matrix->data[2][1];

    matrix->data[0][0] = c * m0_0 + s * m0_1;
    matrix->data[1][0] = c * m1_0 + s * m1_1;
    matrix->data[2][0] = c * m2_0 + s * m2_1;

    matrix->data[0][1] = -s * m0_0 + c * m0_1;
    matrix->data[1][1] = -s * m1_0 + c * m1_1;
    matrix->data[2][1] = -s * m2_0 + c * m2_1;
}

void ecs_mat3x3_add_translation(
    EcsMat3x3 *matrix,
    EcsVec2 *translation)
{
    float m0_0 = matrix->data[0][0];
    float m0_1 = matrix->data[0][1];
    float m0_2 = matrix->data[0][2];

    float m1_0 = matrix->data[1][0];
    float m1_1 = matrix->data[1][1];
    float m1_2 = matrix->data[1][2];

    matrix->data[0][2] = m0_0 * translation->x + m0_1 * translation->y + m0_2;
    matrix->data[1][2] = m1_0 * translation->x + m1_1 * translation->y + m1_2;
}

void ecs_mat3x3_add_scale(
    EcsMat3x3 *matrix,
    EcsVec2 *scale)
{
    matrix->data[0][0] *= scale->x;
    matrix->data[1][1] *= scale->y;
}

void ecs_mat3x3_transform(
    EcsMat3x3 *matrix,
    EcsVec2 *src,
    EcsVec2 *dest,
    size_t size)
{
    for (size_t i = 0; i < size; i++) {
        float x = src[i].x;
        float y = src[i].y;
        dest[i].x = matrix->data[0][0] * x +
                    matrix->data[0][1] * y +
                    matrix->data[0][2];
        dest[i].y = matrix->data[1][0] * x +
                    matrix->data[1][1] * y +
                    matrix->data[1][2];
    }
}

void ecs_mat3x3_transform_int(
    EcsMat3x3 *matrix,
    EcsVec2Int *src,
    EcsVec2Int *dest,
    size_t size)
{
    for (size_t i = 0; i < size; i++) {
        float x = src[i].x;
        float y = src[i].y;

        dest[i].x = matrix->data[0][0] * x +
                    matrix->data[0][1] * y +
                    matrix->data[0][2];
        dest[i].y = matrix->data[1][0] * x +
                    matrix->data[1][1] * y +
                    matrix->data[1][2];
    }
}

void ecs_mat3x3_mul(
    EcsMat3x3 *m1,
    EcsMat3x3 *m2,
    EcsMat3x3 *dest)
{
    int i, j, k; 
    
    for (i = 0; i < 3; i++) { 
        for (j = 0; j < 3; j++) { 
            dest->data[i][j] = 0; 
            for (k = 0; k < 3; k++) {
                dest->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        } 
    } 
}