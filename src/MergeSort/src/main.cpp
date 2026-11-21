/**
 * @file main.cpp
 * @brief Punkt wejścia programu demonstrujący działanie klasy MergeSort dla typów int i double.
 */

#include <iostream>
#include <vector>
#include <string>
#include "MergeSort.hpp"

 /**
  * @brief Pomocnicza funkcja szablonowa wypisująca zawartość wektora na standardowe wyjście.
  *
  * @tparam T Typ elementów przechowywanych w wektorze.
  * @param label Etykieta tekstowa wyświetlana przed zawartością tablicy.
  * @param vec Stała referencja do wektora, którego elementy mają zostać wypisane.
  */
template <typename T>
void printVector(const std::string& label, const std::vector<T>& vec) {
    std::cout << label << ": [ ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Główna funkcja programu.
 *
 * Tworzy dwie instancje tablic (dla typów int oraz double), sortuje je
 * przy użyciu klasy MergeSort i wypisuje stan tablic przed oraz po sortowaniu.
 *
 * @return int Kod zakończenia programu (0 oznacza poprawne wykonanie).
 */
int main() {
    // --- 1. Test dla liczb całkowitych (int) ---
    std::vector<int> intData = { 3, 27, 43, 3, 9, 82, 10 };
    MergeSort<int> intSorter;

    std::cout << "=== TEST TYPU INT ===" << std::endl;
    printVector("Przed sortowaniem", intData);

    intSorter.sort(intData);

    printVector("Po sortowaniu   ", intData);
    std::cout << std::endl;

    // --- 2. Test dla liczb zmiennoprzecinkowych (double) ---
    std::vector<double> doubleData = { 12.55, 3.14, -5.6, 42.0, 3.13, 0.0, -15.2 };
    MergeSort<double> doubleSorter;

    std::cout << "=== TEST TYPU DOUBLE ===" << std::endl;
    printVector("Przed sortowaniem", doubleData);

    doubleSorter.sort(doubleData);

    printVector("Po sortowaniu   ", doubleData);

    return 0;
}