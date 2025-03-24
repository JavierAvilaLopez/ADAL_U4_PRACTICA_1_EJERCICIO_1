#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::swap

using namespace std;

// Función para imprimir el contenido del vector en la consola
void imprimirVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // Imprimir cada elemento separado por un espacio
    }
    cout << endl; // Nueva línea al final
}

// Función de ordenamiento por selección
void ordenamientoSeleccion(vector<int>& v) {
    int n = v.size(); // Obtener el tamaño del vector

    // Recorrer cada posición del vector
    for (int i = 0; i < n; i++) {
        int minIndex = i; // Asumir que el índice mínimo es el actual

        // Buscar el índice del valor mínimo en el resto del vector
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) { // Comparar elementos
                minIndex = j; // Actualizar el índice mínimo si se encuentra uno menor
            }
        }

        // Intercambiar el valor mínimo encontrado con el valor en la posición actual
        swap(v[i], v[minIndex]);

        // Imprimir el vector después de cada intercambio
        imprimirVector(v);
    }
}

int main() {
    int n;

    // Solicitar el número de elementos al usuario
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v(n); // Crear un vector de tamaño n

    // Solicitar los elementos del vector
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> v[i]; // Leer cada elemento ingresado por el usuario
    }

    // Llamar a la función de ordenamiento por selección
    ordenamientoSeleccion(v);

    // Mensaje final con el vector ordenado
    cout << "Sorted elements: ";
    imprimirVector(v);

    return 0;
}
