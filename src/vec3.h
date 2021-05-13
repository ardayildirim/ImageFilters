#pragma once

#include <cmath>

class vec3
{
public:
	double x, y, z;

	vec3();
	vec3(double, double, double);

	vec3 operator*(const double rhs);
	vec3 operator+(const vec3& rhs);
	vec3 operator-(const vec3& rhs);
	vec3 operator*(const float rhs);
	double operator[](int ind);


	void normalize();
	vec3 normalized() const;
	double magnitude() const;


	static vec3 cross_product(vec3, vec3);
	static double dot_product(vec3, vec3);
	static vec3 rotate(vec3&, double, double);
};

