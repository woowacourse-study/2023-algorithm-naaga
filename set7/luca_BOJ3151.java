package programmers.y2023.kokodak.set7;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BOJ3151 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        List<Integer> aj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            aj.add(scanner.nextInt());
        }
        long count = 0;
        aj.sort((o1, o2) -> o1 - o2);
        int size = aj.size();
        for (int i = 0; i < size - 2; i++) {
            Integer a = aj.get(i);
            for (int j = i + 1; j < size - 1; j++) {
                Integer b = aj.get(j);
                int c = -(a + b);
                int minMin = j + 1;
                int minMax = size - 1;
                int minMid = (minMin + minMax) / 2;
                while (minMin <= minMax) {
                    minMid = (minMin + minMax) / 2;
                    Integer temp = aj.get(minMid);
                    if (temp >= c) {
                        minMax = minMid - 1;
                    } else {
                        minMin = minMid + 1;
                    }
                }
                int maxMin = j + 1;
                int maxMax = size - 1;
                int maxMid = (maxMin + maxMax) / 2;
                while (maxMin <= maxMax) {
                    maxMid = (maxMin + maxMax) / 2;
                    Integer temp = aj.get(maxMid);
                    if (temp > c) {
                        maxMax = maxMid - 1;
                    } else {
                        maxMin = maxMid + 1;
                    }
                }
                if (minMin < aj.size()) {
                    count += maxMin - minMin;
                }
            }
        }
        System.out.println(count);
    }
}
