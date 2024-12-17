#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAP_WIDTH 5
#define MAP_HEIGHT 24

int map[MAP_WIDTH][MAP_HEIGHT] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void bresenham(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;

    while (1)
	{
        // Verifica se o ponto atual é uma parede
        if (map[y0][x0] == 1)
		{	
            printf("Wall hit at (%d, %d)\n", y0, x0);
            break;
        }

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
		{
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
		{
            err += dx;
            y0 += sy;
        }
    }
}

void ray_casting(int origin_x, int origin_y, double angle, int max_distance)
{
    int x1 = origin_x + (int)(max_distance * cos(angle));
    int y1 = origin_y + (int)(max_distance * sin(angle));

    bresenham(origin_x, origin_y, x1, y1);
}

int main()
{
    int		origin_x = 1;
    int		origin_y = 1;
    double	angle = 3.14;
    // float angle = ;  // Ângulo em radianos (45 graus)

    int max_distance = 30;

    ray_casting(origin_x, origin_y, angle, max_distance);

    return 0;
}