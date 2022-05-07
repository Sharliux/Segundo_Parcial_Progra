#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "Persona.h"
#include "CONEXIONBD.h"
using namespace std;
class Estudiante : Persona {
private: string email;
	   string carnet;
public:
	Estudiante() {
	}
	Estudiante(string nom, string ape, string dir, int gen, string car, int tel, string fn, string em) : Persona(nom, ape, dir, tel, gen, fn) {
		email = em;
		carnet = car;

	}
	void setCarnet(string car) { carnet = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setGenero(int gen) { genero = gen; }
	void setEmail(string em) { email = em; }
	void setTelefono(int tel) { telefono = tel; }
	void setFehca_Nacimiento(string fn) { fecha_nacimiento = fn; }

	string getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getGenero() { return genero; }
	string getEmail() { return email; }
	int getTelefono() { return telefono; }
	string getFehca_Ncimineto() { return fecha_nacimiento; }


	void crear_estudiante() {
		int q_estado;
		CONEXIONBD cn = CONEXIONBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		string g = to_string(genero);
		cout << "Ingrese Carnet: ";
		cin >> carnet;
		cout << "Ingrese Nombre: ";
		cin >> nombres;
		cout << "Ingrese Apellido: ";
		cin >> apellidos;
		cout << "Ingrese Direccion: ";
		cin >> direccion;
		cout << "Ingrese Genero: ";
		cin >> genero;
		cout << "Ingrese Email: ";
		cin >> email;
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cout << "Ingrese Fecha de nacimiento: ";
		cin >> fecha_nacimiento;
		if (cn.getConectar()) {
			string insert = "insert into universidad.estudiante(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento) values('" + carnet + "','" + nombres + "', '" + apellidos + "','" + direccion + "','" + t + "'," + g + ", '" + email + "','" + fecha_nacimiento + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingresos Exitosos" << endl;
			}
			else {
				cout << "Error al Ingresar" << endl;
			}
		}
		else {
			cout << "ERROR EN LA CONEXION..." << endl;
		}
		cn.cerrar_conexion();
		system("pause");	system("cls");
	}

	void leer_estudiante() {
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		CONEXIONBD cn = CONEXIONBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM universidad.estudiante";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "------------------------------------------ESTUDIANTES------------------------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << "  |  " << fila[7] << "  |  " << fila[8] << endl;
				}
			}
			else {
				cout << "Error en Consulta : " << mysql_error(cn.getConectar()) << endl;
			}
			if (cn.getConectar()) {

			}
		}
		else {
			cout << "ERROR EN LA CONEXION..." << endl;
		}
		cn.cerrar_conexion();
		system("pause");	system("cls"); 
	}

	void actualizar_estudiante() {
		int q_estado;
		CONEXIONBD cn = CONEXIONBD();
		cn.abrir_conexion();
		string id_estudiante;
		string t = to_string(telefono);
		string g = to_string(genero);
		cout << "Ingrese id del estudiante: ";
		cin >> id_estudiante;
		cout << "Ingrese Carnet: ";
		cin >> carnet;
		cout << "Ingrese Nombre: ";
		cin >> nombres;
		cout << "Ingrese Apellido: ";
		cin >> apellidos;
		cout << "Ingrese Direccion: ";
		cin >> direccion;
		cout << "Ingrese Genero: ";
		cin >> genero;
		cout << "Ingrese Email: ";
		cin >> email;
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cout << "Ingrese Fecha de nacimiento: ";
		cin >> fecha_nacimiento;
		if (cn.getConectar()) {
			string update = "update universidad.estudiente set carnet =('" + carnet + "'), nombre =('" + nombres + "'), apellido =('" + apellidos + "'), direccion=('" + direccion + "'), genro=(" + g + "), emial=('" + email + "'), telefono=('" + t + "'), fecha_nacimiento('" + fecha_nacimiento + "') where id_estudiente = ('" + id_estudiante + "')  ";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Modificacion Exitosa..." << endl;
			}
			else {
				cout << "Error en la Modificacion..." << endl;
			}
		}
		else {
			cout << "ERROR EN LA CONEXION..." << endl;
		}
		cn.cerrar_conexion();
		system("pause");	system("cls");
	}

	void borrar_estudiante() {
		int q_estado;
		CONEXIONBD cn = CONEXIONBD();
		cn.abrir_conexion();
		string id_estudiante;
		cout << "Ingrese la ID que desea eliminar: " << endl;
		cin >> id_estudiante;
		if (cn.getConectar()) {
			string borrar = "delete from universidad.estudiante where id_estudiante = ('" + id_estudiante + "')";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa..." << endl;
			}
			else {
				cout << "Error en la Eliminacion..." << endl;
			}
		}
		else {
			cout << "ERROR EN LA CONEXION..." << endl;
		}
		cn.cerrar_conexion();
		system("pause");	system("cls");
	}
};
