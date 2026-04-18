#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

float calcularPromedio(const vector<float>& notas) {
    float suma = 0;
    for (float nota : notas) {
        suma += nota;
    }
    return suma / static_cast<float>(notas.size());
}

string determinarEstado(float promedio) {
    if (promedio >= 61) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

string determinarCategoria(float promedio) {
    if (promedio >= 85 && promedio <= 100) {
        return "Excelente";
    } else if (promedio >= 70) {
        return "Bueno";
    } else if (promedio >= 61) {
        return "Regular";
    } else {
        return "Deficiente";
    }
}

void mostrarResultado(const string& nombre, const string& curso, float promedio,
    const string& estado, const string& categoria) {
    cout << "\n----- RESULTADO FINAL -----" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Curso: " << curso << endl;
    cout << fixed << setprecision(0) << "Promedio: " << promedio << endl;
    cout << "Estado: " << estado << endl;
    cout << "Categoria: " << categoria << endl;
}

int main() {
    string nombre, curso;
    int cantidadNotas;

    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);

    cout << "Ingrese el curso: ";
    getline(cin, curso);

    cout << "Ingrese la cantidad de notas: ";
    cin >> cantidadNotas;
    cin.ignore();

    vector<float> notas(cantidadNotas);

    for (int i = 0; i < cantidadNotas; i++) {
        cout << "Ingrese la nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    float promedio = calcularPromedio(notas);
    string estado = determinarEstado(promedio);
    string categoria = determinarCategoria(promedio);

    mostrarResultado(nombre, curso, promedio, estado, categoria);

    return 0;
}