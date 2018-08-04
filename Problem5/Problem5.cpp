#include <iostream>
using namespace std;

int main() 
{
    int input;

    for (int i=2520; i<252000000; i+=2520)
    {
        if (i % 11 == 0 && i % 13 == 0 && i % 16 == 0 && i % 17 == 0 && i % 19 == 0)
        {
            cout << i << endl;
            break;
        }
    }

    cin >> input;
    return 0;
}