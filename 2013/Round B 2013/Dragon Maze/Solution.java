import java.io.*;
import java.util.*;

public class Solution {
    private static int N, M, enx, eny, exx, exy, maze[][];

    private static int[] Queue_Item(int x, int y) {
        int it[] = new int[2];
        it[0] = x;
        it[1] = y;
        return it;
    }

    private static boolean isValid(int x, int y) {
        return ((x >= 0) && (y >= 0) && (x < N) && (y < M));
    }

    private static int BFS() {
        Queue<int[]> Qu = new LinkedList<int[]>();
        Qu.add(Queue_Item(enx, eny));
        int[][] R = Arrays.stream(maze).map(int[]::clone).toArray(int[][]::new);
        boolean V[][] = new boolean[N][];
        for(int i = 0; i < N; i++) {
            V[i] = new boolean[M];
            for(int j = 0; j < M; j++)
                if(maze[i][j] == -1) V[i][j] = true;
                else V[i][j] = false;
        }
        V[enx][eny] = true;
        while(!Qu.isEmpty()) {
            Queue<int[]> temp = new LinkedList<int[]>();
            while(!Qu.isEmpty()) {
                int q[] = Qu.peek();
                Qu.poll();
                int x = q[0];
                int y = q[1];
                int val = R[x][y];
                if((x == exx) && (y == exy)) return val;

                if(isValid(x - 1, y)) {
                    if(maze[x - 1][y] != -1) R[x - 1][y] = Math.max(R[x - 1][y], val + maze[x - 1][y]);
                    if(V[x - 1][y] == false) {
                        V[x - 1][y] = true;
                        temp.add(Queue_Item(x - 1, y));
                    }
                }
                if(isValid(x, y - 1)) {
                    if(maze[x][y - 1] != -1) R[x][y - 1] = Math.max(R[x][y - 1], val + maze[x][y - 1]);
                    if(V[x][y - 1] == false) {
                        V[x][y - 1] = true;
                        temp.add(Queue_Item(x, y - 1));
                    }
                }
                if(isValid(x + 1, y)) {
                    if(maze[x + 1][y] != -1) R[x + 1][y] = Math.max(R[x + 1][y], val + maze[x + 1][y]);
                    if(V[x + 1][y] == false) {
                        V[x + 1][y] = true;
                        temp.add(Queue_Item(x + 1, y));
                    }
                }
                if(isValid(x, y + 1)) {
                    if(maze[x][y + 1] != -1) R[x][y + 1] = Math.max(R[x][y + 1], val + maze[x][y + 1]);
                    if(V[x][y + 1] == false) {
                        V[x][y + 1] = true;
                        temp.add(Queue_Item(x, y + 1));
                    }
                }
            }
            Qu = temp;

        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            N = sc.nextInt();
            M = sc.nextInt();
            enx = sc.nextInt();
            eny = sc.nextInt();
            exx = sc.nextInt();
            exy = sc.nextInt();

            maze = new int[N][];
            for(int i = 0; i < N; i++) {
                int row[] = new int[M];
                for(int j = 0; j < M; j++) row[j] = sc.nextInt();
                maze[i] = row;
            }
                
            int y = BFS();
            if(y == -1) System.out.println("Case #" + x + ": Mission Impossible.");
            else System.out.println("Case #" + x + ": " + y);
        }
        
        sc.close();
	}
}
