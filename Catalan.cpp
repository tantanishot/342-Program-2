#include <iostream>
using namespace std;

int factorial(int f) {
    if(f <= 0) 
    {
        return 1;
    }
    else 
    {
        return f * factorial(f - 1);
    }
}

int Catalan(int n) {
    return (factorial(2 * n)) / (factorial(n + 1) * factorial(n));
}

int main() {
 
    cout << Catalan(4);
    return 0;
}