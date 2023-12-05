import java.util.Scanner;

public class 2688 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder stringBuilder = new StringBuilder();
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            long[][] map = new long[10][64];
            for (int j = 0; j <= 9; j++) {
                map[j][0] = 1;
            }
            for (int j = 1; j < n; j++) {
                for (int k = 0; k <= 9; k++) {
                    for (int l = 0; l <= k; l++) {
                        map[k][j] += map[l][j - 1];
                    }
                }
            }
            long count = 0;
            for (int j = 0; j <= 9; j++) {
                count += map[j][n - 1];
            }
            stringBuilder.append(count)
                    .append(System.lineSeparator());
        }
        System.out.println(stringBuilder);
    }
}