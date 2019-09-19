#include <stdio.h>
#include <locale.h>
#include <iostream>
#include "Header.h"

void main() {

	vec3 <int> v1(0, 0, 0);
	vec3 <float> v2(0, 0, 0);
	vec3 <double> v3(0, 0, 0);
	int opcion = 0;
	
	/*cout << v1.zero()<<endl;
	cout << v2.zero()<<endl;*/
	
	v1.inicial(v1);
	v2.inicial(v2);
	v3.inicial(v3);

	v1.writevector(v1);
	v2.writevector(v2);
	v3.writevector(v3);
	//cout << v1.zero() << endl;
	//cout << v1.is_zero() << endl;

	cout << "Elige una opcion: ";
	cin >> opcion;
	cout << v1.distance_to(v1, v2, v3, opcion) << endl;



	system("pause");
}