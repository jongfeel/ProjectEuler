using System;
using System.Linq;

namespace Problem21
{
    class Program
    {
        static int SumOfDivisor(int number) => Enumerable.Range(1, number / 2).Sum(i => number % i == 0 ? i : 0);

        /*int sum = 0;
        for (int i = 1; i <= number / 2; i++)
        {
            if (number % i == 0)
            {
                //Console.WriteLine(i);
                sum += i;
            }
        }
        return sum;*/
        
        static void Main(string[] args)
        {
            int AmicableSum = 0;
            for (int i = 1; i <= 10000; i++)
            {
                int sum1 = SumOfDivisor(i);
                int sum2 = SumOfDivisor(sum1);
                
                // case of same SumOfDivisor parameter value and return value 
                // not amicable numbers
                // 6, 28, 496, 8128

                if (sum2 == i && sum1 != sum2)
                {
                    // Console.WriteLine(i + ", " + sum1);
                    AmicableSum += i + sum2;
                }
            }

            Console.WriteLine(AmicableSum / 2);
        }
    }
}