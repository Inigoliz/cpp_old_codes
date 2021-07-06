// BREAK: sale del bucle inicial

#include <iostream>

using namespace std;

int main() {
    float number, sum = 0.0;
    bool a = true;

    // test expression is always true
    while (a)
    {
        cout << "Enter a number: ";
        cin >> number;

        if (number != 0.0)
        {
            sum += number;
        }
        else
        {
            // terminates the loop if number equals 0.0
            break;
        }

    }
    cout << "Sum = " << sum << "\n";

    return 0;
}
