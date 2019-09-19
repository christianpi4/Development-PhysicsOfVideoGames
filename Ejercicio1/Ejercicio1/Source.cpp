#include <stdio.h>
#include <locale.h>
#include <iostream>
#include "Header.h"

void main() {

	vec3 <int> v1(4, 4, 4);
	vec3 <float> v2(4.4, 2.4, 5.3);
	vec3 <double> v3(2.55, 7.44, 8.34); 

	/*cout << v1.zero()<<endl;
	cout << v2.zero()<<endl;*/
	cout << v1.writevector(v1)<<endl;
	cout << v1.is_zero()<<endl;









	system("pause");
}