import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T, N;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            N = sc.nextInt();

            int board[][] = new int[N][];
            int y[][] = new int[N][];
            for(int i = 0; i < N; i++) {
                board[i] = new int[N];
                y[i] = new int[N];
                for(int j = 0; j < N; j++) board[i][j] = sc.nextInt();
            }
            System.out.println("Case #" + x + ":");
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(j == N - 1)
                        System.out.println(y[i][j]);
                    else
                        System.out.print(y[i][j] + " ");
                }
            }
        }

        sc.close();
	}
}
