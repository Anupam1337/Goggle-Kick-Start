import java.io.*;
import java.util.*;

public class Solution {
    private static Vector<Boolean> V;
    private static Vector<Integer> C;

    private static int M, K;
    private static LinkedList<Integer> A[];

    @SuppressWarnings("unchecked") private static void graph() {
        A = new LinkedList[K];
        for (int i = 0; i < K; ++i)
            A[i] = new LinkedList<>();
    }
    
    private static String DFSUtil(int i) {
        V.set(i, true);
        // System.out.print(i + " -> ");
 
        Iterator<Integer> it = A[i].listIterator();
        while(it.hasNext()) {
            int n = it.next();
            if (!V.get(n)) {
                C.set(n, 1 - C.get(i));
                String s = DFSUtil(n);
                if(s.equals("No")) return s;
            } else if(C.get(i).equals(C.get(n))) return "No";
        }

        return "Yes";
    }
 
    private static String DFS() {
        V = new Vector<>();
        C = new Vector<>();

        for(int i = 0; i < K; i++) {
            V.add(false);
            C.add(2);
        }

        for(int i = 1; i < K; i++) {
            if(!V.get(i)) {
                C.set(i, 0);
                String S = DFSUtil(i);
                // System.out.println();
                if(S.equals("No")) return S;
            }
        }
        return "Yes";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T;
        T = sc.nextInt();

        for(int x = 1; x <= T; x++) {
            String y = "Yes";

            M = sc.nextInt();
            Map<String, Integer> mp = new  HashMap<>();
            Vector<String> names1 = new Vector<>(M);
            Vector<String> names2 = new Vector<>(M);

            K = 1;
            for(int i = 0; i < M; i++) {
                names1.add(sc.next());
                if(!mp.containsKey(names1.get(i))) mp.put(names1.get(i), K++);

                names2.add(sc.next());
                if(!mp.containsKey(names2.get(i))) mp.put(names2.get(i), K++);
            }

            graph();
            for(int i = 0; i < M; i++) {
                A[mp.get(names1.get(i))].add(mp.get(names2.get(i)));
                A[mp.get(names2.get(i))].add(mp.get(names1.get(i)));
            }

            y = DFS();
            
            System.out.println("Case #" + x + ": " + y);
        }
        
        sc.close();
	}
}
