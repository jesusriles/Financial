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

bool Ingresos::guardarIngreso(Ingresos& i) {

	ofstream file;
	file.open(ARCHIVO_INGRESOS, fstream::app);

	file <<
		i.getId() << "," <<
		i.getIdCuentaAsociada() << "," <<
		i.getCantidad() << ";" <<
		endl;

	file.close();
	return true;
}

vector<Ingresos> Ingresos::leerIngresos() {

	string lineTmp{};
	ifstream file(ARCHIVO_INGRESOS, std::ifstream::in);

	vector<Ingresos> ingresos{};

	for (int i{ 0 }; getline(file, lineTmp); ++i) { // iterar sobre cada linea

		int contadorDeComas{ 0 };
		string s{};

		// valores que se necesitan para hacer la clase de tipo Ingresos
		int tmpId{ 0 };					// 0
		int tmpIdCuentaAsociada{ 0 };		// 1
		float tmpCantidad{ 0 };			// 2

		for (int x{ 0 }; x < lineTmp.size(); ++x) { // iterar sobre cada letra en cada linea

			if (lineTmp[x] != ',' && lineTmp[x] != ';') { // separar cada elemento por coma
				s += lineTmp[x];
			}

			else {
				// asignar los valores
				if (contadorDeComas == 0) tmpId = stoi(s);
				else if (contadorDeComas == 1)  tmpIdCuentaAsociada = stoi(s);
				else if (contadorDeComas == 2) {
					tmpCantidad = stof(s);

					// se crea la cuenta y se agrega al vector cuentas
					ingresos.push_back(Ingresos(tmpId, tmpIdCuentaAsociada, tmpCantidad));
				}

				contadorDeComas++;
				s = "";
			}
		}
	}
	return ingresos;
}