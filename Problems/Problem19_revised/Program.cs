using System;

namespace Problem19_revised
{
    class Program
    {
        static void Main(string[] args)
        {
            int sundayCount = 0;
            int dayCount = 0;
            for (int year = 1900; year <= 2000; year++)
            {
                for (int month = 1; month <= 12; month++)
                {
                    int dayOfMonth = 31; // 1, 3, 5, 7, 8, 10, 12 month
                    if (month == 4 || month == 6 || month == 9 || month == 11)
                    {
                        dayOfMonth = 30;
                    }
                    else if (month == 2)
                    {
                    if (year % 4 == 0)
                    {
                        dayOfMonth = 29;
                    }
                    else
                    {
                        dayOfMonth = 28;
                    }
                    }
                    for (int day = 1; day <= dayOfMonth; day++)
                    {
                        dayCount++;
                        if (year >= 1901 && dayCount % 7 == 0 && day == 1)
                        {
                            sundayCount++;
                        }
                    }
                }
            }
            
            Console.WriteLine(sundayCount);
        }
    }
}