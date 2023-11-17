package codingTest.set6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class irae_25631 {
    
    static int N;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        ArrayList<Integer> dolls = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            dolls.add(Integer.parseInt(st.nextToken()));
        }
        
        Set<Integer> notDuplicatedSizes = new HashSet<>(dolls);
        List<Integer> frequencies = new ArrayList<>();
        for (int size : notDuplicatedSizes) {
            frequencies.add(Collections.frequency(dolls, size));
        }
        Integer max = frequencies.stream()
                                 .max(Integer::compareTo)
                                 .get();
        System.out.println("max = " + max);
    }
}
