package codingTest.set7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class irae_17127 {
    
    static int N;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] trees = new int[N];
        for (int i = 0; i < N; i++) {
            trees[i] = Integer.parseInt(st.nextToken());
        }
        
        List<Integer> sums = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            int before = 0;
            for (int k = 0; k < i; k++) {
                before += trees[k];
            }
            int mid = 1;
            for (int j = i; j < i + N - 3; j++) {
                mid *= trees[j];
            }
            int after = 0;
            for (int l = i + N - 3; l < N; l++) {
                after += trees[l];
            }
            sums.add(before + mid + after);
        }
        
        System.out.println(sums.stream().max(Integer::compareTo).get());
    }
}
