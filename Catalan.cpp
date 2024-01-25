#include <iostream>
using namespace std;

 int Catalan(int n){
    int total = 0;
    if(n <= 1) 
    {
        return 1;
    }
    else 
    {
    for(int i = 0; i < n; i++) {
        total += Catalan(n) * Catalan(n - i);
    }
    }
 
    return total;
}

int main(){
    cout << Catalan(10) << endl;
    return 0;
};