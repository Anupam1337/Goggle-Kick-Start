import java.io.*;
import java.util.*;

public class Solution {
    private static int getBlue(int i, int N, String S[]) {
        if(i == N) return 0;
        if(S[i].charAt(0) != 'B') return getBlue(i + 1, N, S);
        int j, k;
        Stack<int[]> st = new Stack<>();
        st.push(new int[]{i, 0});
        while(!st.isEmpty()) {
            int[] p = st.peek();
            st.pop();
            j = p[0];
            k = p[1];
            StringBuilder string = new StringBuilder(S[j]);
            string.setCharAt(k, '.');
            S[j] = string.toString();
            if(k == (N - 1)) return 1 + getBlue(i + 1, N, S);
    
            if((k > 0) && (S[j].charAt(k - 1) == 'B')) st.push(new int[]{j, k - 1});
            if((j < (N - 1)) && (k > 0) && (S[j + 1].charAt(k - 1) == 'B')) st.push(new int[]{j + 1, k - 1});
            if((j < (N - 1)) && (S[j + 1].charAt(k) == 'B')) st.push(new int[]{j + 1, k});
            if((k < (N - 1)) && (S[j].charAt(k + 1) == 'B')) st.push(new int[]{j, k + 1});
            if((j > 0) && (S[j - 1].charAt(k) == 'B')) st.push(new int[]{j - 1, k});
            if((j > 0) && (k < (N - 1)) && (S[j - 1].charAt(k + 1) == 'B')) st.push(new int[]{j - 1, k + 1});
        }
        return getBlue(i + 1, N, S);
    }
    
    private static int getRed(int j, int N, String S[]) {
        if(j == N) return 0;
        if(S[0].charAt(j) != 'R') return getRed(j + 1, N, S);
        int i = 0, k = j;
        Stack<int[]> st = new Stack<>();
        st.push(new int[]{i, k});
        while(!st.empty()) {
            int[] p = st.peek();
            st.pop();
            i = p[0];
            k = p[1];
            StringBuilder string = new StringBuilder(S[i]);
            string.setCharAt(k, '.');
            S[i] = string.toString();
            if(i == (N - 1)) return 1 + getRed(j + 1, N, S);
    
            if((i > 0) && (k < (N - 1)) && (S[i - 1].charAt(k + 1) == 'R')) st.push(new int[]{i - 1, k + 1});
            if((i > 0) && (S[i - 1].charAt(k) == 'R')) st.push(new int[]{i - 1, k});
            if((k < (N - 1)) && (S[i].charAt(k + 1) == 'R')) st.push(new int[]{i, k + 1});
            if((k > 0) && (S[i].charAt(k - 1) == 'R')) st.push(new int[]{i, k - 1});
            if((i < (N - 1)) && (S[i + 1].charAt(k) == 'R')) st.push(new int[]{i + 1, k});
            if((i < (N - 1)) && (k > 0) && (S[i + 1].charAt(k - 1) == 'R')) st.push(new int[]{i + 1, k - 1});
        }
        return getRed(i + 1, N, S);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T, N;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            N = sc.nextInt();
            int B = 0, R = 0, Bl = 0, Rl = 0;

            String board[] = new String[N];
            for(int i = 0; i < N; i++) {
                board[i] = sc.next();
                for(int j = 0; j < N; j++) {
                    if(board[i].charAt(j) == 'B') B++;
                    if(board[i].charAt(j) == 'R') R++;
                }
            }

            Bl = getBlue(0, N, board);
            Rl = getRed(0, N, board);
            String y = "Nobody wins";
            if(Math.abs(R - B) > 1) y = "Impossible";
            else if((Bl + Rl) > 1) y = "Impossible";
            else if((Bl == 1) && (B < R)) y = "Impossible";
            else if((Rl == 1) && (R < B)) y = "Impossible";
            else if(Bl == 1) y = "Blue wins";
            else if(Rl == 1) y = "Red wins";

            System.out.println("Case #" + x + ": " + y);
        }

        sc.close();
	}
}
