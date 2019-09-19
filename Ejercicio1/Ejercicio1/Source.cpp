#include <stdio.h>
#include <locale.h>
#include <iostream>
#include "Header.h"

void main() {


	int opcion = 0;

	vec3 <int> v1(0,0,0);
	vec3 <float> v2(0,0,0);
	vec3 <double> v3(0,0,0);
	
	int i;

	v1.inicial();
	v2.inicial();
	v3.inicial();

	do{

		
		cout << " -----------------MENU----------------- " << endl;
		cout << "1. Normalize" << endl;
		cout << "2. Zero" << endl;
		cout << "3. Is Zero?" << endl;
		cout << "4. Distance To" << endl;
		cout << "5. Introducir nuevos vectores" << endl;
		cout << "6. Mostrar Vectores" << endl;
		cout << "7. Salir" << endl;
		
		cin >> i;

		if (i = 1) {
			
			
			v1.normalize();
			v2.normalize();
			v3.normalize();

		}

		else if (i = 2) {
			
			
			v1.zero();
			v2.zero();
			v3.zero();

		}

		else if (i = 3) {
			
			
			v1.is_zero();
			v2.is_zero();
			v3.is_zero();

		}

		else if (i = 4) {

		
		/*	v1.distance_to();
			v2.distance_to();
			v3.distance_to();*/

		}

		else if (i = 5) {

			v1.inicial();
			v2.inicial();
			v3.inicial();

		}

		else if (i = 6) {

			
			v1.writevector();
			v2.writevector();
			v3.writevector();

		}
		
		else if (i = 7) {

			system("pause");

		}

		
		//cout << v1.distance_to(v1, v2, v3, opcion) << endl;*/


	} while (i != 7);

	system("pause");
}