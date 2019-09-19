#include <stdio.h>
#include <locale.h>
#include <iostream>
#include "Header.h"

void main() {

	vec3 <int> v1(0, 0, 0);
	vec3 <float> v2(0, 0, 0);
	vec3 <double> v3(0, 0, 0);
	
	/*cout << v1.zero()<<endl;
	cout << v2.zero()<<endl;*/
	
	v1.inicial(v1);

	v1.writevector(v1);
	//cout << v1.zero() << endl;
	//cout << v1.is_zero() << endl;






	system("pause");
}