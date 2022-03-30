import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), a[] = new int[n], ans = 0;
		for(int i=0; i<n; i++) {
			a[i] = readInt();
		}
		for(int i=0; i<n; i++) {
			int sum = 0;
			for(int j=i; j<n; j++) {
				sum += a[j]; boolean good = false;
				for(int k=i; k<=j; k++) {
					if(a[k]*(j-i+1) == sum) good = true;
				}
				if(good) ans++;
			}
		}
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