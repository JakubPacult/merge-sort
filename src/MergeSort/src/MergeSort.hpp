/**
 * @file MergeSort.hpp
 * @brief Definicja szablonowej klasy MergeSort realizującej algorytm sortowania przez scalanie.
 */

#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>

 /**
  * @class MergeSort
  * @brief Klasa szablonowa implementująca algorytm sortowania przez scalanie (Merge Sort).
  *
  * Algorytm działa w oparciu o strategię „dziel i zwyciężaj” (divide and conquer),
  * gwarantując złożoność obliczeniową O(n log n) w każdym przypadku.
  *
  * @tparam T Typ przechowywanych i sortowanych danych (np. int, long int, float, double).
  *           Typ musi wspierać operator porównania (<=).
  */
template <typename T>
class MergeSort {
private:
    /**
     * @brief Scala dwie posortowane podtablice w jedną uporządkowaną całość.
     *
     * @param arr Referencja do wektora zawierającego sortowane elementy.
     * @param left Indeks początkowy pierwszej podtablicy.
     * @param mid Indeks końcowy pierwszej podtablicy (środek podziału).
     * @param right Indeks końcowy drugiej podtablicy.
     */
    void merge(std::vector<T>& arr, int left, int mid, int right);

    /**
     * @brief Rekurencyjnie dzieli tablicę na mniejsze podproblemy i wywołuje ich scalanie.
     *
     * @param arr Referencja do wektora zawierającego sortowane elementy.
     * @param left Indeks lewej granicy aktualnie rozpatrywanego fragmentu tablicy.
     * @param right Indeks prawej granicy aktualnie rozpatrywanego fragmentu tablicy.
     */
    void sortRecursive(std::vector<T>& arr, int left, int right);

public:
    /**
     * @brief Sortuje rosnąco przekazany wektor elementów.
     *
     * Metoda stanowi publiczny interfejs klasy. Weryfikuje, czy tablica nie jest pusta,
     * a następnie uruchamia proces rekurencyjnego sortowania.
     *
     * @param arr Referencja do wektora typu T, który ma zostać posortowany w miejscu.
     */
    void sort(std::vector<T>& arr);
};

#endif // MERGESORT_HPP