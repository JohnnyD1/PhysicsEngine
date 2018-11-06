#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include<cmath>
#include <vector>
#include <iostream>
#include "log.hpp"
//#include "string.hpp"

class Vector3 {
public:
    double x;
    double y;
    double z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(double x1, double y1, double z1) : x(x1), y(y1), z(z1) {}

    std::vector<double> get_vec_values() const {
	return {x, y, z};
    }

    std::string get_str_values() const {
	
	return std::to_string(x) +  std::to_string(y) + std::to_string(z);

    }

    void invert() {

	x = -x;
	y = -y;
	z = -z;

    }
 
    // get the norm of Vector3
    double magnitude() const {
    	// can optimize this (don't need all the digits)
	return sqrt(x*x + y*y + z*z);
    }
    // sometimes we don't need to get the square root of the magnitude if we're just comparing two magnitudes
    double squared_magnitude() const {
	
	return x*x + y*y + z*z;
    }
    // converts non zero vector into one of unit length
    void normalize() {
	
	double mag = magnitude();

	if (mag > 0) {
	    // normalizes vector
	    x *= 1.0 / mag;
	    y *= 1.0 / mag;
	    z *= 1.0 / mag;
	}
    }
    // returns a copy of Vector3 with scaled values
    Vector3 operator *(const double scalar) const {
	return Vector3(x*scalar, y*scalar, z*scalar);
    }

    void operator *=(const double scalar) {
	x = x*scalar;
	y = y*scalar;
	z = z*scalar;
    }
    // adds to current Vector3
    void operator +=(const Vector3 &vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
    }
    // add to current Vector3 and creates a new vector
    Vector3 operator +(const Vector3 &vec) const {
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
    }
    // subtracts from current vec
    void operator -=(const Vector3 &vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
    }
    // subtracts and creates new vector
    Vector3 operator -(const Vector3 &vec) {
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
    }
    // scaling a vector and adding it to current vector
    void add_scaled_vec(const Vector3 &vec, const int scalar) {
	x += scalar * vec.x;
	y += scalar * vec.y;
	z += scalar * vec.z;
    }
    // multiplying same indices with different vectors, e.g. vec1.x * vec2.x
    Vector3 component_product(const Vector3 &vec) const {
	return Vector3(x * vec.x, y * vec.y, z * vec.z);
    }
    void component_product_update(const Vector3 &vec) {
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
    }
    double scalar_product (const Vector3 &vec) {
	return x * vec.x + y * vec.y + z * vec.z;
    }
    double operator *(const Vector3 &vec) {
	return x * vec.x + y * vec.y + z * vec.z;
    }
    
    Vector3 vector_product(const Vector3 &a, const Vector3 &b) const {
	
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,  a.x * b.y - a.y * b.x);
    }
    Vector3 vector_product(const Vector3 &vec) const {

	return Vector3(y * vec.z - z * vec.y, z * vec.x - x * vec.z,  x * vec.y - y * vec.x);
    }
    // computes the vector product of both vectors and assigns it to the current vector3
    void vector_product_update(const Vector3 &vec) {

	*this = vector_product(vec);
    }
    // vector3 c will be empty
    void get_orthonormal_vec(Vector3 &a, Vector3 &b, Vector3 &c) {
	
	a.normalize();
	c = vector_product(a, b);
	if (c.squared_magnitude() == 0.0) {
	    LOG("Input Vector3 a and b are parallel");
	    return;
	}
	b = vector_product(c, a); 

    }
};


#endif











