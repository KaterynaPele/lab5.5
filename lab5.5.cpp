#include <iostream>
using namespace std;

// Глобальна змінна для відстеження максимальної глибини рекурсії
int maxDepth = 0;

// Обгортка з 4 аргументів (щоб виклики countWays(m,x,y,z) працювали)
int countWays(int m, int x, int y, int z);

// Рекурсивна функція для підрахунку кількості способів
int countWays(int m, int x, int y, int z, int depth) { // убрано =1
    // Оновлюємо максимальну глибину, якщо потрібно
    if (depth > maxDepth)
        maxDepth = depth;

    // Якщо сума рівна 0 — є 1 спосіб (нічого не додавати)
    if (m == 0)
        return 1;

    // Якщо сума стала від’ємною — такого способу не існує
    if (m < 0)
        return 0;

    // Рекурсивні виклики з передачею поточної глибини +1
    return countWays(m - x, x, y, z, depth + 1)
        + countWays(m - y, x, y, z, depth + 1)
        + countWays(m - z, x, y, z, depth + 1);
}

// Реалізація обгортки: викликає основну функцію з depth = 1
int countWays(int m, int x, int y, int z) {
    maxDepth = 0;             // скидаємо глибину перед кожним викликом (зручно для тестів)
    return countWays(m, x, y, z, 1);
}

int main() {
    int m;      // сума (копійки)
    int x, y, z; // номінали марок

    cout << "Enter the total amount (m): ";
    cin >> m;
    cout << "Enter three stamp denominations (x y z): ";
    cin >> x >> y >> z;

    // Виклик рекурсивної функції
    int result = countWays(m, x, y, z);

    cout << "Number of different ways to pay " << m
        << " cents: " << result << endl;

    cout << "Maximum recursion depth reached: " << maxDepth << endl;

    return 0;
}
