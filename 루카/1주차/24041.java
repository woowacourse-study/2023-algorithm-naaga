import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class 24041 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int g = scanner.nextInt();
        int k = scanner.nextInt();

        List<int[]> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int[] temp = new int[3];
            temp[0] = scanner.nextInt();
            temp[1] = scanner.nextInt();
            temp[2] = scanner.nextInt();
            list.add(temp);
        }

        long lo = 0;
        long hi = Integer.MAX_VALUE;

        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            BigDecimal count = new BigDecimal(0);
            List<BigDecimal> longs = new ArrayList<>();
            for (int[] ints : list) {
                int s = ints[0];
                int l = ints[1];
                int o = ints[2];
                BigDecimal temp = new BigDecimal(s).multiply(new BigDecimal(Math.max(1, mid - l)));
                if (o == 1) {
                    longs.add(temp);
                } else {
                    count = count.add(temp);
                }
            }
            longs.sort((o1, o2) -> o2.compareTo(o1));
            for (int i = k; i < longs.size(); i++) {
                count = count.add(longs.get(i));
            }

            if (count.compareTo(new BigDecimal(g)) > 0) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        System.out.println(hi);
    }
}