import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            int N = sc.nextInt();
            Vector<Integer> S = new Vector<>(N);
            Vector<Integer> O = new Vector<>(N);
            Vector<Integer> E = new Vector<>(N);

            for(int i = 0; i < N; i++) {
                S.add(sc.nextInt());

                if((S.get(i) % 2) == 0) E.add(S.get(i));
                else O.add(S.get(i));
            }

            Collections.sort(E, new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return o2 - o1;
                }
            });

            Collections.sort(O);

            for(int i = 0, j = 0, k = 0; i < N; i++) {
                if((S.get(i) % 2) == 0) S.set(i, E.get(j++));
                else S.set(i, O.get(k++));
            }

            System.out.print("Case #" + x + ": ");

            for(int i = 0; i < N; i++) {
                System.out.print(S.get(i));
                if(i < (N - 1)) System.out.print(" ");
            }
            System.out.println();
        }
        
        sc.close();
	}
}
