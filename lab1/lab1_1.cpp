#include <iostream>
#include <cmath>
using namespace std; 

int main()
{
   /* cout << "Hello Alexandr!" << endl;
    puts("Hello, world!");

    int a, b, c = 0;

    printf("input 3 numbers - ");
    scanf_s("%d %d %d", &a, &b, &c);
    printf("result %d \n", a + b + c);

    */
    int a = 0, b = 0, c = 0;

    printf("input 3 numbers for square - ");
    scanf_s("%d %d %d", &a, &b, &c);

    int d = b * b - 4 * a * c;
    cout << d << endl;
    if (d <  0) {
        cout << "No root" << endl;
    }
    else if (d == 0) {
        cout << "Root - " << ( -b / (2 * a) ) << endl;
    }
    else {
        cout << "Root 1 - " << ( ( -b + std::sqrt(d)) / (2 * a)) << endl;
        cout << "Root 2 - " << ( ( -b - std::sqrt(d)) / (2 * a)) << endl;
    }
}