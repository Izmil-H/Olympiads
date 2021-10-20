import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
	    int N = readInt(), K  =readInt(), a[][] = new int[N+1][N+1];
	    for(int i=1; i<=N; i++)
	        for(int j=1; j<=i; j++)
	            a[i][j] = readInt();
	    int cur = 0, nxt = 0; 
	    for(cur=1, nxt=2; nxt <= K; cur=nxt, nxt=(int)(1.5*cur)){
	        int d = nxt - cur;
	        for(int i=1; i<=N-nxt+1; i++){
	            for(int j=1; j<=i; j++){
	                a[i][j] = Math.max(a[i][j], Math.max(a[i+d][j], a[i+d][j+d]));
	            }
	        }
	    }
	    int d = K - cur; long ans = 0;
	    for(int i=1; i<=N-K+1; i++)
	        for(int j=1; j<=i; j++)
	            ans += Math.max(a[i][j], Math.max(a[i+d][j], a[i+d][j+d]));
	    System.out.println(ans);
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