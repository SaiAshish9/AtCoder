import java.util.*;

public class Main {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        sc.nextLine();

        char[][] grid = new char[H][W];
        for (int i = 0; i < H; i++) {
            grid[i] = sc.nextLine().toCharArray();
        }

        boolean[][] inQueue = new boolean[H][W];
        Queue<int[]> queue = new ArrayDeque<>();

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == '.' && countBlackNeighbors(grid, i, j, H, W) == 1) {
                    queue.add(new int[]{i, j});
                    inQueue[i][j] = true;
                }
            }
        }

        while (!queue.isEmpty()) {
            List<int[]> toBlack = new ArrayList<>();
            int size = queue.size();

            for (int s = 0; s < size; s++) {
                int[] cell = queue.poll();
                int x = cell[0], y = cell[1];
                inQueue[x][y] = false;
                if (grid[x][y] == '.' && countBlackNeighbors(grid, x, y, H, W) == 1) {
                    toBlack.add(cell);
                }
            }

            for (int[] cell : toBlack) {
                int x = cell[0], y = cell[1];
                grid[x][y] = '#';

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W &&
                        grid[nx][ny] == '.' && !inQueue[nx][ny]) {
                        queue.add(new int[]{nx, ny});
                        inQueue[nx][ny] = true;
                    }
                }
            }
        }

        int blackCount = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == '#') blackCount++;
            }
        }

        System.out.println(blackCount);
    }

    static int countBlackNeighbors(char[][] grid, int x, int y, int H, int W) {
        int count = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] == '#') {
                count++;
            }
        }
        return count;
    }
}
