import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T, N;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            N = sc.nextInt();
            String DIR = sc.next();

            int board[][] = new int[N][];
            int y[][] = new int[N][];
            for(int i = 0; i < N; i++) {
                board[i] = new int[N];
                y[i] = new int[N];
                for(int j = 0; j < N; j++) board[i][j] = sc.nextInt();
            }
            if(DIR.equals("left")) {
                for(int i = 0; i < N; i++) {
                    int s = 0, k = 0;
                    for(int j = 0; j < N; j++) {
                        if(board[i][j] == 0) continue;
                        if(s == 0) {
                            y[i][k++] = board[i][j];
                            s = 1;
                        } else {
                            if(y[i][k - 1] == board[i][j]) {
                                y[i][k - 1] += board[i][j];
                                s = 0;
                            } else {
                                y[i][k++] = board[i][j];
                            }
                        }
                    }
                }
            } else if(DIR.equals("right")) {
                for(int i = 0; i < N; i++) {
                    int s = 0, k = N - 1;
                    for(int j = N - 1; j >= 0; j--) {
                        if(board[i][j] == 0) continue;
                        if(s == 0) {
                            y[i][k--] = board[i][j];
                            s = 1;
                        } else {
                            if(y[i][k + 1] == board[i][j]) {
                                y[i][k + 1] += board[i][j];
                                s = 0;
                            } else {
                                y[i][k--] = board[i][j];
                            }
                        }
                    }
                }
            } else if(DIR.equals("up")) {
                for(int i = 0; i < N; i++) {
                    int s = 0, k = 0;
                    for(int j = 0; j < N; j++) {
                        if(board[j][i] == 0) continue;
                        if(s == 0) {
                            y[k++][i] = board[j][i];
                            s = 1;
                        } else {
                            if(y[k - 1][i] == board[j][i]) {
                                y[k - 1][i] += board[j][i];
                                s = 0;
                            } else {
                                y[k++][i] = board[j][i];
                            }
                        }
                    }
                }
            } else if(DIR.equals("down")) {
                for(int i = 0; i < N; i++) {
                    int s = 0, k = N - 1;
                    for(int j = N - 1; j >= 0; j--) {
                        if(board[j][i] == 0) continue;
                        if(s == 0) {
                            y[k--][i] = board[j][i];
                            s = 1;
                        } else {
                            if(y[k + 1][i] == board[j][i]) {
                                y[k + 1][i] += board[j][i];
                                s = 0;
                            } else {
                                y[k--][i] = board[j][i];
                            }
                        }
                    }
                }
            }

            System.out.println("Case #" + x + ":");
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(j == N - 1)
                        System.out.println(y[i][j]);
                    else
                        System.out.print(y[i][j] + " ");
                }
            }
        }

        sc.close();
	}
}
