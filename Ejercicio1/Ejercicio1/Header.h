#include <stdio.h>
#include <locale.h>
#include <iostream>

using namespace std;

template <class T=void>

class vec3 {
	

public:
	
	T x, y, z;
	
	vec3(T, T, T);
	vec3();
	
	void normalize();
	void writevector();
	void inicial();

	void zero();
	bool is_zero();
	void distance_to(vec3 <int>, vec3 <float>, vec3 <double>, int);
	/*friend vec3<T> operator +(vec3<T>);
	friend vec3<T> operator -(vec3<T>);
	friend vec3<T> operator -=(vec3<T>);
	friend vec3<T> operator +=(vec3<T>);
	friend vec3<T> operator ==(vec3<T>);*/
	

};

template <class T>

vec3<T>::vec3() {

	x = 0;
	y = 0;
	z = 0;

}

template <class T>

vec3<T>::vec3(T x1, T y1, T z1) {

	x = x1;
	y = y1;
	z = z1;

}

template <class T>

void vec3<T>::normalize() {

	float m;

	m = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

	x = x / m;
	y = y / m;
	z = z / m;

	cout << "(" << x << "," << y << "," << z << ")" << endl;

}

template <class T>

void vec3<T>::inicial() {

	cout << "Elige los vectores el primero INT, segundo FLOAT y el tercero DOUBLE: " << endl;

	cout << "x: ";
	cin >> x;
	cout << endl;
	cout << "y: ";
	cin >> y;
	cout << endl;
	cout << "z: ";
	cin >> z;
	cout << endl;

	cout << "(" << x << "," << y << "," << z << ")" << endl;

}

template <class T>

void vec3<T>::writevector() {

	cout << "(" << x << "," << y << "," << z << ")" << endl;
	
}

template <class T>

void vec3<T>::zero() {

	x = 0;
	y = 0;
	z = 0;

	cout << "(" << x << "," << y << "," << z << ")" << endl;

}
template <class T>

bool vec3<T>::is_zero() {
	
	if (x == 0 && y == 0 && z == 0) {
		
		return true;
	}
	else {
		return false;
	}

}

template <class T>

void vec3<T>::distance_to(vec3 <int> v1, vec3 <float> v2, vec3 <double> v3, int opcion) {
	
	float res1=0, res2=0, res3=0;

	if(opcion==1){
		
		res1=pow(pow(v1.x - v2.x,2) + pow(v1.y - v2.y,2) + pow(v1.z - v2.z,2),1/2);

		return res1;

	}

	else if (opcion == 2) {

		res2=pow(pow(v2.x - v3.x, 2) + pow(v2.y - v3.y, 2) + pow(v2.z - v3.z, 2), 1 / 2);

		return res2;

	}

	else if (opcion == 3) {

		res3=pow(pow(v3.x - v1.x, 2) + pow(v3.y - v1.y, 2) + pow(v3.z - v1.z, 2), 1 / 2);

		return res3;

	}
	
}

//template <class T>
//
//vec3<T> operator +(vec3<T>) {
//	vec3 <T>res(0, 0, 0);
//	res.x = this->x + v1.x;
//	res.y = this->y + v1.y;
//	res.z = this->z + v1.z;
//	return res;
//}
//
//template <class T>
//
//vec3<T> operator -(vec3<T>) {
//	{
//		vec3 <T>res(0, 0, 0);
//		res.x = this->x - v1.x;
//		res.y = this->y - v1.y;
//		res.z = this->z - v1.z;
//		return res;
//	}
//}
//
//template <class T>
//
//vec3<T> operator -=(vec3<T>) {
//	{
//		vec3 <T>res(0, 0, 0);
//
//		res.x = this->x -= v1.x;
//		res.y = this->y -= v1.y;
//		res.z = this->z -= v1.z;
//		return res;
//	}
//}
//
//template <class T>
//
//vec3<T> operator+=(vec3<T>) {
//	{
//		vec3 <T>res(0, 0, 0);
//		res.x = this->x += v1.x;
//		res.y = this->y += v1.y;
//		res.z = this->z += v1.z;
//		return res;
//	}
//}
//
//template <class T>
//
//vec3<T> operator ==(vec3<T>) {
//	{
//		if (this->x == v1->x && this->y == v1->y && this->z == v1->z)
//		{
//			return true;
//		}
//		return false;
//	}
//}
