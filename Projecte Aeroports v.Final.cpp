#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Tuplas (estructures)
struct CargaCorreoAeropuerto {
    string pais;
    string aeropuerto;
    float carga;
    float descarga;
    int vuelos;
};

struct CargaCorreoPais {
    string pais;
    float nacional;
    float intraeuropeo;
    float extraeuropeo;
};

struct PasajerosAeropuerto {
    int anyo;
    string pais;
    string aeropuerto;
    float meses[12];
};

struct PasajerosPais {
    int anyo;
    string pais;
    float meses[12];
};


const string nombresMeses[12] = {
    "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
    "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
};

void consultarPasajerosAeropuerto(const vector<PasajerosAeropuerto>& pa);
void consultarPasajerosPais(const vector<PasajerosPais>& pp);
void consultarAeropuerto(const vector<CargaCorreoAeropuerto>& cca);
void consultarPais(const vector<CargaCorreoAeropuerto>& cca);
void compararAeropuertoPais(const vector<CargaCorreoAeropuerto>& cca, const vector<CargaCorreoPais>& ccp);
void aeropuertoMasCarga(const vector<CargaCorreoAeropuerto>& cca);
void calcularTotalCorreoCargadoDescargado(const vector<CargaCorreoAeropuerto>& cca, const vector<CargaCorreoPais>& ccp);

int main() {
    ifstream fin1("carga_correo_aeropuerto.txt");
    ifstream fin2("carga_correo_pais.txt");
    ifstream fin3("cantidad_pasajeros_aeropuerto.txt");
    ifstream fin4("cantidad_pasajeros_pais.txt");

    vector<CargaCorreoAeropuerto> cca;
    vector<CargaCorreoPais> ccp;
    vector<PasajerosAeropuerto> pa;
    vector<PasajerosPais> pp;

    CargaCorreoAeropuerto registre_cca;
    while (fin1 >> registre_cca.pais >> registre_cca.aeropuerto >> registre_cca.carga >> registre_cca.descarga >> registre_cca.vuelos) {
        cca.push_back(registre_cca);
    }

    CargaCorreoPais registre_ccp;
    while (fin2 >> registre_ccp.pais >> registre_ccp.nacional >> registre_ccp.intraeuropeo >> registre_ccp.extraeuropeo) {
        ccp.push_back(registre_ccp);
    }

    PasajerosAeropuerto registre_pa;
    while (fin3 >> registre_pa.anyo >> registre_pa.pais >> registre_pa.aeropuerto) {
        for(int i = 0; i < 12; i++){
            fin3 >> registre_pa.meses[i];
        }
        pa.push_back(registre_pa);
    }

	PasajerosPais registre_pp;
	while (fin4 >> registre_pp.anyo >> registre_pp.pais) {
	    for (int j = 0; j < 12; j++) {
	        fin4 >> registre_pp.meses[j];
	    }
	    pp.push_back(registre_pp);
	}

int opcion = 0;
while (opcion != 5) {
    cout << "\t|=======================================|" << endl;
    cout << "\t|            MENU PRINCIPAL             |" << endl;
    cout << "\t|=======================================|" << endl;
    cout << "\t| 1. Submenu Pasajeros                  |" << endl;
    cout << "\t| 2. Submenu Mercancia y Correo         |" << endl;
    cout << "\t| 3. Salir                              |" << endl;
    cout << "\t|=======================================|" << endl;
    cout << "\tOpcion: ";
    cin >> opcion;

    if (opcion == 1) {
        int subop = 0;
        while (subop != 5) {
            cout << "\n\t|=======================================|" << endl;
            cout << "\t|        SUBMENU PASAJEROS              |" << endl;
            cout << "\t|=======================================|" << endl;
            cout << "\t| 1. Consultar pasajeros por aeropuerto |" << endl;
            cout << "\t| 2. Consultar pasajeros por pais       |" << endl;
            cout << "\t| 3. Volver al menu principal           |" << endl;
            cout << "\t|=======================================|" << endl;
            cout << "\tOpcion: ";
            cin >> subop;

	//SUBPROGRAMAS A USAR

            if (subop == 1) {
                consultarPasajerosAeropuerto(pa);
            }

            else if (subop == 2) {
                consultarPasajerosPais(pp);
            }
            else if (subop == 3) {
                break;
            }
            else{
                cout << "opcion no valida, intenta de nuevo." << endl;
            }
        }
    }
    else if (opcion == 2) {
        int subop = 0;
        while (subop != 3) {
            cout << "	|=======================================|" << endl;
            cout << "	|     SUBMENU MERCANCIA Y CORREO        |" << endl;
            cout << "	|=======================================|" << endl;
            cout << "	| 1. Consultar carga por aeropuerto     |" << endl;
            cout << "	| 2. Consultar carga total por pais     |" << endl;
            cout << "	| 3. Comparar aeropuerto con pais       |" << endl;
            cout << "	| 4. Aeropuerto con mas carga           |" << endl;
            cout << "	| 5. Total correo cargado + descargado  |" << endl;
            cout << "	| 6. Volver al menu principal           |" << endl;
            cout << "	|=======================================|" << endl;
            cout << "	Opcion: ";
            cin >> subop;

	//SUBPROGRAMAS A USAR PARA LAS SUBOPCIONES

            if (subop == 1) {
                consultarAeropuerto(cca);
            }

            else if (subop == 2) {
                consultarPais(cca);
            }
            else if (subop == 3) {
                compararAeropuertoPais(cca, ccp);
            }
            else if (subop == 4) {
                aeropuertoMasCarga(cca);
            }
            else if (subop == 5) {
                calcularTotalCorreoCargadoDescargado(cca, ccp);
            }
            else if (subop == 6) {
                break;
            }
            else{
                cout << "opcion no valida, intenta de nuevo." << endl;
            }
        }
	}
	
	else if (opcion == 3) {
	cout << "\n\t|==========================|" << endl;
    cout << "\t|   Finalitzant programa   |" << endl;
    cout << "\t|==========================|" << endl;
    break;
	}

}

return 0;
}

// DEFINICIONES DE FUNCIONES

float calcularPorcentaje(float part, float total) {
    float porcentaje = (part / total) * 100;
    return porcentaje;
}

void consultarPasajerosAeropuerto(const vector<PasajerosAeropuerto>& pa) {
    string aeropuerto;
    cout << "Introduce el nombre del aeropuerto: ";
    cin >> aeropuerto;

    bool trobat = false;
    float totalGlobal = 0;

    for (int i = 0; i < pa.size(); i++) {
        if (pa[i].aeropuerto == aeropuerto) {
            trobat = true;
            float suma = 0;
            int mesMax = 0;
            float valorMax = pa[i].meses[0];

            cout << "\n\t|===============================================|" << endl;
            cout << "\t|       DATOS DE PASAJEROS POR MES (MILES)      |" << endl;
            cout << "\t|===============================================|" << endl;

            for (int m = 0; m < 12; m++) {
                cout << "\t| " << pa[i].anyo << " - " << m + 1 << " : " << pa[i].meses[m] << " mil pasajeros\t|" << endl;
                suma += pa[i].meses[m];
                if (pa[i].meses[m] > valorMax) {
                    valorMax = pa[i].meses[m];
                    mesMax = m;
                }
            }

            totalGlobal += suma;

            cout << "\n\t|===============================================|" << endl;
            cout << "\t| Total anual: " << suma << " mil pasajeros" << endl;
            cout << "\t| Media mensual: " << suma / 12 << " mil pasajeros" << endl;
            cout << "\t| Mes con mas pasajeros: (" << mesMax + 1 << ") con " << valorMax << " mil pasajeros" << endl;
            cout << "\t|===============================================|" << endl;
        }
    }

    if (trobat) {
        cout << "\n\t|===============================================|" << endl;
        cout << "\t| TOTAL ACUMULADO: " << totalGlobal << " mil pasajeros" << endl;
        cout << "\t|===============================================|" << endl;
    } else {
        cout << "\nNo se han encontrado datos para el aeropuerto especificado." << endl;
    }
}

void consultarPasajerosPais(const vector<PasajerosPais>& pp) {
    string pais;
    cout << "Introduce el pais en minusculas: ";
    cin >> pais;

    vector<int> anysDisponibles;
    for (int i = 0; i < pp.size(); i++) {
        if (pp[i].pais == pais) {
            bool repetit = false;
            for (int j = 0; j < anysDisponibles.size(); j++) {
                if (anysDisponibles[j] == pp[i].anyo) {
                    repetit = true;
                }
            }
            if (!repetit) {
                anysDisponibles.push_back(pp[i].anyo);
            }
        }
    }

    if (anysDisponibles.size() == 0) {
        cout << "-----------------------------" << endl;
        cout << "No hay informacion disponible" << endl;
        cout << "-----------------------------" << endl;
        return;
    }

    cout << "\nAnys disponibles per al pais '" << pais << "':" << endl;
    for (int i = 0; i < anysDisponibles.size(); i++) {
        cout << i + 1 << ". " << anysDisponibles[i] << endl;
    }

    int seleccio;
    cout << "Selecciona un any: ";
    cin >> seleccio;

    if (seleccio < 1 || seleccio > anysDisponibles.size()) {
        cout << "Seleccio invalida." << endl;
        return;
    }

    int anySeleccionat = anysDisponibles[seleccio - 1];
    float totalGeneral = 0;

    for (int i = 0; i < pp.size(); i++) {
        if (pp[i].pais == pais && pp[i].anyo == anySeleccionat) {
            float suma = 0;
            int mesMax = 0;
            float valorMax = pp[i].meses[0];

            cout << "\n\t|====================================================|" << endl;
            cout << "\t|  DATOS DE PASAJEROS POR MES (MILES) - " << anySeleccionat << "         |" << endl;
            cout << "\t|====================================================|" << endl;

            for (int j = 0; j < 12; j++) {
                cout << "\t| " << nombresMeses[j] << ": " << pp[i].meses[j] << " mil pasajeros\t|" << endl;
                suma += pp[i].meses[j];
                if (pp[i].meses[j] > valorMax) {
                    valorMax = pp[i].meses[j];
                    mesMax = j;
                }
            }

            cout << "\n\t|====================================================|" << endl;
            cout << "\t| Total: " << suma << " mil pasajeros" << endl;
            cout << "\t| Media mensual: " << suma / 12 << " mil pasajeros" << endl;
            cout << "\t| Mes con mas pasajeros: " << nombresMeses[mesMax] << " con " << valorMax << " mil pasajeros" << endl;
            cout << "\t|====================================================|" << endl;

            totalGeneral += suma;
        }
    }

    char resposta;
    cout << "\nVols veure l'altre any disponible? (s/n): ";
    cin >> resposta;

    if (resposta == 's') {
        for (int i = 0; i < anysDisponibles.size(); i++) {
            if (anysDisponibles[i] != anySeleccionat) {
                int segonAny = anysDisponibles[i];
                for (int j = 0; j < pp.size(); j++) {
                    if (pp[j].pais == pais && pp[j].anyo == segonAny) {
                        float suma = 0;
                        cout << "\n\t|====================================================|" << endl;
                        cout << "\t|  DATOS DE PASAJEROS POR MES (MILES) - " << segonAny << "         |" << endl;
                        cout << "\t|====================================================|" << endl;

                        for (int m = 0; m < 12; m++) {
                            cout << "\t| " << nombresMeses[m] << ": " << pp[j].meses[m] << " mil pasajeros\t|" << endl;
                            suma += pp[j].meses[m];
                        }

                        cout << "\n\t| Total: " << suma << " mil pasajeros" << endl;
                        totalGeneral += suma;
                    }
                }
            }
        }

        cout << "\n\t|====================================================|" << endl;
        cout << "\t| TOTAL ACUMULADO TODOS LOS AÑOS: " << totalGeneral << " mil pasajeros" << endl;
        cout << "\t|====================================================|" << endl;
    }
}

void consultarAeropuerto(const vector<CargaCorreoAeropuerto>& cca) {
    int repetir = 1;
    while (repetir == 1) {
        vector<string> aero_unics;

        for (int i = 0; i < cca.size(); i++) {
            bool repetit = false;
            for (int j = 0; j < aero_unics.size(); j++) {
                if (cca[i].aeropuerto == aero_unics[j]) {
                    repetit = true;
                }
            }
            if (!repetit) {
                aero_unics.push_back(cca[i].aeropuerto);
            }
        }

        cout << "\n\t|=====================================|" << endl;
        cout << "\t|        AEROPUERTOS DISPONIBLES      |" << endl;
        cout << "\t|=====================================|" << endl;

        for (int i = 0; i < aero_unics.size(); i++) {
            cout << "\t| " << i + 1 << ". " << aero_unics[i] << endl;
        }

        int sel;
        cout << "\t|=====================================|" << endl;
        cout << "\tSelecciona un aeropuerto: ";
        cin >> sel;

        if (sel < 1 || sel > aero_unics.size()) {
            cout << "Seleccion invalida." << endl;
            return;
        }

        string aeroport_escollit = aero_unics[sel - 1];
        bool trobat = false;

        for (int i = 0; i < cca.size(); i++) {
            if (cca[i].aeropuerto == aeroport_escollit) {
                trobat = true;
                float carga = cca[i].carga;
                float descarga = cca[i].descarga;
                float total = carga + descarga;

                cout << "\n\t|=============================================|" << endl;
                cout << "\t|    INFORMACION DE CARGA Y CORREO (t)        |" << endl;
                cout << "\t|=============================================|" << endl;
                cout << "\t| Pais: " << cca[i].pais << endl;
                cout << "\t| Aeropuerto: " << cca[i].aeropuerto << endl;
                cout << "\t| Carga cargada: " << carga / 1000.0 << " mil t" << endl;
                cout << "\t| Carga descargada: " << descarga / 1000.0 << " mil t" << endl;
                cout << "\t| Total: " << total / 1000.0 << " mil t" << endl;
                cout << "\t|=============================================|" << endl;
                break;
            }
        }

        if (!trobat) {
            cout << "-----------------------" << endl;
            cout << "No hay informacion." << endl;
            cout << "-----------------------" << endl;
        }

        cout << "\n\t|=====================================|" << endl;
        cout << "\t| 1. Consultar otro aeropuerto        |" << endl;
        cout << "\t| 2. Volver al menu principal         |" << endl;
        cout << "\t|=====================================|" << endl;
        cout << "\tOpcion: ";
        cin >> repetir;
        if (repetir != 1) repetir = 0;
    }
}

void consultarPais(const vector<CargaCorreoAeropuerto>& cca) {
    int repetir = 1;
    while (repetir == 1) {
        vector<string> paisos_unics;

        for (int i = 0; i < cca.size(); i++) {
            bool repetit = false;
            for (int j = 0; j < paisos_unics.size(); j++) {
                if (cca[i].pais == paisos_unics[j]) {
                    repetit = true;
                }
            }
            if (!repetit) {
                paisos_unics.push_back(cca[i].pais);
            }
        }

        cout << "\n\t|=============================|" << endl;
        cout << "\t|        PAISES DISPONIBLES   |" << endl;
        cout << "\t|=============================|" << endl;
        for (int i = 0; i < paisos_unics.size(); i++) {
            cout << "\t| " << i + 1 << ". " << paisos_unics[i] << endl;
        }
        int sel;
        cout << "\t|=============================|" << endl;
        cout << "\tSelecciona un pais: ";
        cin >> sel;

        if (sel < 1 || sel > paisos_unics.size()) {
            cout << "Seleccion invalida." << endl;
            return;
        }

        string pais_escollit = paisos_unics[sel - 1];
        bool trobat = false;
        float carga = 0, descarga = 0;

        for (int i = 0; i < cca.size(); i++) {
            if (cca[i].pais == pais_escollit) {
                carga += cca[i].carga;
                descarga += cca[i].descarga;
                trobat = true;
            }
        }

        float total = carga + descarga;
        if (trobat) {
            cout << "\n\t|=============================================|" << endl;
            cout << "\t|       INFORMACION TOTAL POR PAIS (t)        |" << endl;
            cout << "\t|=============================================|" << endl;
            cout << "\t| Pais: " << pais_escollit << endl;
            cout << "\t| Carga cargada total: " << carga / 1000.0 << " mil t" << endl;
            cout << "\t| Carga descargada total: " << descarga / 1000.0 << " mil t" << endl;
            cout << "\t| Total: " << total / 1000.0 << " mil t" << endl;
            cout << "\t|=============================================|" << endl;
        } else {
            cout << "-----------------------" << endl;
            cout << "No hay informacion." << endl;
            cout << "-----------------------" << endl;
        }

        cout << "\n\t|=====================================|" << endl;
        cout << "\t| 1. Consultar otro pais              |" << endl;
        cout << "\t| 2. Volver al menu principal         |" << endl;
        cout << "\t|=====================================|" << endl;
        cout << "\tOpcion: ";
        cin >> repetir;
        if (repetir != 1) repetir = 0;
    }
}

void compararAeropuertoPais(const vector<CargaCorreoAeropuerto>& cca, const vector<CargaCorreoPais>& ccp) {
    int repetir = 1;
    while (repetir == 1) {
        cout << "\n\t|=========================================|" << endl;
        cout << "\t| COMPARAR AEROPUERTO CON DATOS DEL PAIS |" << endl;
        cout << "\t|=========================================|" << endl;

        string pais;
        cout << "Nombre del pais: ";
        cin >> pais;
        vector<string> aeropuertos;
        for (int i = 0; i < cca.size(); i++) {
            if (cca[i].pais == pais) aeropuertos.push_back(cca[i].aeropuerto);
        }
        for (int i = 0; i < aeropuertos.size(); i++) {
            cout << i + 1 << ". " << aeropuertos[i] << endl;
        }
        int sel;
        cout << "Seleccion: ";
        cin >> sel;
        if (sel > 0 && sel <= aeropuertos.size()) {
            string aero = aeropuertos[sel - 1];
            float carga = 0, descarga = 0;
            for (int i = 0; i < cca.size(); i++) {
                if (cca[i].aeropuerto == aero && cca[i].pais == pais) {
                    carga = cca[i].carga;
                    descarga = cca[i].descarga;
                }
            }
            float totalAero = carga + descarga;
            float totalPais = 0;
            for (int i = 0; i < ccp.size(); i++) {
                if (ccp[i].pais == pais) {
                    totalPais = ccp[i].nacional + ccp[i].intraeuropeo + ccp[i].extraeuropeo;
                    float totalSimplificat = totalPais / 1000.0;
                    float totalSimplificatAero = totalAero / 1000.0;
                    cout << "Total pais: " << totalSimplificat << " t" << endl;
                    cout << "Total aeropuerto: " << totalSimplificatAero << " t" << endl;
                    float porcentajePais = calcularPorcentaje(totalAero, totalPais);
                    cout << "Porcentaje aeropuerto respecto al pais: " << porcentajePais << " %" << endl;
                }
            }
            float maxOtroAero = 0;
            string aeroMax = "";
            for (int i = 0; i < cca.size(); i++) {
                if (cca[i].pais == pais && cca[i].aeropuerto != aero) {
                    float total = cca[i].carga + cca[i].descarga;
                    if (total > maxOtroAero) {
                        maxOtroAero = total;
                        aeroMax = cca[i].aeropuerto;
                    }
                }
            }
            if (maxOtroAero > 0) {
                float diferencia = maxOtroAero - totalAero;
                float porcentaje = calcularPorcentaje(diferencia, maxOtroAero);
                if (diferencia > 0) {
                    cout << "El aeropuerto seleccionado tiene " << porcentaje << "% menos carga que el de mayor carga del pais (" << aeroMax << ")" << endl;
                } else if (diferencia < 0) {
                    cout << "El aeropuerto seleccionado tiene " << -porcentaje << "% mas carga que el segundo mayor del pais (" << aeroMax << ")" << endl;
                } else {
                    cout << "El aeropuerto seleccionado tiene la misma carga que el de mayor carga." << endl;
                }
            }
        }

        cout << "\n\t|=====================================|" << endl;
        cout << "\t| 1. Consultar otro aeropuerto        |" << endl;
        cout << "\t| 2. Volver al menu principal         |" << endl;
        cout << "\t|=====================================|" << endl;
        cout << "\tOpcion: ";
        cin >> repetir;
        if (repetir != 1) repetir = 0;
    }
}

void aeropuertoMasCarga(const vector<CargaCorreoAeropuerto>& cca) {
    cout << "\n\t|=========================================|" << endl;
    cout << "\t| AEROPUERTO EUROPEO CON MAS CANTIDAD DE CARGA |" << endl;
    cout << "\t|=========================================|" << endl;

    float maxi_carga = 0;
    string aeropuerto_maxi_carga;
    for (int i = 0; i < cca.size(); i++) {
        if (cca[i].carga > maxi_carga) {
            maxi_carga = cca[i].carga;
            aeropuerto_maxi_carga = cca[i].aeropuerto;
        }
    }

    cout << "El Aeropuerto amb mes carga de correu es: " << aeropuerto_maxi_carga << endl;
    float cargaSimplificada = maxi_carga / 1000.0;
    cout << "Carga total: " << cargaSimplificada << " t" << endl;

    int opcio;
    cout << "\nVols veure el top 5 aeroports amb mes carga? (1 = Si, 0 = Tornar al menu): ";
    cin >> opcio;

    if (opcio == 1) {
        cout << "\n\t|=========================================|" << endl;
        cout << "\t|    TOP 5 AEROPUERTOS CON MAS CARGA 	 |" << endl;
        cout << "\t|=========================================|" << endl;

        vector<string> noms;
        vector<float> cargues;

        for (int i = 0; i < cca.size(); i++) {
            noms.push_back(cca[i].aeropuerto);
            cargues.push_back(cca[i].carga);
        }

        for (int i = 0; i < cargues.size() - 1; i++) {
            for (int j = i + 1; j < cargues.size(); j++) {
                if (cargues[j] > cargues[i]) {
                    float auxC = cargues[i];
                    cargues[i] = cargues[j];
                    cargues[j] = auxC;

                    string auxN = noms[i];
                    noms[i] = noms[j];
                    noms[j] = auxN;
                }
            }
        }

        for (int i = 0; i < 5 && i < cargues.size(); i++) {
            float cargaSimplificada = cargues[i] / 1000.0;
            cout << i + 1 << ". " << noms[i] << " - " << cargaSimplificada << " t" << endl;
        }
    }
}

void calcularTotalCorreoCargadoDescargado(const vector<CargaCorreoAeropuerto>& cca, const vector<CargaCorreoPais>& ccp) {
	int opsub = 1;
	while (opsub == 1) {
	cout << "\n\t|===============================================|" << endl;
	cout << "\t| TOTAL CARGA Y DESCARGA DE UN AEROPUERTO      |" << endl;
	cout << "\t|===============================================|" << endl;

	    string pais;
	    cout << "Introduce el pais en minusculas: ";
	    cin >> pais;
	
	    vector<string> aeropuertos;
	    for (int i = 0; i < cca.size(); i++) {
	        if (cca[i].pais == pais) aeropuertos.push_back(cca[i].aeropuerto);
	    }
	
	    if (aeropuertos.size() == 0) {
	        cout << "No se encontraron aeropuertos para el pais especificado." << endl;
	        opsub = 0;
	    } else {
	        for (int i = 0; i < aeropuertos.size(); i++) {
	            cout << i + 1 << ". " << aeropuertos[i] << endl;
	        }
	
	        int sel;
	        cout << "Selecciona un aeropuerto: ";
	        cin >> sel;
	
	        if (sel <= 0 || sel > aeropuertos.size()) {
	            cout << "Seleccion invalida." << endl;
	            opsub = 0;
	        } else {
	            string aeropuerto = aeropuertos[sel - 1];
	            float totalCarga = 0, totalDescarga = 0;
	            bool trobat = false;
	            for (int i = 0; i < cca.size(); i++) {
	                if (cca[i].aeropuerto == aeropuerto && cca[i].pais == pais) {
	                    trobat = true;
	                    totalCarga = cca[i].carga;
	                    totalDescarga = cca[i].descarga;
	                }
	            }
	
	            if (!trobat) {
	                cout << "-----------------------" << endl;
	                cout << "No hay informacion." << endl;
	                cout << "-----------------------" << endl;
	                opsub = 0;
	            } else {
	                float total = totalCarga + totalDescarga;
	                float totalSimplificada = total / 1000.0;
	                cout << "\n\t|=============================================|" << endl;
	                cout << "\t|  RESULTADOS DEL AEROPUERTO (MIL T)         |" << endl;
	                cout << "\t|=============================================|" << endl;
	                cout << "\t| Total carga + descarga: " << totalSimplificada << " t" << endl;
	
	                float totalPais = 0;
	                for (int i = 0; i < ccp.size(); i++) {
	                    if (ccp[i].pais == pais) {
	                        totalPais = ccp[i].nacional + ccp[i].intraeuropeo + ccp[i].extraeuropeo;
	                    }
	                }
	
	                if (totalPais > 0) {
	                    float porcentaje = calcularPorcentaje(total, totalPais);
	                    cout << "\t| Porcentaje respecto al total del pais: " << porcentaje << " %" << endl;
	                } else {
	                    cout << "\t| No se encontro el pais en la base de datos." << endl;
	                }
	
	                float maxTotal = 0;
	                string aeroMax = "";
	                for (int i = 0; i < cca.size(); i++) {
	                    float suma = cca[i].carga + cca[i].descarga;
	                    if (suma > maxTotal) {
	                        maxTotal = suma;
	                        aeroMax = cca[i].aeropuerto;
	                    }
	                }
	
	                float diferencia = maxTotal - total;
	                float perc = calcularPorcentaje(diferencia, maxTotal);
	                if (diferencia > 0) {
	                    cout << "\t| Este aeropuerto tiene un " << perc << "% menos que el de mayor carga: " << aeroMax << endl;
	                } else if (diferencia < 0) {
	                    cout << "\t| Este aeropuerto tiene un " << -perc << "% mas que el segundo mayor." << endl;
	                } else {
	                    cout << "\t| Este aeropuerto tiene la misma carga que el de mayor carga." << endl;
	                }
	
	                int eleccio = 0;
	                cout << "\n\t|=============================================|" << endl;
	                cout << "\t| OPCIONES ADICIONALES                       |" << endl;
	                cout << "\t|=============================================|" << endl;
	                cout << "\t| 1. Consultar otro aeropuerto               |" << endl;
	                cout << "\t| 2. Mostrar ranking de todos los aeropuertos|" << endl;
	                cout << "\t| 3. Volver al menu principal                |" << endl;
	                cout << "\t|=============================================|" << endl;
	                cout << "\tOpcion: ";
	                cin >> eleccio;
	
	                if (eleccio == 2) {
	                    cout << "\n\t|===============================================|" << endl;
	                    cout << "\t| RANKING DE TODOS LOS AEROPUERTOS (DESC)       |" << endl;
	                    cout << "\t|===============================================|" << endl;
	
	                    vector<string> noms;
	                    vector<float> valors;
	
	                    for (int i = 0; i < cca.size(); i++) {
	                        string nom = cca[i].aeropuerto;
	                        float valor = cca[i].carga + cca[i].descarga;
	
	                        bool repetit = false;
	                        for (int j = 0; j < noms.size(); j++) {
	                            if (nom == noms[j]) {
	                                repetit = true;
	                            }
	                        }
	
	                        if (!repetit) {
	                            noms.push_back(nom);
	                            valors.push_back(valor);
	                        }
	                    }
	
	                    for (int i = 0; i < valors.size() - 1; i++) {
	                        for (int j = i + 1; j < valors.size(); j++) {
	                            if (valors[j] > valors[i]) {
	                                float tmpVal = valors[i];
	                                valors[i] = valors[j];
	                                valors[j] = tmpVal;
	
	                                string tmpNom = noms[i];
	                                noms[i] = noms[j];
	                                noms[j] = tmpNom;
	                            }
	                        }
	                    }
	
	                    for (int i = 0; i < noms.size(); i++) {
	                        float val = valors[i] / 1000.0;
	                        cout << "\t| " << i + 1 << ". " << noms[i] << " - " << val << " t" << endl;
	                    }
	                    cout << "\t|===============================================|" << endl;
	                    opsub = 0;
	                } else if (eleccio == 1) {
	                    opsub = 1;
	                } else {
	                    opsub = 0;
	                }
	            }
	        }
	    }
	}
}

