import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T, N;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            N = sc.nextInt();
            String board[] = new String[N];
            for(int i = 0; i < N; i++) board[i] = sc.next();
            String y = "Impossible";
            System.out.println("Case #" + x + ": " + y);
        }
        
        sc.close();
	}
}
