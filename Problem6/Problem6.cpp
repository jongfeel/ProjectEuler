#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int input;
    int n = 100;
    
    int TheSquareOfTheSum = floor(pow( (n * (n + 1)) / 2.0, 2.0));
    int TheSumOfTheSqures = (n * (n + 1) * (2*n + 1)) / 6.0;

    int result = TheSquareOfTheSum - TheSumOfTheSqures;

    cout << result << endl;
    cout << "To end of program, input any character and enter...";
    cin >> input;
    return 0;
}