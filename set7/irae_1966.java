package codingTest.set7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class irae_1966 {
    
    static int Case;
    static Queue<Integer> indexQueue;
    
    static Queue<Integer> importanceQueue;
    
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Case = Integer.parseInt(br.readLine());
        for (int i = 0; i < Case; i++) {
            String[] papers_index = br.readLine().split(" ");
            int papersCount = Integer.parseInt(papers_index[0]);
            int index = Integer.parseInt(papers_index[1]);
            
            int count = 1;
            Map<Integer, Integer> old_newCount = new HashMap<>();
            indexQueue = new LinkedList<>();
            importanceQueue = new LinkedList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < papersCount; j++) {
                indexQueue.add(j);
                importanceQueue.add(Integer.parseInt(st.nextToken()));
            }
            
            while (!indexQueue.isEmpty()) {
                Integer idx = indexQueue.poll();
                Integer importance = importanceQueue.poll();
                
                if (importanceQueue.stream()
                                   .anyMatch(num -> num > importance)) {
                    indexQueue.add(idx);
                    importanceQueue.add(importance);
                    continue;
                }
                old_newCount.put(idx, count);
                count++;
            }
            
            System.out.println(old_newCount.get(index));
        }
    }
}
