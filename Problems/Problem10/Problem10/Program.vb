Module Program
    Sub Main(args As String())
        'Dim StartTime As DateTime = DateTime.Now
        Dim UntilNumber As Integer = 2000000
        Dim SumOfThePrimes As ULong = 0
        Dim Primes As List(Of Long) = Enumerable.Range(0, UntilNumber).Select(Of Long)(Function(p) p).ToList()

        Primes(1) = 0   '1 is not prime
        For index = 2 To Math.Sqrt(UntilNumber)
            If Primes(index) <> 0 Then
                For innerIndex = index * 2 To Primes.Count - 1 Step index
                    Primes(innerIndex) = 0
                Next
            End If
        Next

        Console.WriteLine(Primes.Sum())
        'Dim EndTime As DateTime = DateTime.Now
        'Dim ElapsedTime As TimeSpan = EndTime - StartTime
        'Console.WriteLine(ElapsedTime.TotalSeconds)
        Console.ReadLine()

    End Sub
End Module
