#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int main() 
{
    clock_t begin = clock();

    int input;
    int largestCount = 0;
    size_t resultNumber = 2;

    // start number is 2
    for (size_t i = 2; i < 1000000; i++)
    {
        size_t number = i;
        int count = 1;
        while (number != 1)
        {
            if (number % 2 == 0)
            {
                number = number / 2;
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
        //cout << i << ": count is " << count << endl;
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Largest count: " << largestCount << endl;
    cout << "Result number: " << resultNumber << endl;
    cout << "Elapsed time: " << elapsed_secs << "ms" << endl;
    
    cout << "To end of program, input any character and enter...";
    cin >> input;
    return 0;
}