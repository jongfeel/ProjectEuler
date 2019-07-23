#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int input;
    int largestCount = 0;
    int resultNumber = 2;

    // start number is 2
    for (size_t i = 2; i <= 1000000; i++)
    {
        int number = i;
        int count = 0;
        while (number != 1)
        {
            if (number % 2 == 0)
            {
                number /= 2;
            }
            else
            {
                number = 3 * number + 1;
            }
            count++;
        }
        if (count > largestCount)
        {
            largestCount = count;
            resultNumber = i;
        }
        // cout << i << ": count is " << count << endl;
    }

    cout << "Largest count: " << largestCount << endl;
    cout << "Result number: " << resultNumber << endl;
    
    cout << "To end of program, input any character and enter...";
    cin >> input;
    return 0;
}