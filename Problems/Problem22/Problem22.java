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

            int[] index = { 1 };
            int sum = nameList.stream().map(name -> name.chars().map(nameChar -> nameChar - 64).sum() * index[0]++).mapToInt(Integer::intValue).sum();
            System.out.println(sum);

        } catch (Exception e) {
        }
    }
}