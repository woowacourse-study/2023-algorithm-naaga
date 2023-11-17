package codingTest.set6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class irae_1051 {
    
    static int N;
    static int M;
    static int min;
    static int[][] map;
    
    static int[] X = new int[]{1, 0, 1};
    static int[] Y = new int[]{0, 1, 1};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        min = Math.min(N, M);
        Set<Integer> answers = new HashSet<>();
        map = new int[N][M];
        for (int i = 0; i < N; i++) {
            String[] split = br.readLine().split("");
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(split[j]);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; i + k < N && j + k < M; k++) {
                    int num = map[i][j];
                    if (map[i + k][j] == num && map[i][j + k] == num && map[i + k][j + k] == num) {
                        answers.add((k + 1) * (k + 1));
                    }
                    
                }
            }
        }
        System.out.println(answers.stream().max(Integer::compareTo).get());
    }
}
