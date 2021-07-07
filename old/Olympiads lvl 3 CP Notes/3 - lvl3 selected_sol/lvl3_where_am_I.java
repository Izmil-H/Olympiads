import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(); String s = readLine();
		for(int len = 1; len <= n; len ++) {
			boolean flag = true;
			for(int i=0; i+len <=n; i++) {
				String sub = s.substring(i, i+len);
				int p1 = s.indexOf(sub);
				int p2 = s.indexOf(sub, p1+1);
				if(p2 != -1) { flag = false;  break; }
			}
			if(flag) { System.out.println(len); return; }
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