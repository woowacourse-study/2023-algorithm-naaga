package codingTest.set7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class irae_3186 {
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        Map<String, Integer> keywords = new HashMap();
        for (int i = 0; i < N; i++) {
            keywords.put(br.readLine(), 1);
        }
        for (int i = 0; i < M; i++) {
            String[] split = br.readLine().split(",");
            for (String str : split) {
                if (keywords.getOrDefault(str, 0) != 0) {
                    keywords.remove(str);
                }
            }
            System.out.println(keywords.keySet().size());
        }
    }
}
