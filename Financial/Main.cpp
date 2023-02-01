#include <iostream>
#include "Cuentas.h"
#include "Ingresos.h"
#include "Menu.h"

int main()
{
	// Menu (todavia es un draft)
	// Menu menu{};
	// menu.printMenu();

	// Crear cuenta
	Cuentas cuentaUno{ 1, "Cartera", 200.50, 0, 0, "null" };
	Cuentas cuentaDos{ 2, "HSBC Nomina", 0.0, 0, 0, "Tarjeta donde me depositan de Deloitte" };

	cuentaUno.imprimirCuenta();
	cuentaDos.imprimirCuenta();

	// Crear ingresos
	Ingresos ingresoUno{ 1, 1, 50 };
	Ingresos ingresoDos{ 2, 1, 450 };
	Ingresos ingresoTres{ 3, 2, 32956.86 };

	
	ingresoUno.imprimirIngresos();
	ingresoDos.imprimirIngresos();
	ingresoTres.imprimirIngresos();
	
	return 0;
}

/*
Version 1:
	*[] Creando toda la logica de las cuentas
		*19 Ene -> [x] Poder crear una cuenta
			*19 Ene -> [x] Agregar el constructor
			*19 Ene -> [x] Agregar las reglas de lo que se puede y no se puede hacer en las cuentas (e.g. nombre maximo x caracteres, etc.)
		
		[] Al crear una cuenta, si se registra un monto inicial debe crear un ingreso/gasto inicial con el comentario "Inicial"
			
		[] Poder imprimir la informacion de la cuenta
		[] Poder eliminar una cuenta
		[] Poder modificar una cuenta

	[] Poder guardar la informacion en un archivo de forma organizada
		[] Pensar en la mejor forma de guardar informacion
			1- Puede ser en archivos mensuales (IngresosEnero2023.txt, GastosFebrero2023.txt)
			2- Todo los ingresos/gastos/movimientos por mes (Movimientos2023.txt)

	[] Tener un menu y la estructura de como va a ser el menu (con la parte de las cuentas)
 */