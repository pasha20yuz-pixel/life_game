#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // для sleep()

#include "world.h"  // Подключаем наш модуль с логикой

/**
 * Заполняет мир случайными значениями.
 * Вероятность появления живой клетки - примерно 25%.
 */
void init_world_random(int world[HEIGHT][WIDTH]) {
    // Инициализируем генератор случайных чисел
    srand(time(NULL));
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // rand() % 4 дает 0, 1, 2 или 3
            // Условие rand() % 4 == 0 выполняется с вероятностью ~25%
            world[y][x] = (rand() % 4 == 0) ? 1 : 0;
        }
    }
}

/**
 * Заполняет мир известным паттерном "Планер" (Glider).
 * Это простейший двигающийся паттерн для тестирования.
 */
void init_world_glider(int world[HEIGHT][WIDTH]) {
    // Сначала очищаем мир (все клетки мертвые)
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            world[y][x] = 0;
        }
    }
    
    // Устанавливаем живые клетки для планера
    // Планер будет двигаться вниз-вправо по диагонали
    world[1][2] = 1;
    world[2][3] = 1;
    world[3][1] = 1;
    world[3][2] = 1;
    world[3][3] = 1;
}

/**
 * Выводит мир в консоль.
 * 'X' - живая клетка, '.' - мертвая.
 */
void print_world(int world[HEIGHT][WIDTH]) {
    // Очищаем экран (работает в Linux/macOS и Windows 10+)
    printf("\033[2J\033[1;1H");  // Аналог system("cls") или system("clear")
    
    // Выводим верхнюю границу
    for (int x = 0; x < WIDTH + 2; x++) printf("#");
    printf("\n");
    
    // Выводим поле
    for (int y = 0; y < HEIGHT; y++) {
        printf("#");  // Левая граница
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", world[y][x] ? 'X' : '.');
        }
        printf("#\n");  // Правая граница
    }
    
    // Выводим нижнюю границу
    for (int x = 0; x < WIDTH + 2; x++) printf("#");
    printf("\n");
}

int main() {
    // Создаем и инициализируем мир
    int world[HEIGHT][WIDTH];
    
    printf("Выберите начальную конфигурацию:\n");
    printf("1. Случайное заполнение (~25%% живых клеток)\n");
    printf("2. Планер (Glider) - тестовый паттерн\n");
    printf("Ваш выбор: ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        init_world_random(world);
    } else {
        init_world_glider(world);
    }
    
    // Главный игровой цикл
    int generation = 0;
    while (1) {
        printf("Поколение: %d\n", generation++);
        print_world(world);
        
        // Переходим к следующему поколению
        next_generation(world);
        
        // Пауза 0.5 секунды между поколениями
        // Можно изменить на usleep(200000) для 0.2 секунды
        sleep(1);  // 1 секунда
        
        // Для выхода из цикла можно добавить условие
        // if (generation > 50) break;
    }
    
    return 0;
}