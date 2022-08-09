#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
#define N 20
bool gameOver;

class human
{
private:
    int age = 0, height = 0, weight = 0, x_init = N / 2, y_init = N / 2;

public:
    int x = x_init;
    int y = y_init;
    float d = 0;

    void create(int a, int h, int w)
    {
        age = a;
        height = h;
        weight = w;
    }

    void print()
    {
        cout << "\nAge = " << age << "\tHeight = " << height << "\tweight = " << weight << endl;
    }

    void draw()
    {
        system("cls");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == x && j == y)
                    cout << "0";
                else cout << ".";
            }
            cout << endl;
        }
    }

    void play()
    {
        switch (_getch())
        {
        case 'w':
            if (x > 0)
                x--;
            break;
        case 's':
            if (x < N - 1)
                x++;
            break;
        case 'a':
            if (y > 0)
                y--;
            break;
        case 'd':
            if (y < N - 1)
                y++;
            break;
        case 'z':
            gameOver = true;
        }
    }

    void calc_d()
    {
        d = sqrt(pow(x - x_init, 2) + pow(y - y_init, 2));
    }

    void print_d()
    {
        cout << "\nDistance: " << d;
    }
};


int main()
{
    human h;
    h.create(23, 190, 81);
    h.print();
    cout << "Game Control:\n'W' - Up\n'S' - Down\n'D' - Right\n'A' - Left\n'Z' - Quit\n";
    cout << "\n\npress any key...\n";
    _getch();
    gameOver = false;
    while (!gameOver)
    {
        h.draw();
        h.play();
    }

    h.calc_d();
    h.print_d();

    return 0;
}

