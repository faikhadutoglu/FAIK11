#include <cmath>
#include <iostream>
#include <type_traits>

// Diese Template-Funktion `my_max` gibt den größeren von zwei Werten zurück.
// Sie funktioniert mit beliebigen Datentypen T, vorausgesetzt, der > Operator ist für T definiert.
template <typename T>
auto my_max(T par_x, T par_y) -> T
{
    // Vergleicht par_x mit par_y, gibt par_x zurück, wenn es größer ist, sonst par_y.
    return (par_x > par_y) ? par_x : par_y;
}

// Diese Template-Funktion `approx_equal` prüft, ob zwei Zahlen annähernd gleich sind.
// Die Funktion nimmt zwei Werte und eine Epsilon-Schranke, innerhalb derer sie als gleich betrachtet werden.
template <typename T>
auto approx_equal(const T &par_x, const T &par_y, const double eps) -> bool
{
    // Statische Überprüfung, um sicherzustellen, dass T ein arithmetischer Typ ist.
    static_assert(std::is_arithmetic<T>::value, "macht nur Sinn für Zahlen");
    // Berechnet den absoluten Unterschied zwischen par_x und par_y und prüft, ob dieser kleiner als eps ist.
    bool res = std::abs(static_cast<double>(par_x) - static_cast<double>(par_y)) < eps;
    return res;
}

auto main() -> int
{
    // Test der Funktion `my_max` mit int-Werten.
    std::cout << my_max<int>(3, 7) << std::endl;  // Gibt den größeren der beiden Werte aus.
    // Test der Funktion `my_max` mit double-Werten.
    std::cout << my_max<double>(3.0, 7.0) << std::endl;  // Funktioniert ebenso mit Gleitkommazahlen.
    // Test der Funktion `my_max` mit char-Werten.
    std::cout << my_max<char>('g', 'e') << std::endl;  // Auch Buchstaben können verglichen werden.

    // Verschiedene Tests für die Funktion `approx_equal`, um zu prüfen, ob Zahlen annähernd gleich sind.
    std::cout << "Test 1: " << approx_equal<double>(3.0, 2.8, 0.1) << std::endl;  // Sollte false ausgeben.
    std::cout << "Test 1: " << approx_equal<double>(2.8, 3.0, 0.1) << std::endl;  // Sollte false ausgeben.
    std::cout << "Test 2: " << approx_equal<double>(3.0, 2.95, 0.1) << std::endl;  // Sollte true ausgeben.
    std::cout << "Test 2: " << approx_equal<double>(2.95, 3.0, 0.1) << std::endl;  // Sollte true ausgeben.
    std::cout << "Test 3: " << approx_equal<int>(3, 3, 0.1) << std::endl;  // Gleiche Werte, gibt true zurück.
    std::cout << "Test 4: " << approx_equal<int>(3, 2, 0.1) << std::endl;  // Sollte false ausgeben.
    // Der folgende Test würde wegen static_assert scheitern, weil std::string kein arithmetischer Typ ist.
    // std::cout << "Test 5: " << approx_equal<std::string>("g", "a", 0.1) << std::endl;

    return 0;
}
