package programmers.y2023.kokodak.set7;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BOJ17127 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }

        int max = 0;
        int a = 1;
        int b = 1;
        int c = 1;
        int d = 1;

        for (int i = 0; i < n - 3; i++) {
            a *= list.get(i);
            b = 1;
            for (int j = i + 1; j < n - 2; j++) {
                b *= list.get(j);
                c = 1;
                for (int k = j + 1; k < n - 1; k++) {
                    c *= list.get(k);
                    d = 1;
                    for (int l = k + 1; l < n; l++) {
                        d *= list.get(l);
                        int temp = a + b + c + d;
                        max = Math.max(max, temp);
                    }
                }
            }
        }
        System.out.println(max);
    }
}
