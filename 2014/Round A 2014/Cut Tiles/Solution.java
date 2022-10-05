import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T = sc.nextInt();
        for(int x = 1; x <= T; x++) {
            int N = sc.nextInt(), M = sc.nextInt();
            int y = 0;

            Vector<Long> required = new Vector<>();
            for(int i = 0; i < N; i++) {
                int n = sc.nextInt();
                required.add(1L << n);
            }
            Collections.sort(required);
            Vector<long[]> st = new Vector<>();
            while(required.size() > 0) {
                if(st.size() == 0) {
                    st.add(new long[]{M, M});
                    y++;;
                }
                N = required.size();
                for(int i = N - 1; i >= 0; i--) {
                    for(int j = 0; j < st.size(); j++) {
                        if(st.get(j)[0] < required.get(i)) continue;
                        long p[] = st.get(j);
                        st.remove(j);
                        j--;
                        if(p[0] == required.get(i)) {
                            if(p[1] > required.get(i)) {
                                st.add(new long[]{Math.min(p[1] - p[0], p[0]), Math.max(p[1] - p[0], p[0])});
                            }
                        } else {
                            long m1 = p[0] - required.get(i);
                            long m2 = p[1] - required.get(i);
                            st.add(new long[]{Math.min(m1, m2), Math.max(m1, m2)});
                            st.add(new long[]{Math.min(m1, required.get(i)), Math.max(m1, required.get(i))});
                            st.add(new long[]{Math.min(m2, required.get(i)), Math.max(m2, required.get(i))});
                        }
                        required.remove(i);
                        Collections.sort(st, new Comparator<long[]>() {
                            public int compare(long a[], long b[]) {
                                if(a[0] == b[0]) {
                                    if(a[1] < b[1]) return -1;
                                    if(a[1] > b[1]) return 1;
                                    return 0;
                                }
                                if(a[0] < b[0]) return -1;
                                if(a[0] > b[0]) return 1;
                                return 0;
                        }
                        });
                        break;
                    }
                }
                st.clear();
            }

            System.out.println("Case #" + x + ": " + y);
        }
        sc.close();
    }
}