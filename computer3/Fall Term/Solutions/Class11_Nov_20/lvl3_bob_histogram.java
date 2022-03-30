import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt(), sum =0, a[] = new int[n];
		for(int i=0; i<n; i++) {
			a[i] = readInt(); sum += a[i];
		}
		int cost1 = 0, cost2 = 0, avg = sum/n;
		for(int i=0; i<n; i++) cost1 += (a[i] - avg)*(a[i] - avg);
		avg++;
		for(int i=0; i<n; i++) cost2 += (a[i] - avg)*(a[i] - avg);
		System.out.println(Math.min(cost1, cost2));
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