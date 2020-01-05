using System;

namespace Problem19
{
    class Program
    {
        static void Main(string[] args)
        {
            int sundayCount = 0;
            for (int year = 1901; year <= 2000; year++)
            {
                for (int month = 1; month <= 12; month++)
                {
                    sundayCount += new DateTime(year, month, 1).DayOfWeek == DayOfWeek.Sunday ? 1 : 0;
                }
            }
            
            Console.WriteLine(sundayCount);
        }
    }
}