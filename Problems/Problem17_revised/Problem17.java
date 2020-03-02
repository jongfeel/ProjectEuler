public class Problem17 {
    public static void main(final String[] args) {
        int sum = 0;
        for (int i = 1; i <= 1000; i++) {
            String numString = "";
            
            int thousand = i / 1000;
            int thousandMod = i % 1000;
            int hundred = thousandMod / 100;
            int hundredMod = thousandMod % 100;
            int ten = hundredMod / 10;
            int tenMod = hundredMod % 10;
            int one = tenMod;

            if (thousand > 0) {
                if (thousand == 1) {
                    numString += "one";
                }
                numString += "thousand";
            }

            if (thousandMod > 0 && hundred > 0) {
                switch (hundred) {
                    case 1:
                        numString += "one";
                        break;
                    case 2:
                        numString = "two";
                        break;
                    case 3:
                        numString = "three";
                        break;
                    case 4:
                        numString = "four";
                        break;
                    case 5:
                        numString = "five";
                        break;
                    case 6:
                        numString = "six";
                        break;
                    case 7:
                        numString = "seven";
                        break;
                    case 8:
                        numString = "eight";
                        break;
                    case 9:
                        numString = "nine";
                        break;
                    default:
                        break;
                }
                numString += "hundred";
                if (hundredMod != 0)
                {
                    numString += "and";
                }
            }

            if (hundredMod > 0 && ten > 0) {
                if (ten == 1)
                {
                    switch (tenMod) {
                        case 0:
                            numString += "ten";
                            break;
                        case 1:
                            numString += "eleven";
                            break;
                        case 2:
                            numString += "twelve";
                            break;
                        case 3:
                            numString += "thirteen";
                            break;
                        case 4:
                            numString += "fourteen";
                            break;
                        case 5:
                            numString += "fifteen";
                            break;
                        case 6:
                            numString += "sixteen";
                            break;
                        case 7:
                            numString += "seventeen";
                            break;
                        case 8:
                            numString += "eighteen";
                            break;
                        case 9:
                            numString += "nineteen";
                            break;
                        default:
                            break;
                    }
                }

                switch (ten) {
                    case 2:
                        numString += "twenty";
                        break;
                    case 3:
                        numString += "thirty";
                        break;
                    case 4:
                        numString += "forty";
                        break;
                    case 5:
                        numString += "fifty";
                        break;
                    case 6:
                        numString += "sixty";
                        break;
                    case 7:
                        numString += "seventy";
                        break;
                    case 8:
                        numString += "eighty";
                        break;
                    case 9:
                        numString += "ninety";
                        break;
                    default:
                        break;
                }
            }

            if (tenMod > 0 && one > 0 && ten != 1) {
                switch (one) {
                    case 1:
                        numString += "one";
                        break;
                    case 2:
                        numString += "two";
                        break;
                    case 3:
                        numString += "three";
                        break;
                    case 4:
                        numString += "four";
                        break;
                    case 5:
                        numString += "five";
                        break;
                    case 6:
                        numString += "six";
                        break;
                    case 7:
                        numString += "seven";
                        break;
                    case 8:
                        numString += "eight";
                        break;
                    case 9:
                        numString += "nine";
                        break;
                    default:
                        break;
                }
            }

            //System.out.println(numString);
            sum += numString.length();
        }
        System.out.println();
        System.out.println(sum);
    }
}