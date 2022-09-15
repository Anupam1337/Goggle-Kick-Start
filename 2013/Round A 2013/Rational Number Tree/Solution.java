import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T;
        T = sc.nextInt();

        for(int x = 1; x <= T; x++) {
            int id = sc.nextInt();

            long n = 1, p = 1, q = 1;

            if(id == 1) {
                n = Long.parseUnsignedLong(sc.next());
                String s = Long.toBinaryString(n);
                for(int i = 1; i < s.length(); i++) {
                    if(s.charAt(i) == '1') p += q;
                    else q += p;
                }
                System.out.println("Case #" + x + ": " + p + " " + q);
            } else {
                p = Long.parseUnsignedLong(sc.next());
                q = Long.parseUnsignedLong(sc.next());
                n = 0;
                BigInteger N = new BigInteger("0");
                BigInteger i = new BigInteger("1");
                while((p >= 1) && (q >= 1)) {
                    if(p < q) {
                        q -= p;
                    } else {
                        p -= q;
                        N = N.add(i);
                    }
                    i = i.multiply(BigInteger.valueOf(2));
                }
    
                System.out.println("Case #" + x + ": " + N.toString());
            }
        }
        
        sc.close();
	}
}
