#ifndef WORLD_H
#define WORLD_H

// Размеры мира по умолчанию
#define WIDTH 25
#define HEIGHT 25

// Функция для подсчета живых соседей у клетки (y, x)
int count_neighbors(int world[HEIGHT][WIDTH], int y, int x);

// Функция для перехода к следующему поколению
void next_generation(int world[HEIGHT][WIDTH]);

#endif