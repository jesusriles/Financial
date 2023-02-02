#include "FileMgmt.h"

bool FileMgmt::guardarCuenta(Cuentas &c) {

	ofstream file;
	file.open(ARCHIVO_CUENTAS, fstream::app);
	
	file << 
		c.obtenerId() << "," <<
		c.obtenerNombre() << "," <<
		c.obtenerComentario() << "," <<
		c.obtenerFechaCreacion() << "," <<
		c.obtenerValorInicial() << "," <<
		c.obtenerTipoDeCuenta() << "," <<
		c.obtenerTipoDeMoneda() << "," <<
		c.obtenerEscondido() << "," <<
		c.obtenerArchivado() << ";" <<
		endl;
	
	file.close();
	return true;
}

bool FileMgmt::leerCuenta(int id) {

}