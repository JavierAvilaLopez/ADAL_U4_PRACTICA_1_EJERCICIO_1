#include <iostream>     // Incluye la biblioteca estándar para entrada/salida (cout, cin)
#include <vector>       // Incluye la biblioteca para el uso del contenedor vector
#include <algorithm>    // Incluye algoritmos estándar, como std::swap
#include <limits>       // Incluye herramientas para manejar los límites numéricos

using namespace std;    // Utiliza el espacio de nombres estándar para evitar el uso de "std::" repetidamente

/**
 * @brief Imprime los elementos de un vector de enteros en la consola.
 *
 * @param v El vector de enteros a imprimir.
 *        Se pasa por referencia constante para evitar copias innecesarias.
 *
 * @pre El vector puede estar vacío o contener cualquier número de elementos.
 *
 * @complexity Tiempo: O(n), donde n es el tamaño del vector.
 *             Espacio: O(1), ya que no se utiliza almacenamiento adicional significativo.
 */
void imprimirVector(const vector<int>& v) {
    for (int i : v) {  // Bucle que recorre cada elemento del vector
        cout << i << " ";  // Imprime el elemento seguido de un espacio
    }
    cout << endl;  // Imprime un salto de línea al final para mayor claridad
}

/**
 * @brief Ordena un vector de enteros en orden ascendente utilizando el algoritmo de selección.
 *
 * @param v El vector de enteros a ordenar. Se pasa por referencia para modificarlo directamente.
 *
 * @pre El vector puede contener números repetidos o negativos.
 *
 * @complexity Tiempo: O(n^2), donde n es el tamaño del vector, ya que hay dos bucles anidados.
 *             Espacio: O(1), ya que el ordenamiento se realiza en el propio vector (ordenamiento in situ).
 */
void ordenarSeleccion(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {  // Recorre cada posición del vector
        size_t minIndex = i;  // Asume que el elemento actual es el mínimo

        for (size_t j = i + 1; j < v.size(); j++) {  // Recorre los elementos restantes
            if (v[j] < v[minIndex]) {  // Encuentra el índice del elemento mínimo
                minIndex = j;  // Actualiza el índice mínimo
            }
        }

        // Intercambia el elemento actual con el mínimo encontrado
        swap(v[i], v[minIndex]);

        // Imprime el estado actual del vector después de cada intercambio
        imprimirVector(v);
    }
}

int main() {
    try {
        int sizeVector;  // Declaración de una variable entera para almacenar el tamaño de un vector
        cin.exceptions(ios::failbit);  // Configura cin para que lance una excepción si ocurre un error de entrada

        do {
            cout << "Enter size of vector: ";  // Muestra un mensaje para que el usuario ingrese el tamaño del vector
            cin >> sizeVector;  // Lee el tamaño ingresado por el usuario

            if (sizeVector <= 0) {  // Verifica si el tamaño ingresado es inválido (número no positivo)
                cout << "Invalid input. Try again." << endl;  // Informa al usuario sobre el error
                continue;
            }

            vector<int> vector(sizeVector);  // Declara el vector de tamaño indicado

            // Ingreso de elementos con manejo de errores
            for (int& i : vector) {
                cout << "Enter element at position " << i + 1 << ": ";
                while (!(cin >> vector[i])) {  // Verifica si la entrada es válida
                    cout << "Invalid input. Please enter an integer: ";
                    cin.clear();  // Limpia el estado de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar entrada incorrecta
                }
            }

            cout << "\nVector before sorting: ";
            imprimirVector(vector);

            // Ordenamiento por selección
            cout << "\nSorting process:\n";
            ordenarSeleccion(vector);

            cout << "\nSorted vector: ";
            imprimirVector(vector);

        } while (sizeVector <= 0);  // Repite el bucle mientras el tamaño sea inválido

    } catch (const ios_base::failure& e) {  // Captura excepciones de fallo en la entrada
        cout << "Error: " << e.what() << endl;  // Muestra el mensaje de error proporcionado por la excepción

        cin.clear();  // Limpia el estado de error de cin para permitir nuevas entradas
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar caracteres no deseados en el búfer
    }

    return 0;  // Finaliza el programa correctamente
}