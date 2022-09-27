import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        System.out.println("Case #1:");
        try {
            String S = sc.nextLine();
            int c = 0;
            while(S != null) {
                int N = S.length();
                for(int i = 0; i < N; i++) {
                    if(S.charAt(i) == '*') {
                        if((i < (N - 1)) && (S.charAt(i + 1) == '/')) {
                            if(c > 0) {
                                i++;
                                c--;
                            } else System.out.print(S.charAt(i));
                        }
                        else if(c == 0) System.out.print(S.charAt(i));
                    } else if(S.charAt(i) == '/') {
                        if((i < (N - 1)) && (S.charAt(i + 1) == '*')) {
                            i++;
                            c++;
                        } else if(c == 0) System.out.print(S.charAt(i));
                    } else if(c == 0) System.out.print(S.charAt(i));
                }
                if(c == 0) System.out.println();
                S = sc.nextLine();
            }
        } catch(Exception e) {}
        sc.close();
    }
}
