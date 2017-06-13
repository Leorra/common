#include "common.h"

triangle* triangleCreate(triangle* t, vector4d* a, vector4d* b, vector4d* c) {

	t->A = *vectorCreate(&t->A, a);
	t->B = *vectorCreate(&t->B, b);
	t->C = *vectorCreate(&t->C, c);

	vector4d AB, AC;
	t->N = *vectorNormalize(vectorCrossProduct(&t->N, vectorCreate(&AB, a, b), vectorCreate(&AC, a, c)));

	return t;
}

ray* rayCreate(ray* r, vector4d *a, vector4d *b) {

	r->A = *vectorCreate(&r->A, a);
	r->B = *vectorCreate(&r->B, b);

	r->R = *vectorNormalize(vectorCreate(&r->R, a, b));

	return r;
}

int rayTriangleIntersect(ray *r, triangle *t, vector4d *p) {

	vector4d temp1, temp2, temp3;

	float res1 = vectorDotProduct(
		vectorCrossProduct(&temp3, vectorCreate(&temp1, &r->A, &t->A), vectorCreate(&temp2, &r->A, &t->B)), &r->R);
	float res2 = vectorDotProduct(
		vectorCrossProduct(&temp3, vectorCreate(&temp1, &r->A, &t->B), vectorCreate(&temp2, &r->A, &t->C)), &r->R);
	float res3 = vectorDotProduct(
		vectorCrossProduct(&temp3, vectorCreate(&temp1, &r->A, &t->C), vectorCreate(&temp2, &r->A, &t->A)), &r->R);

	if (res1 > .0f && res2 > .0f && res3 > .0f ||
		res1 < .0f && res2 < .0f && res3 < .0f) {

		float dot = vectorDotProduct(&t->N, &r->R);
		if (dot == .0f)
			return 0;

		float d = vectorDotProduct(&t->N, vectorCreate(&temp3, &r->A, &t->A)) / dot;
		if (d < .0f)
			return 0;
		vectorCreate(p, &r->R);
		vectorMultiply(p, d);
		vectorAdd(p, &r->A);

		return 1;
	}

	else
		return 0;
}
