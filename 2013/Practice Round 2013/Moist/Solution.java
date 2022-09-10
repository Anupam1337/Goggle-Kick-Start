import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T, N, y;
        String S, mx = "";
        T = Integer.parseInt(sc.nextLine());
        
        for(int x = 1; x <= T; x++) {
            N = Integer.parseInt(sc.nextLine());
            
            y = 0;
            
            for(int i = 0; i < N; i++) {
                S = sc.nextLine();
                
                if((i == 0) || (S.compareTo(mx) >= 0)) mx = S;
                else y++;
            }
            
            System.out.println("Case #" + x + ": " + y);
        }
        
        sc.close();
	}
}
