Imports System

Module Program
    Sub Main(args As String())
        Dim GivenNumber As ULong = 600851475143
        Dim Index As ULong = 2
        Dim IsPrimeFactor As ULong = 0
        Dim LargestPrimeFactor As ULong = 0

        While Index <= GivenNumber
            If IsPrime(Index) Then
                'Console.WriteLine("Prime number: {0}", Index)
                IsPrimeFactor = GivenNumber Mod Index
                If IsPrimeFactor = 0 Then
                    'Console.WriteLine("Prime factor: {0}", Index)
                    GivenNumber /= Index
                    LargestPrimeFactor = Index
                End If
            End If
            Index += 1
        End While

        Console.WriteLine(LargestPrimeFactor)
        Console.ReadLine()

    End Sub

    Function IsPrime(ByVal toNumber As ULong) As Boolean
        For index As Integer = 2 To toNumber
            If toNumber Mod index = 0 And index <> toNumber Then
                Return False
            End If
        Next
        Return True
    End Function
End Module
