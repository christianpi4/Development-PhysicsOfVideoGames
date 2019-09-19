#include <stdio.h>
#include <locale.h>
#include <iostream>

using namespace std;

template <class T=void>

class vec3 {
	
	T x, y, z;

public:
	
	vec3(T, T, T);
	
	
	T normalize();
	void writevector(vec3);
	void inicial(vec3 <int>);
	T zero();
	T is_zero();
	T distance_to(vec3 <int>, vec3 <float>, vec3 <double>);

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



template <class T>

void vec3<T>::inicial(vec3 <int> v1) {


	cout << "Elige el primer vector de tipo INT: " << endl;
	cout << "X: " << endl;
	cin >> v1.x;
	cout << "Y: " << endl;
	cin >> v1.y;
	cout << "Z: " << endl;
	cin >> v1.z;
	

	/*cout << "Elige el segundo vector de tipo INT: " << endl;
	cout << "X: " << endl;
	cin >> v2.x;
	cout << "Y: " << endl;
	cin >> v2.y;
	cout << "Z: " << endl;
	cin >> v2.z;
	system("clear");

	cout << "Elige el tercer vector de tipo INT: " << endl;
	cout << "X: " << endl;
	cin >> v3.x;
	cout << "Y: " << endl;
	cin >> v3.y;
	cout << "Z: " << endl;
	cin >> v3.z;
	system("clear");*/

	
	//cout << "(" << v.x << "," << v.y << "," << v.z << ")" << endl;
	/*return true;*/
}

template <class T>

void vec3<T>::writevector(vec3 v1) {

	cout << "(" << v1.x << "," << v1.y << "," << v1.z << ")" << endl;
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

T vec3<T>::distance_to(vec3 <int> v1, vec3 <float> v2, vec3 <double> v3) {



}