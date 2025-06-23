
DESCRIPCIÓN (ESPAÑOL)
---------------------
Este proyecto analiza y consulta datos sobre el transporte aéreo europeo,
procesando información relativa a carga, correo y pasajeros. Los datos 
provienen de cuatro ficheros TXT y permiten consultas detalladas por país,
aeropuerto y año.

El sistema permite:
- Mostrar totales y medias mensuales de pasajeros por país.
- Comparar datos de pasajeros entre años.
- Consultar la carga y correo transportados por país y aeropuerto.
- Calcular porcentajes respecto al total nacional.
- Generar rankings ordenados por carga y pasajeros.
- Comparar un aeropuerto con el total de su país.
- Mostrar menús interactivos para facilitar la navegación.

El código cumple con las restricciones impuestas:
- Uso de `vector` y estructuras (`struct`) para almacenar los datos.
- No se utilizan funciones avanzadas de la STL como `find`, `sort`, `auto`, `size_t`, `to_string`, etc.
- Todos los formatos y cálculos se hacen manualmente.
- La entrada y salida de datos se realiza con `cin` y `cout`, con diseño visual por consola.

FICHEROS
--------
- `Projecte Aeroports v.Final.cpp`: Código fuente principal.
- `*.txt`: Archivos de datos originales.

COMPILACIÓN
-----------
Compilar con un compilador C++ estándar, por ejemplo:
    g++ -o aeroports programa.cpp
    ./aeroports

REQUISITOS
----------
- Sistema compatible con C++11 o superior.
- Archivos de datos en el mismo directorio que el ejecutable.

DESCRIPTION (ENGLISH)
---------------------
This project analyzes and queries data on European air transport,
processing information related to cargo, mail, and passengers.
The data is taken from four TXT files and enables detailed queries
by country, airport, and year.

The system allows:
- Displaying passenger totals and monthly averages by country.
- Comparing passenger data between years.
- Querying cargo and mail transported by country and airport.
- Calculating percentages with respect to the national total.
- Generating rankings sorted by cargo and passengers.
- Comparing an airport with the total of its country.
- Navigating through interactive console menus.

The code follows the constraints established:
- Uses `vector` and `struct` to store data.
- Does NOT use advanced STL features like `find`, `sort`, `auto`, `size_t`, `to_string`, etc.
- All formatting and calculations are done manually.
- Input/output is handled using `cin` and `cout`, with a visual console layout.

FILES
-----
- `Projecte Aeroports v.Final.cpp`: Main source code.
- `*.txt`: Original data files.

COMPILATION
-----------
Compile with any standard C++ compiler, e.g.:
    g++ -o aeroports program.cpp
    ./aeroports

REQUIREMENTS
------------
- C++11 or later compatible system.
- Data files in the same folder as the executable.
