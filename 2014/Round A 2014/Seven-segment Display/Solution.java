import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T, N;
        T = sc.nextInt();
        
        for(int x = 1; x <= T; x++) {
            N = sc.nextInt();
            Vector<String> board = new Vector<>(N);
            String led = "2222222";
            char[] ledChars = led.toCharArray();
            for(int i = 0; i < N; i++) {
                board.add(sc.next());
                for(int k = 0; k < 7; k++) {
                    if(board.get(i).charAt(k) == '1') {
                        ledChars[k] = '1';
                    }
                }
            }
            led = String.valueOf(ledChars);
            String digits[] = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
            String y = "";
            Map<Integer, String> mp = new HashMap<Integer,String>();
            for(int i = 0; i < 10; i++) mp.put(i, led);

            for(int i = 0; i < N; i++) {
                Map<Integer, String> mpr = new HashMap<Integer,String>();
                for(Map.Entry<Integer,String> entry : mp.entrySet()) {
                    int flag = 1;
                    int disp = entry.getKey();
                    String leds = entry.getValue();

                    for(int k = 0; k < 7; k++) {
                        if(board.get(i).charAt(k) == '1') {
                            if((digits[disp].charAt(k) == '0') || (leds.charAt(k) == '0')) {
                                flag = 0;
                                break;
                            }
                            leds = leds.substring(0, k) + '1' + leds.substring(k + 1);
                        } else if(digits[disp].charAt(k) == '1') {
                            if(leds.charAt(k) == '1') {
                                flag = 0;
                                break;
                            }
                            leds = leds.substring(0, k) + '0' + leds.substring(k + 1);
                        }
                    }
                    if(flag == 1) mpr.put((disp + 9) % 10, leds);
                }
                mp = mpr;
            }
            for(Map.Entry<Integer,String> entry : mp.entrySet()) {
                String ans = digits[entry.getKey()];
                led = entry.getValue();

                for(int k = 0; k < 7; k++) {
                    if((ans.charAt(k) == '1') && (led.charAt(k) == '2')) {
                        ans = "ERROR!";
                        break;
                    }
                    if(led.charAt(k) == '0') ans = ans.substring(0, k) + '0' + ans.substring(k + 1);
                }

                if(y.equals("")) y = ans;
                if(!y.equals(ans)) y = "ERROR!";
            }
            if(y.equals("")) y = "ERROR!";
            System.out.println("Case #" + x + ": " + y);
        }

        sc.close();
	}
}
