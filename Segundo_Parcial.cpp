#include <iostream>
#include "Estudiante.h"
int main()
{
	int opcion;
	cout << "\t____________MENU DE OPCIONES____________" << endl;
	cout << "\t\t1. Crear estudiante" << endl;
	cout << "\t\t2. ver estudiante" << endl;
	cout << "\t\t3. Actualizar estudiante" << endl;
	cout << "\t\t4. eliminar estudiante" << endl;
	cout << "\t\t5. Salir" << endl << endl;
	cout << "\t\t\tDigite su opcion: ";
	cin >> opcion;
	Estudiante c = Estudiante();
	switch (opcion) {
	case 1: c.crear_estudiante(); ; break;
	case 2: c.leer_estudiante(); ; break;
	case 3: c.actualizar_estudiante(); ; break;
	case 4: c.borrar_estudiante(); ; break;
	case 5: exit(-1); ; break;
	default:cout << "Opcion no valida";
	}
	system("pause");
}

	


