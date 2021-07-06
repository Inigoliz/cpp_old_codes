// CONTINUE: se salta el bucle y vuelve a la condición inicial

#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        if ( i == 6 || i == 9)
        {
            continue;
        }
        cout << i << "\t";
    }
    return 0;
}
