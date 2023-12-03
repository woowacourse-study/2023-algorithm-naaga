import java.util.*;

public class 13975 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder stringBuilder = new StringBuilder();
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int k = scanner.nextInt();
            PriorityQueue<Long> queue = new PriorityQueue<>();
            for (int j = 0; j < k; j++) {
                queue.add(scanner.nextLong());
            }
            long count = 0;
            while (queue.size() > 1) {
                Long poll1 = queue.poll();
                Long poll2 = queue.poll();
                long temp = poll1 + poll2;
                count += temp;
                queue.add(temp);
            }
            stringBuilder.append(count)
                    .append(System.lineSeparator());
        }
        System.out.println(stringBuilder);
    }
}
