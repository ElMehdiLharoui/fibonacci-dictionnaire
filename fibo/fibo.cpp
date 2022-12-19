#include <iostream>
#include <vector>

using namespace std;

double fibonacci(vector <double>& cachedValues, double n)
{
    // base case
    if (n == 0)
        return 0;
    // if value already computed return it 
    if (cachedValues[n] != 0)
        return cachedValues[n];

    // otherwise calculate the solution and store it
    cachedValues[n] = fibonacci(cachedValues, n - 1) + fibonacci(cachedValues, n - 2);

    // finally return the solution
    return cachedValues[n];
}
void display(vector <double>& cachedValues)
{
    for (int i = 0; i <= cachedValues.size()-1; i++)
        cout << cachedValues[i] << endl;
}
int main()
{
    cout << "Enter a number: " << endl;
    int n;
    cin >> n;

    //dynamic programming vector of size n with initial value of 0
    vector <double> cachedValues(n, 0);
    cachedValues[1] = 1;

    cout << "Fibonacci Series of " << n << " is : " << fibonacci(cachedValues, n - 1) << endl;
    display(cachedValues);
        
}
