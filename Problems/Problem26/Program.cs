using System;
using System.Numerics;

namespace Problem26
{
    class Program
    {
        static bool IsPrime(double number)
        {
            if (number < 2)
            {
                return false;
            }

            double sqrt = Math.Sqrt(number);
            for (int i = 2; i <= sqrt; i++)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        static void Main(string[] args)
        {
            BigInteger dividend = BigInteger.Pow(10000000000, 100);
            for (int i = 1000; i > -1; i--)
            {
                if (IsPrime(i))
                {
                    BigInteger result = BigInteger.Divide(dividend, i);
        
                    string resultString = result.ToString();
                    string recurringCycle5digit = resultString.Substring(0, 5);

                    int recurringCycle = resultString.IndexOf(recurringCycle5digit, 5, resultString.Length - 5);

                    if (recurringCycle + 1 == i)
                    {
                        Console.WriteLine(i);
                        break;
                    }
                }
            }
        }
    }
}
