package programmers.y2023.kokodak.set7;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class BOJ22233 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String keyword = scanner.next();
            map.put(keyword, 1);
        }

        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String line = scanner.next();
            String[] kws = line.split(",");
            for (String keyword : kws) {
                map.remove(keyword);
            }
            stringBuilder.append(map.size())
                    .append(System.lineSeparator());
        }
        System.out.println(stringBuilder);
    }
}
