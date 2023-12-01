package programmers.y2023.kokodak.set7;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class BOJ15989 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int x = scanner.nextInt();
        StringBuilder stringBuilder = new StringBuilder();
        
        for (int i = 0; i < x; i++) {
            int n = scanner.nextInt();
            int count = 0;
            for (int j = 0; j <= n / 3; j++) { // 3
                int o1 = n - (j * 3);
                count += o1 / 2 + 1;
            }
            stringBuilder.append(count)
                    .append(System.lineSeparator());
        }
        System.out.println(stringBuilder);
    }
}
