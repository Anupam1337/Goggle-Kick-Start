import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T, N, ans;
        String S, mx = "";
        T = Integer.parseInt(sc.nextLine());
        
        for(int t = 1; t <= T; t++) {
            N = Integer.parseInt(sc.nextLine());
            
            ans = 0;
            
            for(int i = 0; i < N; i++) {
                S = sc.nextLine();
                
                if((i == 0) || (S.compareTo(mx) >= 0)) mx = S;
                else ans++;
            }
            
            System.out.println("Case #" + t + ": " + ans);
        }
        
        sc.close();
	}
}
