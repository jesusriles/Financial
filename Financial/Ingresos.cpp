#include "Ingresos.h"

Ingresos::Ingresos(int tmpId, string tmpShortDescription, int tmpAccountId, float tmpAmount)
{
	mId = tmpId;
	mShortDescription = tmpShortDescription;
	mAccountId = tmpAccountId;
	mAmount = tmpAmount;
}

void Ingresos::imprimirIngresos(const vector<Ingresos> &i) {
	// Modificar un numero para que muestre comas (e.j. 1,000,999.321)
	std::cout.imbue(std::locale(""));
	std::cout << std::fixed << std::showpoint << std::setprecision(2);

	for (Ingresos ingreso : i) {
		int tabSize = 40 - ingreso.mShortDescription.size();

		cout << ingreso.mId << "\t" << ingreso.mAccountId << "\t" <<
			ingreso.mShortDescription << setw(tabSize) << ingreso.mAmount << endl;
	}
	system("PAUSE"); // wait user input to continue
}

double Ingresos::obtenerIngresoTotalDeCuenta(vector<Ingresos> &i, int cuentaId) {

	float total{ 0 };

	for (Ingresos ingreso : i) {
		if(ingreso.getAccountId() == cuentaId)
		total += ingreso.mAmount;
	}
	return total;
}

bool Ingresos::guardarIngreso(Ingresos& i) {

	ofstream file;
	file.open(ARCHIVO_INGRESOS, fstream::app);

	file <<
		i.getId() << "," <<
		i.getShortDescription() << "," <<
		i.getAccountId() << "," <<
		i.getAmount() << ";" <<
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
		int tmpId{ 0 };
		string tmpShortDescription{};
		int tmpIdCuentaAsociada{ 0 };
		float tmpCantidad{ 0 };

		for (int x{ 0 }; x < lineTmp.size(); ++x) { // iterar sobre cada letra en cada linea

			if (lineTmp[x] != ',' && lineTmp[x] != ';') { // separar cada elemento por coma
				s += lineTmp[x];
			}

			else {
				// asignar los valores
				if (contadorDeComas == 0) tmpId = stoi(s);
				else if (contadorDeComas == 1) tmpShortDescription = s;
				else if (contadorDeComas == 2)  tmpIdCuentaAsociada = stoi(s);
				else if (contadorDeComas == 3) {
					tmpCantidad = stof(s);

					// se crea la cuenta y se agrega al vector cuentas
					ingresos.push_back(Ingresos(tmpId, tmpShortDescription, tmpIdCuentaAsociada, tmpCantidad));
				}
				contadorDeComas++;
				s = "";
			}
		}
	}
	return ingresos;
}