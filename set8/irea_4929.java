package codingTest.set8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class irae_4929 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String str = br.readLine();
            if (str.equals("0")) {
                break;
            }
            StringTokenizer st = new StringTokenizer(str);
            int firstNumbersCount = Integer.parseInt(st.nextToken());
            List<Integer> firstNumbers = new ArrayList<>();
            for (int i = 0; i < firstNumbersCount; i++) {
                firstNumbers.add(Integer.parseInt(st.nextToken()));
            }
            
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int secondNumbersCount = Integer.parseInt(st2.nextToken());
            List<Integer> secondNumbers = new ArrayList<>();
            for (int i = 0; i < secondNumbersCount; i++) {
                secondNumbers.add(Integer.parseInt(st2.nextToken()));
            }
            
            List<Integer> sameNumbers = new ArrayList<>();
            for (int num : firstNumbers) {
                if (secondNumbers.contains(num)) {
                    sameNumbers.add(num);
                }
            }
            
            List<Integer> firstScores = getScores(firstNumbers, sameNumbers);
            List<Integer> secondScores = getScores(secondNumbers, sameNumbers);
            
            int maxSum = 0;
            for (int i = 0; i < sameNumbers.size() + 1; i++) {
                maxSum += Integer.max(firstScores.get(i), secondScores.get(i));
            }
            
            System.out.println(maxSum);
        }
    }
    
    private static List<Integer> getScores(final List<Integer> numbers, final List<Integer> sameNumbers) {
        List<Integer> scores = new ArrayList<>();
        int score = 0;
        for (int num : numbers) {
            if (sameNumbers.contains(num)) {
                scores.add((score + num));
                score = 0;
                continue;
            }
            score += num;
        }
        scores.add(score);
        return scores;
    }
}
