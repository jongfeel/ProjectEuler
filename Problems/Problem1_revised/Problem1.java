public class Problem1 {

    public static int SumOfAP(int n, int a, int l) {
        return n * (a + l) / 2;
    }

    public static void main(String[] args) {
        int sum = SumOfAP(333, 3, 999) + SumOfAP(199, 5, 995) - SumOfAP(66, 15, 990);
        System.out.println(sum);
    }
}