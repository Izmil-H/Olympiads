import java.io.*;
import java.util.*;

public class Main {
     static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int maxV = (int) 1e5;
        long [] psa = new long[maxV+1];boolean[] f = new boolean[maxV+1];
        
        for(int i = 2; i <maxV+1;i++){
            psa[i] = psa[i-1];
            if(!f[i]){
                psa[i] +=i;
                for(int j = 2*i; j < maxV+1; j +=i) f[j] = true;
            }
        }
        
        for(int Q = readInt(); Q > 0;Q--){
            int a= readInt(), b = readInt();
            System.out.println(psa[b]-psa[a-1]);
        }
            



    }


    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();

    }

}