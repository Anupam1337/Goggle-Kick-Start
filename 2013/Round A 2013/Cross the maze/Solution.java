import java.io.*;
import java.util.*;

public class Solution {
    private static int mp[][];
    private static String Sq[];

    private static char getLeft(char d) {
        if(d == 'N') return 'W';
        if(d == 'E') return 'N';
        if(d == 'S') return 'E';
        return 'S';
    }
    
    private static char getRight(char d) {
        if(d == 'N') return 'E';
        if(d == 'E') return 'S';
        if(d == 'S') return 'W';
        return 'N';
    }
    
    private static char getBack(char d) {
        if(d == 'N') return 'S';
        if(d == 'E') return 'W';
        if(d == 'S') return 'N';
        return 'E';
    }
    
    private static int getIncoming(char d) {
        if(d == 'N') return 0;
        if(d == 'E') return 1;
        if(d == 'S') return 2;
        return 3;
    }
    
    private static boolean checkBoundary(int x, int y, int N, char c) {
        if((x + mp[getIncoming(c)][0]) < 0) return true;
        if((y + mp[getIncoming(c)][1]) < 0) return true;
        if((x + mp[getIncoming(c)][0]) == N) return true;
        if((y + mp[getIncoming(c)][1]) == N) return true;
    
        return false;
    }

    private static boolean isStep(int sx, int sy, int N, char c) {
        if(checkBoundary(sx, sy, N, c)) return false;
        return (Sq[sx + mp[getIncoming(c)][0]].charAt(sy + mp[getIncoming(c)][1]) == '.');
    }

    public static void main(String[] args) {
        mp = new int[4][];
        mp[getIncoming('E')] = new int[]{0, 1};
        mp[getIncoming('W')] = new int[]{0, -1};
        mp[getIncoming('N')] = new int[]{-1, 0};
        mp[getIncoming('S')] = new int[]{1, 0};

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T = sc.nextInt();

        for(int x = 1; x <= T; x++) {
            int N = sc.nextInt();

            Sq = new String[N];
            for(int i = 0; i < N; i++) {
                Sq[i] = sc.next();
            }

            int V[][][] = new int[N][][];
            for(int i = 0; i < N; i++) {
                V[i] = new int[N][];
                for(int j = 0; j < N; j++) {
                    V[i][j] = new int[4];
                    V[i][j][0] = 0;
                    V[i][j][1] = 0;
                    V[i][j][2] = 0;
                    V[i][j][3] = 0;
                }
            }

            int sx = sc.nextInt(), sy = sc.nextInt(), ex = sc.nextInt(), ey = sc.nextInt();
            char c = 'E';

            if((sx == N) && (sy == 1)) c = 'N';
            else if((sx == 1) && (sy == 1)) c = 'E';
            else if((sx == N) && (sy == N)) c = 'W';
            else if((sx == 1) && (sy == N)) c = 'S';

            String path = "";
            int ans = 0;
            sx--;
            sy--;
            ex--;
            ey--;

            while(ans != -1) {
                char l = getLeft(c);
                if(isStep(sx, sy, N, l)) {
                    if(V[sx + mp[getIncoming(l)][0]][sy + mp[getIncoming(l)][1]][getIncoming(l)] == 0) {
                        sx += mp[getIncoming(l)][0];
                        sy += mp[getIncoming(l)][1];
                        V[sx][sy][getIncoming(l)] = 1;
                        ans++;
                        c = l;
                        path += c;
                    } else {
                        ans = -1;
                        path = "Edison ran out of energy.";
                    }
                } else {
                    l = c;
                    if(isStep(sx, sy, N, l)) {
                        if(V[sx + mp[getIncoming(l)][0]][sy + mp[getIncoming(l)][1]][getIncoming(l)] == 0) {
                            sx += mp[getIncoming(l)][0];
                            sy += mp[getIncoming(l)][1];
                            V[sx][sy][getIncoming(l)] = 1;
                            ans++;
                            c = l;
                            path += c;
                        } else {
                            ans = -1;
                            path = "Edison ran out of energy.";
                        }
                    } else {
                        l = getRight(c);
                        if(isStep(sx, sy, N, l)) {
                            if(V[sx + mp[getIncoming(l)][0]][sy + mp[getIncoming(l)][1]][getIncoming(l)] == 0) {
                                sx += mp[getIncoming(l)][0];
                                sy += mp[getIncoming(l)][1];
                                V[sx][sy][getIncoming(l)] = 1;
                                ans++;
                                c = l;
                                path += c;
                            } else {
                                ans = -1;
                                path = "Edison ran out of energy.";
                            }
                        } else {
                            l = getBack(c);
                            if(isStep(sx, sy, N, l)) {
                                if(V[sx + mp[getIncoming(l)][0]][sy + mp[getIncoming(l)][1]][getIncoming(l)] == 0) {
                                    sx += mp[getIncoming(l)][0];
                                    sy += mp[getIncoming(l)][1];
                                    V[sx][sy][getIncoming(l)] = 1;
                                    ans++;
                                    c = l;
                                    path += c;
                                } else {
                                    ans = -1;
                                    path = "Edison ran out of energy.";
                                }
                            } else {
                                ans = -1;
                                path = "Edison ran out of energy.";
                            }
                        }
                    }
                }
                if((sx == ex) && (sy == ey)) break;
            }

            if(ans == -1)
                System.out.println("Case #" + x + ": " + path);
            else
                System.out.println("Case #" + x + ": " + ans + "\n" + path);
        }
	}
}
