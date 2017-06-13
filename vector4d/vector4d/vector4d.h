#pragma once

#include <math.h>

#pragma pack(push, 4)

typedef struct _vector4d {

	float x, y, z, w;

} vector4d;

#pragma pack(pop)

vector4d* vectorCreate(vector4d* a);
vector4d* vectorCreate(vector4d* a, float x, float y, float z);
vector4d* vectorCreate(vector4d* a, vector4d* b);
vector4d* vectorCreate(vector4d* a, vector4d* b, vector4d* c);
vector4d* vectorCreate(vector4d* a, vector4d* b);
vector4d* vectorAdd(vector4d* a, vector4d* b);
float vectorDotProduct(vector4d* a, vector4d* b);
vector4d* vectorCrossProduct(vector4d* a, vector4d* b, vector4d* c);
vector4d* vectorMultiply(vector4d* a, float f);
vector4d* vectorMultiply(vector4d* a, vector4d* b, vector4d* c, float f);
float vectorGetLenghtSquared(vector4d* a);
float vectorGetLenght(vector4d* a);
vector4d* vectorGetMiddle(vector4d* a, vector4d* b, vector4d* c);
float vectorGetCos(vector4d* a, vector4d* b);
vector4d* vectorNormalize(vector4d* a);
vector4d* vectorNegate(vector4d *a);
