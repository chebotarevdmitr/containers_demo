// list_container.h
#ifndef LIST_CONTAINER_H
#define LIST_CONTAINER_H

#include <stdexcept>

template <typename T>
class ListContainer {
private:
    // Узел списка
    struct Node {
        T value;       // Значение
        Node* prev;    // Указатель на предыдущий узел
        Node* next;    // Указатель на следующий узел

        Node(const T& val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;        // Первый элемент
    Node* tail;        // Последний элемент
    size_t size_;      // Текущий размер

public:
    // Конструктор
    ListContainer() : head(nullptr), tail(nullptr), size_(0) {}

    // Деструктор (очищает память)
    ~ListContainer() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Добавление в конец
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size_++;
    }

    // Вставка на позицию index
    void insert(size_t index, const T& value) {
        if (index > size_) {
            throw std::out_of_range("Index out of range");
        }

        Node* newNode = new Node(value);
        if (index == 0) { // Вставка в начало
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
        } else { // Вставка в середину или конец
            Node* current = get_node(index - 1);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
        size_++;
    }

    // Удаление элемента по индексу
    void erase(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }

        Node* toDelete = get_node(index);
        if (toDelete->prev) {
            toDelete->prev->next = toDelete->next;
        } else {
            head = toDelete->next;
        }

        if (toDelete->next) {
            toDelete->next->prev = toDelete->prev;
        } else {
            tail = toDelete->prev;
        }

        delete toDelete;
        size_--;
    }

    // Текущий размер
    size_t size() const {
        return size_;
    }

    // Доступ по индексу (небезопасная версия)
    T& operator[](size_t index) {
        return get_node(index)->value;
    }

    // Доступ по индексу (const версия)
    const T& operator[](size_t index) const {
        return get_node(index)->value;
    }

private:
    // Вспомогательный метод для доступа к узлу по индексу
    Node* get_node(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }
};

#endif // LIST_CONTAINER_H