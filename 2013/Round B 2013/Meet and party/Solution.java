import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T, B, x1, y1, x2, y2;
        T = sc.nextInt();
        
        for(int t = 1; t <= T; t++) {
            B = sc.nextInt();
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();
            int x = x1 + x2, y = y1 + y2 ,d = B;
            System.out.println("Case #" + t + ": " + x + " " + y + " " + d);
        }
        
        sc.close();
	}
}
