cmake_minimum_required(VERSION 3.10)
project(ContainersDemo)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем исполняемый файл
add_executable(ContainersDemo
    src/main.cpp
    src/sequential_container.cpp
    src/list_container.cpp
)

# Указываем путь к заголовочным файлам
target_include_directories(ContainersDemo PRIVATE include)