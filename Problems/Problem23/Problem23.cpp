#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool IsAbundant(int number)
{
    int sumOfProperDivisors = 0;
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sumOfProperDivisors += i;
        }
    }
    return sumOfProperDivisors > number;
}

int main() 
{
    vector<int> NotSumOfTwoAbundantNumbers(28124);
    vector<int> AbundantNumbers;
    for (int i = 28123; i > 0; i--)
    {
        NotSumOfTwoAbundantNumbers[i] = i;
        if (IsAbundant(i))
        {
            AbundantNumbers.push_back(i);
            for (int abundantNumber : AbundantNumbers)
            {
                int sumOfTwoAbundantNumber = abundantNumber + i;
                if (sumOfTwoAbundantNumber <= 28123)
                {
                    NotSumOfTwoAbundantNumbers[sumOfTwoAbundantNumber] = 0;
                }
            }
        }        
    }

    int sum = std::accumulate(NotSumOfTwoAbundantNumbers.begin(), NotSumOfTwoAbundantNumbers.end(), 0);
    cout << sum << endl;

    int input;
    cout << "To end of program, input any character and enter..." << endl;
    cin >> input;
    return 0;
}