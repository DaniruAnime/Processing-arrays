#include <iostream>

using namespace std;

// Метод для вывода новой матрицы
void printMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    setlocale(LC_ALL,"rus");

    int n, k;

    cout << "Введите размер квадратной матрицы: ";
    cin >> n;

    int V[100][100]; // Заданная квадратная матрица "V"
    int W[100][100]; // Сформированная матрица "W"

    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> V[i][j];
        }
    }

    cout << "Введите номер строки и столбца для удаления (k): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Неправильное значение (k)" << endl;
        return 1;
    }

    --k; // Преобразование "k" для индексации с 0

    cout << "Исходная матрица: " << endl;
    printMatrix(V, n);

    // Формирование новой матрицы "W"
    int new_size = n - 1; // Новый размер матрицы "W"
    int rowW = 0, colW = 0; // Индексы для новой матрицы "W"

    for (int i = 0; i < n; ++i) {
        if (i == k) continue; // Пропускаем "k-ую" строку
        colW = 0;
            for (int j = 0; j < n; ++j) {
                if (j == k) continue; // Пропускаем "k-ый" столбец
                W[rowW][colW] = V[i][j];
                ++colW;
            }
        ++rowW;
    }

    cout << "Матрица после удаления k-ой строки и столбца: 7" << endl;
    printMatrix(W, new_size);

    return 0;
}
