import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            int N = sc.nextInt();
            int Sudoku[][] = new int[N * N][];
            String y = "Yes";

            for(int i = 0; i < N * N; i++) {
                Sudoku[i] = new int[N * N];
                for(int j = 0; j < N * N; j++) {
                    Sudoku[i][j] = sc.nextInt();
                }
            }
            int f = 1;
            for(int i = 0; (f == 1) && (i < N * N); i++) {
                Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
                for(int j = 0; (f == 1) && (j < N * N); j++) {
                    if((Sudoku[i][j] < 1) || (Sudoku[i][j] > (N * N)) || (mp.get(Sudoku[i][j]) != null)) {
                        y = "No";
                        f = 0;
                    }
                    mp.put(Sudoku[i][j], 1);
                }
            }
            for(int k = 0; (f == 1) && (k < N); k++) {
                Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
                for(int i = 0; (f == 1) && (i < N); i++) {
                    for(int j = 0; (f == 1) && (j < N); j++) {
                        if((Sudoku[i][j] < 1) || (Sudoku[i][j] > (N * N)) || (mp.get(Sudoku[i][j]) != null)) {
                            y = "No";
                            f = 0;
                        }
                        mp.put(Sudoku[i][j], 1);
                    }
                }
            }
            System.out.println("Case #" + x + ": " + y);
        }
        
        sc.close();
	}
}
