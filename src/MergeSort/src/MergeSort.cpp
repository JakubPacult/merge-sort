/**
 * @file MergeSort.cpp
 * @brief Implementacja metod klasy szablonowej MergeSort oraz jej jawne instancjacje.
 */

#include "MergeSort.hpp"

template <typename T>
void MergeSort<T>::merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tymczasowe wektory przechowujące lewą i prawą podtablicę
    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;    // Indeks początkowy pierwszej podtablicy
    int j = 0;    // Indeks początkowy drugiej podtablicy
    int k = left; // Indeks początkowy scalanej podtablicy

    // Scalanie elementów z powrotem do wektora głównego w kolejności rosnącej
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Przepisanie pozostałych elementów z L (jeśli istnieją)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Przepisanie pozostałych elementów z R (jeśli istnieją)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void MergeSort<T>::sortRecursive(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        sortRecursive(arr, left, mid);
        sortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

template <typename T>
void MergeSort<T>::sort(std::vector<T>& arr) {
    if (!arr.empty()) {
        sortRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
    }
}

// Jawne instancjacje szablonu wymagane przy rozdzieleniu deklaracji i definicji
template class MergeSort<int>;
template class MergeSort<long int>;
template class MergeSort<float>;
template class MergeSort<double>;