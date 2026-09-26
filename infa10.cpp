#include <iostream>
#include <set>
#include <string>

int main()
{
    // ---------------------------------------------------------
    // PARTE 1: Mantener códigos únicos (std::set)
    // ---------------------------------------------------------
    std::cout << "--- std::set (Registro Único) ---\n";
    std::set<std::string> codigos_unicos;

    // 1. Inserción de clave nueva
    auto res_nuevo = codigos_unicos.insert("USER-100");
    std::cout << "Insertando 'USER-100': "
              << (res_nuevo.second ? "Aceptado" : "Rechazado") << "\n";

    // 2. Inserción de clave repetida
    auto res_duplicado = codigos_unicos.insert("USER-100");
    std::cout << "Insertando 'USER-100' nuevamente: "
              << (res_duplicado.second ? "Aceptado" : "Rechazado por duplicado") << "\n";

    // 3. Búsqueda de clave existente y clave inexistente
    bool existe_100 = (codigos_unicos.find("USER-100") != codigos_unicos.end());
    bool existe_999 = (codigos_unicos.find("USER-999") != codigos_unicos.end());

    std::cout << "Busqueda 'USER-100': " << (existe_100 ? "Encontrado" : "No encontrado") << "\n";
    std::cout << "Busqueda 'USER-999': " << (existe_999 ? "Encontrado" : "No encontrado") << "\n\n";

    // ---------------------------------------------------------
    // PARTE 2: Registrar todas las ocurrencias (std::multiset)
    // ---------------------------------------------------------
    std::cout << "--- std::multiset (Historial de Accesos) ---\n";
    std::multiset<std::string> historial_accesos;

    // Simulamos múltiples accesos
    historial_accesos.insert("USER-100");
    historial_accesos.insert("USER-100");
    historial_accesos.insert("USER-100");
    historial_accesos.insert("USER-205");

    // 4. Análisis de repeticiones con count()
    size_t total_100 = historial_accesos.count("USER-100");
    std::cout << "'USER-100' registró " << total_100 << " accesos.\n";

    // Uso de equal_range() para obtener los límites de las repeticiones
    auto rango = historial_accesos.equal_range("USER-100");
    std::cout << "Iterando sobre los elementos devueltos por equal_range:\n";
    for (auto it = rango.first; it != rango.second; ++it)
    {
        std::cout << " - Acceso registrado: " << *it << "\n";
    }

    // 5. Eliminación de una sola ocurrencia mediante iterador
    auto it_borrar = historial_accesos.find("USER-100");
    if (it_borrar != historial_accesos.end())
    {
        historial_accesos.erase(it_borrar);
        std::cout << "\nSe eliminó un solo registro de 'USER-100'.\n";
    }

    // Verificación de los elementos restantes
    std::cout << "Accesos restantes para 'USER-100': "
              << historial_accesos.count("USER-100") << "\n";

    return 0;
}