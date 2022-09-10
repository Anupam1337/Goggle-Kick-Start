import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            double V, D, g = 9.8, PI = 3.14159265359, y = 0;

            V = sc.nextInt();
            D = sc.nextInt();
            double val = (g * D) / (V * V);

            if(val > 1) val = 1;
            else if(val < -1) val = -1;

            y = 90 * Math.asin(val) / PI;
            
            System.out.println("Case #" + x + ": " + y);
        }
        
        sc.close();
	}
}
