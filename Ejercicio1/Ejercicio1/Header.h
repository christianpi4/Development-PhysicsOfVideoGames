#include <stdio.h>
#include <locale.h>
#include <iostream>

using namespace std;

template <class T>

class vec3 {
	
	T x, y, z;

public:
	
	vec3(T x1, T y1, T z1) {

		x = x1;
		y = y1;
		z = z1;

	}
	
	//~vec3();

	int normalize() {

		float m;

		m = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

		x = x / m;
		y = y / m;
		z = z / m;

		return x, y, z;

	}

	int zero() {

		x = 0;
		y = 0;
		z = 0;

		return x, y, z;

	}

	bool is_zero() {


	}

	float distance_to(vec3 v1, vec3 v2, vec3 v3) {



	}

};


