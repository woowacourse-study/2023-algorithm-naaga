package codingTest.set8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class irae_9017 {
    
    static int Case;
    static List<Integer> result = new ArrayList<>();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Case = Integer.parseInt(br.readLine());
        for (int i = 0; i < Case; i++) {
            int N = Integer.parseInt(br.readLine());
            List<Integer> rankBoard = new ArrayList<>();
            //1. 팀마다 들어온 플레이어 수 구하기
            Map<Integer, Integer> numberOfPlayerByTeam = new HashMap<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int team = Integer.parseInt(st.nextToken());
                rankBoard.add(team);
                Integer before = numberOfPlayerByTeam.getOrDefault(team, 0);
                numberOfPlayerByTeam.put(team, before + 1);
            }
            result.add(findWinnerTeam(rankBoard, numberOfPlayerByTeam));
        }
        for (int winnerTeam : result) {
            System.out.println(winnerTeam);
        }
    }
    
    private static int findWinnerTeam(final List<Integer> rankBoard, Map<Integer, Integer> numberOfPlayerByTeam) {
        Map<Integer, Integer> team_score = new HashMap<>();
        Map<Integer, Integer> team_order = new HashMap<>();
        int[] fifthPlayerScore = new int[numberOfPlayerByTeam.size() + 1];
        int score = 1;
        //순서
        for (int team : rankBoard) {
            if (numberOfPlayerByTeam.get(team) >= 6) {
                team_order.put(team, team_order.getOrDefault(team, 0) + 1);
                
                if (team_order.get(team) <= 4) {
                    team_score.put(team, team_score.getOrDefault(team, 0) + score);
                }
                if (team_order.get(team) == 5) {
                    fifthPlayerScore[team] = score;
                }
                score++;
            }
        }
        List<Integer> winnerCandidates = new ArrayList<>(team_score.keySet());
        winnerCandidates.sort((first, second) -> {
            if (Objects.equals(team_score.get(first), team_score.get(second))) {
                return fifthPlayerScore[first] - fifthPlayerScore[second];
            } else {
                return team_score.get(first) - team_score.get(second);
            }
        });
        return winnerCandidates.get(0);
    }
    }
}
