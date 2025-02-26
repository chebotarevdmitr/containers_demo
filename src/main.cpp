#include <iostream>
#include "sequential_container.h" // Ensure this path is correct
#include "list_container.h" // Ensure this path is correct

// Шаблонная функция для тестирования любого контейнера
template <typename Container>
void test_container(const std::string& container_name) {
    std::cout << "=== Testing " << container_name << " ===\n";

    Container c;

    // 1. Добавление 0-9
    for (int i = 0; i < 10; ++i) {
        c.push_back(i);
    }

    // 2. Вывод элементов
    std::cout << "After push_back(0-9): ";
    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << "\nSize: " << c.size() << "\n";

    // 3. Удаление 3-го, 5-го, 7-го элементов (индексы 2, 4, 6)
    c.erase(2);
    c.erase(4 - 1); // После первого удаления размер уменьшился
    c.erase(6 - 2); // После двух удалений

    std::cout << "After erase(2,4,6): ";
    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << "\nSize: " << c.size() << "\n";

    // 4. Добавление 10 в начало
    c.insert(0, 10);
    std::cout << "After insert(0,10): ";
    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";

    // 5. Добавление 20 в середину
    c.insert(c.size() / 2, 20);
    std::cout << "After insert(middle,20): ";
    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";

    // 6. Добавление 30 в конец
    c.push_back(30);
    std::cout << "Final state: ";
    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n\n";
}

int main() {
    test_container<SequentialContainer<int>>("Sequential Container");
    test_container<ListContainer<int>>("List Container");
    return 0;
}