import java.util.stream.IntStream;

public class Problem12 {

    public static void main(String[] args) {
        for (int i = 1000; i < 100000000; i++) {
            int triangle = i * (i + 1) / 2;
            //System.out.println(triangle);

            int divisorCount = 1;   // 1 is divisor of all number
            for (int j = 2; j <= Math.sqrt(triangle); j++) {
                if (triangle % j == 0) {
                    if (triangle / j == j)
                        divisorCount++;
                    else
                        divisorCount += 2;
                }
            }
            divisorCount += triangle != 1 ? 1 : 0; // add triangle number
            
            //if (divisorCount > 200)
                //System.out.println(i + "  " + triangle + "  " + divisorCount);

            if (divisorCount >= 500) {
                System.out.println(triangle);
                break;
            }
        }
    }
}