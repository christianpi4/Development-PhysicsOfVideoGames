#include <stdio.h>
#include <locale.h>
#include <iostream>

using namespace std;

template <class T>

class vec3 {
	
	T x, y, z;

public:
	
	vec3(T, T, T);
	
	
	T normalize();
	void writevector(vec3);
	T zero();
	T is_zero();
	T distance_to(vec3, vec3, vec3);

};
template <class T>
vec3<T>::vec3(T x1, T y1, T z1) {

	x = x1;
	y = y1;
	z = z1;

}
template <class T>

T vec3<T>::normalize() {

	float m;

	m = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

	x = x / m;
	y = y / m;
	z = z / m;

	return x, y, z;

}

template <class T=void>

void vec3<T>::writevector(vec3 v) {

	cout << "(" << v.x << "," << v.y << "," << v.z << ")" << endl;
	/*return true;*/
}

template <class T>

T vec3<T>::zero() {

	x = 0;
	y = 0;
	z = 0;

	return x, y, z;

}
template <class T>

T vec3<T>::is_zero() {
	if (x == 0 & y == 0 & z == 0) {
		
		return true;
	}
	else {
		return false;
	}

}
template <class T>

T vec3<T>::distance_to(vec3 v1, vec3 v2, vec3 v3) {



}