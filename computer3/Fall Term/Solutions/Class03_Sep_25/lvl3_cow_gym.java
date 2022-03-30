import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int k = readInt(), n=readInt(), a[][] = new int[k+1][n+1];
		for(int i=1; i<=k; i++)
			for(int j=1; j<=n; j++)
				a[i][readInt()] = j;
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				int val = sign(a[1][i], a[1][j]); boolean flag = true;
				for(int p=1; p<=k; p++)
					if(sign(a[p][i], a[p][j]) != val) flag = false;
				if(flag) cnt++;
			}
		}
		System.out.println(cnt);
	}
	static int sign(int a, int b) {
		return a > b? 1 : -1;
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