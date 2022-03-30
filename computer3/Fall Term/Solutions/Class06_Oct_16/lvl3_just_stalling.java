import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), cow[] = new int[n], stall[] = new int[n];
		for(int i=0; i<n; i++) {
			cow[i] = readInt();
		}
		for(int i=0; i<n; i++) {
			stall[i] = readInt();
		}
		Arrays.sort(cow); Arrays.sort(stall);
		long ans = 1;
		for(int i=n-1; i>=0; i--) {
			int cnt = 0;
			for(int j=i; j>=0; j--) {
				if(stall[j] >= cow[i]) cnt++;
			}
			ans = ans*cnt;
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