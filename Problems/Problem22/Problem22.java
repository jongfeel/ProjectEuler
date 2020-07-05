import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Problem22 {

    public static void main(final String[] args) {

        System.out.println("Problem22");

        try {
            String fileContents = Files.readString(Path.of("p022_names.txt"));
            // System.out.println(fileContents);

            String removedDoubeQuote = fileContents.replace("\"", "");
            // System.out.println(removedDoubeQuote);

            String[] names = removedDoubeQuote.split(",");
            // System.out.println(names.length);
            
            List<String> nameList = Arrays.asList(names);
            Collections.sort(nameList);

            int index = 1;
            int namesSum = 0;
            for (String name : nameList) {
                int nameSum = 0;
                for (int i = 0; i < name.length(); i++) {
                    nameSum += name.charAt(i) - 64;
                }
                namesSum += nameSum * index;
                index++;
            }

            System.out.println(namesSum);

        } catch (Exception e) {
        }
    }
}