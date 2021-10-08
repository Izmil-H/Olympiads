import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static class pair implements Comparable<pair>{
        int x, y;
        pair(int a, int b){
            x = a;
            y = b;
        }
        public int compareTo(pair p){
        	if(x != p.x) return Integer.compare(x, p.x);
            return Integer.compare(y, p.y);
        }
    }
        static int MM = (int)1e5+5, MV = (int)1e4+2, mod = (int)1e9+7;
        static int n; static pair p[]; 
        static long ans, sx[], sy[], cx[] ;
        static long cy[], lx[], ly[];
    static void fun(){
        Arrays.sort(p); 
        sx = new long[2*MV]; sy = new long[2*MV]; cx = new long[2*MV]; cy = new long[2*MV];
        lx = new long[2*MV]; ly = new long[2*MV]; 
        for(int i = 0; i < n; i++){
            int x = p[i].x+MV, y = p[i].y + MV;
            sx[x] = (sx[x]+cx[x]*(y-lx[x]))%mod;
            sy[y] = (sy[y]+cy[y]*(x-ly[y]))%mod;
            ans = (ans+sx[x]*sy[y])%mod;
            cx[x]++; cy[y]++; lx[x]=y; ly[y]=x;
        }
    }
    static void rot(){
        for(int i = 0; i < n; i++){
            int x = p[i].x, y = p[i].y;
            p[i].x = y; p[i].y=-x;
        }
    }
    public static void main(String[] args) throws IOException {
        n = readInt(); p = new pair[n];
        for(int i = 0; i < n; i++){
            p[i] = new pair(readInt(), readInt());
        }
        for(int k = 1; k <= 4; k++){
            fun();
            rot();
        }
        System.out.println(ans);
    }
    
    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        }
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}