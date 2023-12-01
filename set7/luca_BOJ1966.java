package programmers.y2023.kokodak.set7;

import java.util.*;

public class BOJ1966 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < x; i++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

            Queue<int[]> queue = new LinkedList<>();
            int[] counter = new int[10];
            for (int j = 0; j < n; j++) {
                int a = scanner.nextInt();
                int[] temp = {j, a};
                queue.add(temp);
                counter[a]++;
            }
            int count = 0;
            while (!queue.isEmpty()) {
                int[] curr = queue.poll();
                boolean flag = false;
                for (int j = curr[1] + 1; j < 10; j++) {
                    if (counter[j] > 0) {
                        flag = true;
                    }
                }
                if (flag) {
                    queue.add(curr);
                } else {
                    counter[curr[1]]--;
                    count++;
                    if (curr[0] == m) {
                        stringBuilder.append(count)
                                .append(System.lineSeparator());
                        queue.clear();
                    }
                }
            }
        }
        System.out.println(stringBuilder);
    }
}
