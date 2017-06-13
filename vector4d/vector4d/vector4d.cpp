// Vector4d (c) 2017 Alex Lisnyak
//
// Input fortmat: destination, source_1, ..., source_n

#include "vector4d.h"

vector4d* vectorCreate(vector4d* a) {

	a->x = .0f;
	a->y = .0f;
	a->z = .0f;
	a->w = .0f;

	return a;
}

vector4d* vectorCreate(vector4d* a, float x, float y, float z) {

	a->x = x;
	a->y = y;
	a->z = z;
	a->w = .0f;

	return a;
}

vector4d* vectorCreate(vector4d* a, vector4d* b) {

	a->x = b->x;
	a->y = b->y;
	a->z = b->z;
	a->w = .0f;

	return a;
}

vector4d* vectorCreate(vector4d* a, vector4d* b, vector4d* c) {

	a->x = c->x - b->x;
	a->y = c->y - b->y;
	a->z = c->z - b->z;
	a->w = .0f;

	return a;
}

vector4d* vectorAdd(vector4d* a, vector4d* b) {

	a->x += b->x;
	a->y += b->y;
	a->z += b->z;

	return a;
}

float vectorDotProduct(vector4d* a, vector4d* b) {

	return a->x * b->x + a->y * b->y + a->z * b->z;
}

vector4d* vectorCrossProduct(vector4d* a, vector4d* b, vector4d* c) {

	a->x = b->y * c->z - b->z * c->y;
	a->y = b->z * c->x - b->x * c->z;
	a->z = b->x * c->y - b->y * c->x;
	a->w = .0f;

	return a;
}

vector4d* vectorMultiply(vector4d* a, float f) {

	a->x *= f;
	a->y *= f;
	a->z *= f;

	return a;
}

vector4d* vectorMultiply(vector4d* a, vector4d* b, vector4d* c, float f) {

	a->x = b->x * c->x * f;
	a->y = b->y * c->y * f;
	a->z = b->z * c->z * f;
	a->w = .0f;

	return a;
}

float vectorGetLenghtSquared(vector4d* a) {

	return a->x * a->x + a->y * a->y + a->z * a->z;
}

float vectorGetLenght(vector4d* a) {

	return sqrtf(vectorGetLenghtSquared(a));
}

vector4d* vectorGetMiddle(vector4d* a, vector4d* b, vector4d* c) {

	a->x = (b->x + c->x) / 2;
	a->y = (b->y + c->y) / 2;
	a->z = (b->z + c->z) / 2;
	a->w = .0f;

	return c;
}

float vectorGetCos(vector4d* a, vector4d* b) {

	return vectorDotProduct(a, b) / sqrtf(vectorGetLenghtSquared(a) * vectorGetLenghtSquared(b));
}

vector4d* vectorNormalize(vector4d* a) {

	float n = vectorGetLenght(a);

	a->x /= n;
	a->y /= n;
	a->z /= n;

	return a;
}

vector4d* vectorNegate(vector4d *a) {

	a->x = -a->x;
	a->y = -a->y;
	a->z = -a->z;

	return a;
}
