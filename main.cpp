#include <iostream>

using namespace std;

struct Point{
    int x = -1, y = -1, depth = 0;
};

void add_point_to_queue(Point point,
                         Point *queue,
                         bool ( &maze )[100][100],
                         int &queue_end_pointer)
{
    if (maze[point.y][point.x])
    {
        point.depth += 1;
        queue[queue_end_pointer] = point;
        queue_end_pointer += 1;
    }
}

bool in_check(Point point, Point ( &check_mas )[10000], int &end_check_mas_pointer)
{
    for (int i = 0; i < end_check_mas_pointer; ++i) {
        if (check_mas[i].x == point.x and check_mas[i].y == point.y)
        {
            return true;
        }
    }
    return false;
}

void add_in_check(Point point, Point ( &check_mas )[10000], int &end_check_mas_pointer)
{
    check_mas[end_check_mas_pointer] = point;
    end_check_mas_pointer += 1;
}

int bfs(bool ( &maze )[100][100], int n, Point start) {
    Point check[10000], queue[10000], now_point, next_point;
    int queue_now_pointer = 0, queue_end_pointer = 1, end_check_mas_pointer = 0;
    queue[0] = start;
    while (queue_now_pointer != queue_end_pointer) {
        now_point = queue[queue_now_pointer];
        if (now_point.x == 0 or now_point.x == n - 1 or now_point.y == 0 or now_point.y == n - 1) {
            return queue[queue_now_pointer].depth;
        } else {
            if (not in_check(now_point, check, end_check_mas_pointer)) {
                add_in_check(now_point, check, end_check_mas_pointer);

                next_point = now_point;
                next_point.x += 1;
                if (maze[next_point.y][next_point.x] and not in_check(next_point, check, end_check_mas_pointer)){
                add_point_to_queue(next_point, queue, reinterpret_cast<bool (&)[100][100]>(maze),queue_end_pointer);}

                next_point = now_point;
                next_point.x -= 1;
                if (maze[next_point.y][next_point.x] and not in_check(next_point, check, end_check_mas_pointer)){
                    add_point_to_queue(next_point, queue, reinterpret_cast<bool (&)[100][100]>(maze),queue_end_pointer);}

                next_point = now_point;
                next_point.y += 1;
                if (maze[next_point.y][next_point.x] and not in_check(next_point, check, end_check_mas_pointer)){
                    add_point_to_queue(next_point, queue, reinterpret_cast<bool (&)[100][100]>(maze),queue_end_pointer);}

                next_point = now_point;
                next_point.y -= 1;
                if (maze[next_point.y][next_point.x] and not in_check(next_point, check, end_check_mas_pointer)){
                    add_point_to_queue(next_point, queue, reinterpret_cast<bool (&)[100][100]>(maze),queue_end_pointer);}

                queue_now_pointer += 1;
            }
        }
    }
    return -1;
}


int main() {
    int n;
    Point start;
    bool maze[100][100];
    //max size 100*100
    cin >> n;
    cin >> start.y >> start.x;
    // start not wall
    // 0 - wall, 1 - void
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    cout << bfs(maze, n, start);
}




























































/*
#include "iostream"

using namespace std;

struct Dot
{
    int x = 0, y = 0;
};

class Vector
{
public:
    Dot start, end;

    void get_coordinate ()
    {
        x = end.x - start.x;
        y = end.y - start.y;
    }

private:
    int x = 0, y = 0;
};

class Target
{
public:
    Vector vector_mas[100];
};

int main()
{
    int n;
    Dot bullet, temp_last, temp_now;
    Target target;
    cin >> bullet.x >> bullet.y;
    cin >> n;
    cin >> temp_last.x >> temp_last.y;
    for (int i = 0; i < n - 1; ++i) {
        cin >> temp_now.x >> temp_now.y;
        target.vector_mas[i].start = temp_last;
        target.vector_mas[i].end = temp_now;
        target.vector_mas[i].get_coordinate();
        temp_last = temp_now;
    }

}
*/




/*
#include "iostream"
#include "MxQdP5s9.h"

using namespace std;

int main() {
    int n, c = 1;
    big_integer a("1");
    cin >> n;
    while (true)
    {
        if (a % n == 0)
        {
            cout << c;
            return 0;
        } else
        {
            a = a * 10 + 1;
            c += 1;
        }
    }

}
*/





























/*
Maze
#include <iostream>

using namespace std;

struct Point{
    int x = 0, y = 0, depth = 0;
};

void print_maze(bool maze[100][100], int n){
    for (int i=0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << maze[i][j] << " ";
        cout << '\n';
    }
}

void add_in_check(Point point, Point check_mas[10000])
{

}

bool in_check(Point point, Point check_mas[10000])
{
    return true;
}

int bfs(bool maze[100][100], int n, Point start)
{
    Point check[10000], queue[10000], next_point;
    int pointer = 0, queue_end_pointer = 0, check_pointer = 0;
    queue[0] = start;
    check[0] = start;
    while (pointer != queue_end_pointer + 1)
    {
        next_point = queue[pointer];
        next_point.x += 1;
        if (maze[next_point.y][next_point.x] = 1 and not in_check(next_point, check))
        {
            pointer += 1;
            continue;
        }
    }
    return 0;
}


int main()
{
    int n;
    Point start;
    bool maze[100][100];
    //max size 100*100
    cin >> n;
    cin >> start.y >> start.x;
    // start not wall
    for (int i=0; i < n; i++)
        for (int j=0; j < n; j++)
            cin >> maze[i][j];
    print_maze(maze, n);

}
*/