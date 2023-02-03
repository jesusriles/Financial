#include "Ingresos.h"

Ingresos::Ingresos(int id, int mIdCuentaAsociada, float cantidad) :
	mId{ id }, mIdCuentaAsociada{ mIdCuentaAsociada }, mCantidad{ cantidad }
{
}

void Ingresos::imprimirIngresos() {
	// Modificar un numero para que muestre comas (e.j. 1,000,999.321)
	std::cout.imbue(std::locale(""));
	std::cout << std::fixed << std::showpoint << std::setprecision(3);

	cout << "Id: " << mId <<
		" Id cuenta: " << mIdCuentaAsociada << " Cantidad: $" << mCantidad << endl;
}

double Ingresos::obtenerIngresoTotalDeCuenta(vector<Ingresos> &i, int cuentaId) {

	float total{ 0 };

	for (Ingresos ingreso : i) {
		if(ingreso.getIdCuentaAsociada() == cuentaId)
		total += ingreso.mCantidad;
	}
	return total;
}