//Catalan class that calculates using the 
//recursive formula computing the nth number

#include <iostream>
using namespace std;


//Catalan method. This is where mainly the 
//Code computes through recursion until basecase hits
//1
 int Catalan(int n){
    if(n <= 1) 
    {
        return 1;
    }
    else 
    {
        long long int total = 0;
        for(int i = 0; i < n; i++) {
            total += Catalan(i) * Catalan(n - i - 1);
        }
        return total;
    }
}

//Main method which gets an integer from the terminal
//and stores it in int n. Checks if negative #'s pass through
//which are not allowed
int main(int argc, char* argv[]){
    //atoi transfers character into integer and uses 
    //the first 2nd index argument as the first index (0)
    //is the exe file
    int n = atoi(argv[1]);
    if(n < 0) 
    {   
        cout << "Cant Catalan a negative number.";
    }
    else 
    {
        cout << "catalan " << n << " " << endl << Catalan(n) << endl;
    }
    return 0;
}