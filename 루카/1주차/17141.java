import java.util.*;

public class 17141 {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[][] mapOrigin = new int[n][n];
        int[][] map = new int[n][n];

        List<int[]> virus = new ArrayList<>();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = scanner.nextInt();
                if (x == 2) {
                    int[] index = new int[2];
                    index[0] = i;
                    index[1] = j;
                    virus.add(index);
                    map[i][j] = 0;
                } else {
                    map[i][j] = x;
                }
                if (x != 1) {
                    count++;
                }
            }
        }

        int answer = Integer.MAX_VALUE;

        int size = virus.size();
        List<List<Integer>> locations = new ArrayList<>();
        int[] temp = new int[m];

        go(-1, -1, m, size, temp, locations);

        Queue<int[]> bfs = new LinkedList<>();

        for (List<Integer> virusLocation : locations) {
            int[][] visited = new int[n][n];
            int countVirus = 0;
            int maxDays = 0;
            for (Integer index : virusLocation) {
                int[] xy = virus.get(index);
                bfs.add(xy);
                visited[xy[0]][xy[1]] = 1;
                countVirus++;
            }
            while (!bfs.isEmpty()) {
                int[] poll = bfs.poll();

                for (int i = 0; i < 4; i++) {
                    int x = poll[0];
                    int nextX = x + dx[i];
                    int y = poll[1];
                    int nextY = y + dy[i];
                    if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
                    if (visited[nextX][nextY] != 0) continue;
                    if (map[nextX][nextY] == 1) continue;
                    int nextDays = visited[x][y] + 1;
                    visited[nextX][nextY] = nextDays;
                    countVirus++;
                    int[] newTemp = {nextX, nextY};
                    bfs.add(newTemp);
                    maxDays = nextDays - 1;
                }
            }
            if (countVirus == count) {
                answer = Math.min(maxDays, answer);
            }
        }
        if (answer == Integer.MAX_VALUE) {
            System.out.println(-1);
        }else {
            System.out.println(answer);
        }
    }

    static void go(int x, int level, int m, int size, int[] temp, List<List<Integer>> locations) {
        if (m == level + 1) {
            List<Integer> newT = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                newT.add(temp[i]);
            }
            locations.add(newT);
            return;
        }
        int nextLevel = level + 1;
        for (int i = x + 1; i < size; i++) {
            temp[nextLevel] = i;
            go(i, nextLevel, m, size, temp, locations);
        }
    }
}
