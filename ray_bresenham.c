#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void bresenham(int x1, int y1, int x2, int y2, int (*points)[2], int *count)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    *count = 0;
    while (1)
	{
        points[*count][0] = x1;
        points[*count][1] = y1;
        (*count)++;
        if (x1 == x2 && y1 == y2)
			break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

bool is_intercepted(int x, int y, int x1, int y1, int x2, int y2, int square_size)
{
    int points[1000][2]; // Array para armazenar os pontos da linha
    int count;
    bresenham(x1, y1, x2, y2, points, &count);

    for (int i = 0; i < count; i++) {
        int px = points[i][0];
        int py = points[i][1];
        if (x <= px && px < x + square_size && y <= py && py < y + square_size) {
            return true;
        }
    }
    return false;
}

int main()
{
    int x = 10, y = 10; // canto inferior esquerdo do quadrado
    int x1 = 5, y1 = 5; // ponto inicial do segmento de reta
    int x2 = 21, y2 = 10; // ponto final do segmento de reta
    int square_size = 10;

    if (is_intercepted(x, y, x1, y1, x2, y2, square_size)) {
        printf("O quadrado é interceptado pelo segmento de reta.\n");
    } else {
        printf("O quadrado não é interceptado pelo segmento de reta.\n");
    }

    return 0;
}