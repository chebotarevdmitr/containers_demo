// sequential_container.h
#ifndef SEQUENTIAL_CONTAINER_H
#define SEQUENTIAL_CONTAINER_H

#include <stdexcept> // для исключений

template <typename T>
class SequentialContainer {
private:
    T* data;          // Указатель на массив элементов
    size_t capacity;  // Вместимость контейнера
    size_t size_;     // Текущее количество элементов

    // Увеличивает вместимость в 2 раза при необходимости
    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

public:
    // Конструктор по умолчанию
    SequentialContainer() : data(nullptr), capacity(0), size_(0) {}

    // Деструктор
    ~SequentialContainer() {
        delete[] data;
    }

    // Добавление элемента в конец
    void push_back(const T& value) {
        if (size_ >= capacity) {
            resize();
        }
        data[size_++] = value;
    }

    // Вставка элемента на позицию index
    void insert(size_t index, const T& value) {
        if (index > size_) {
            throw std::out_of_range("Index out of range");
        }
        if (size_ >= capacity) {
            resize();
        }
        // Сдвигаем элементы вправо
        for (size_t i = size_; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size_++;
    }

    // Удаление элемента по индексу
    void erase(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        // Сдвигаем элементы влево
        for (size_t i = index; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }
        size_--;
    }

    // Текущий размер контейнера
    size_t size() const {
        return size_;
    }

    // Доступ по индексу (небезопасная версия)
    T& operator[](size_t index) {
        return data[index];
    }

    // Доступ по индексу (const версия)
    const T& operator[](size_t index) const {
        return data[index];
    }
};

#endif // SEQUENTIAL_CONTAINER_H