import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int a[] = new int[3];
		for(int i=0; i<3; i++) a[i] = readInt();
		Arrays.sort(a);
		int max = Math.max(a[1]-a[0], a[2]-a[1]) - 1, min = 2;
		if(a[1] - a[0] == 1&& a[2]-a[1] == 1) min = 0;
		if(a[1] - a[0] == 2 || a[2] - a[1] == 2) min = 1;
		System.out.println(min + "\n" + max);
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