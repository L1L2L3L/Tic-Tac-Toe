# Игра в Крестики-нолики

## Описание задачи

Этот проект представляет собой реализацию классической игры в "Крестики-нолики" на языке C++. Игра создана для демонстрации базовых принципов программирования и представляет собой консольное приложение.

## Правила игры

Игра в "Крестики-нолики" проходит на игровом поле размером 3x3. Два игрока поочередно ставят крестики (X) и нолики (O) в свободные клетки поля. Целью игры является заполнение горизонтальных, вертикальных или диагональных линий одним из символов (X или O).

## Зависимости проекта

- C++ компилятор (рекомендуется поддержка стандарта C++11 и выше)
- CMake (для сборки проекта)

## Сборка приложения

1. Убедитесь, что у вас установлен C++ компилятор и CMake.
2. Клонируйте репозиторий: `git clone https://github.com/L1L2L3L/Tic-Tac-Toe.git`
3. Перейдите в каталог проекта: `cd tic-tac-toe`
4. Создайте каталог для сборки: `mkdir build && cd build`
5. Сгенерируйте проект CMake: `cmake ..`
6. Соберите приложение: `cmake --build .`

После выполнения этих шагов у вас должно появиться исполняемое файл `tic-tac-toe`, которое можно запустить для игры в "Крестики-нолики".
