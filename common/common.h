#pragma once

#include "vector4d.h"

typedef struct _triangle {

	vector4d A;
	vector4d B;
	vector4d C;
	vector4d N;

} triangle;

typedef struct _ray {

	vector4d A;
	vector4d B;
	vector4d R;

} ray;

triangle* triangleCreate(triangle* t, vector4d *a, vector4d *b, vector4d *c);
ray* rayCreate(ray* r, vector4d *a, vector4d *b);

int rayTriangleIntersect(ray *r, triangle *t, vector4d *p);
