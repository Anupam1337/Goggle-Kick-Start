import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T;
        T = sc.nextInt();
        String number[] = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
        String count[] = {"", "", "double ", "triple ", "quadruple ", "quintuple ", "sextuple ", "septuple ", "octuple ", "nonuple ", "decuple "};
    
        for(int x = 1; x <= T; x++) {
            String y = "";
            String N = sc.next();
            String F = sc.next();

            int d = 0, i = 0, j = 0, c = 0;
            while(i < N.length()) {
                if(d == 0) {
                    while(j < F.length()) {
                        if(F.charAt(j) == '-') {
                            j++;
                            break;
                        } else {
                            d = ((d * 10) + (int)(F.charAt(j) - '0'));
                        }

                        j++;
                    }
                }
                int k = (int)(N.charAt(i) - '0');
                c++;

                if((d == 1) || (((i + 1) < N.length())) && (N.charAt(i) != N.charAt(i + 1))) {
                    if((c == 1) || (c > 10)) {
                        while(c-- > 0) y += number[k];
                    } else y += count[c] + number[k];
                    c = 0;
                }
                d--;
                i++;
            }
            y = y.substring(0, y.length() - 1);

            System.out.println("Case #" + x + ": " + y);
        }
        
        sc.close();
	}
}
