//
// Created by Miguel Mercado on 28/11/23.
//

#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Variables para almacenar la información del usuario
    int edad;
    string lugarDeNacimiento;
    int horasEjercicioPorSemana;
    bool fuma;
    bool consumeAlcohol;
    int horasSueno;
    bool familiarConCancer;
    string gradoParentesco;
    bool parienteMayorDe95;

    // Random entre 70 y 73
    srand(time(NULL));
    int expectativaDeVida = rand() % 4 + 70;

    // Solicitar información al usuario
    cout << "Ingresa tu edad: ";
    cin >> edad;

    cout << "Ingresa tu lugar de nacimiento: ";
    cin.ignore(); // Para manejar la entrada de cadenas que contienen espacios
    getline(cin, lugarDeNacimiento);

    cout << "Ingresa la cantidad de horas de ejercicio por semana: ";
    cin >> horasEjercicioPorSemana;

    cout << "¿Fumas? (1 para sí, 0 para no): ";
    cin >> fuma;

    cout << "¿Consumes alcohol regularmente? (1 para sí, 0 para no): ";
    cin >> consumeAlcohol;

    cout << "Ingresa la cantidad de horas de sueño por noche: ";
    cin >> horasSueno;

    cout << "¿Tienes algún pariente cercano que haya tenido cáncer? (1 para sí, 0 para no): ";
    cin >> familiarConCancer;

    // Si hay antecedentes de cáncer, preguntar sobre el grado de parentesco
    if (familiarConCancer) {
        cout << "¿Qué familiar ha tenido cáncer? ";
        cin.ignore();
        getline(cin, gradoParentesco);

        // Ajustar la expectativa de vida según la cercanía del familiar
        if (gradoParentesco == "padre" || gradoParentesco == "Padre" ||  gradoParentesco == "madre" || gradoParentesco == "Madre" || gradoParentesco == "hermano" || gradoParentesco == "Hermano" || gradoParentesco == "hermana" || gradoParentesco == "Hermana") {
            expectativaDeVida -= 5;  // Reducción para padres, madres, hermanos y hermanas
            cout << "Lo siento, pero debido a antecedentes de cáncer en un familiar cercano, se reduce la expectativa de vida." << endl;
            // Puedes ajustar la expectativa de vida según la cercanía del familiar
            // Por ejemplo, se podría restar una cantidad mayor si es un padre/madre que si es un hermano/hermana.
            // Pero esto es solo un ejemplo simple.
        }
    }

    cout << "¿Alguno de tus parientes cercanos ha vivido más de 95 años? (1 para sí, 0 para no): ";
    cin >> parienteMayorDe95;

    // Ajustar la expectativa de vida si algún pariente cercano ha vivido más de 95 años
    if (parienteMayorDe95) {
        cout << "¡Increíble! Debido a que un pariente cercano ha vivido más de 95 años, se aumenta la expectativa de vida." << endl;
        // Puedes ajustar la expectativa de vida según lo que consideres apropiado.
        // Por ejemplo, podrías sumar una cantidad fija o un porcentaje.
    }

    // Ajustar la expectativa de vida según factores
    if (edad > 50) {
        expectativaDeVida -= 5;  // Reducción para personas mayores de 50 años
    }

    if (lugarDeNacimiento == "Japon" || lugarDeNacimiento == "japon" || lugarDeNacimiento == "Japón" || lugarDeNacimiento == "japón") {
        expectativaDeVida += 6;  // Aumento para personas nacidas en Japón
    }

    if (lugarDeNacimiento == "Mexico" || lugarDeNacimiento == "mexico" || lugarDeNacimiento == "México" || lugarDeNacimiento == "méxico") {
        expectativaDeVida += 2;  // Aumento para personas nacidas en México
    }

    if (lugarDeNacimiento == "Estados Unidos" || lugarDeNacimiento == "estados unidos" || lugarDeNacimiento == "Estados unidos" || lugarDeNacimiento == "estados Unidos") {
        expectativaDeVida += 3;  // Aumento para personas nacidas en Estados Unidos
    }

    if (lugarDeNacimiento == "Colombia" || lugarDeNacimiento == "colombia") {
        expectativaDeVida += 1;  // Aumento para personas nacidas en Colombia
    }

    if (horasEjercicioPorSemana >= 5) {
        expectativaDeVida += 3;  // Aumento para personas que hacen ejercicio regularmente
    }

    if (fuma) {
        expectativaDeVida -= 7;  // Reducción para fumadores
    }

    if (consumeAlcohol) {
        expectativaDeVida -= 3;  // Reducción para consumidores regulares de alcohol
    }

    if (horasSueno >= 7 && horasSueno <= 9) {
        expectativaDeVida += 2;  // Aumento para personas que duermen lo recomendado
    }


    if (parienteMayorDe95) {
        expectativaDeVida += 5;  // Aumento para personas con parientes que han vivido más de 95 años
    }

    // Mostrar la expectativa de vida estimada
    cout << "\nTu expectativa de vida estimada es: " << expectativaDeVida << " años." << endl;

    return 0;
}
