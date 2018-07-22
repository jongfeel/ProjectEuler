Imports System

Module Program
    Sub Main(args As String())
        Dim GivenNumber As ULong = 600851475143
        Dim PrimeFactor As ULong = 2


        'While GivenNumber <= PrimeFactor

        'End While

        Dim ToNumber As ULong = 600851475143
        Dim Index As ULong = 2
        Dim Factor As ULong = 0

        While Index <= ToNumber
            If IsPrime(Index) Then
                'Console.WriteLine("Prime number: {0}", Index)
                Factor = toNumber Mod Index
                If Factor = 0 Then
                    Console.WriteLine("factor: {0}", Index)
                    toNumber /= Index
                End If
            End If
            Index += 1
        End While

        Console.WriteLine("Loop end")
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
