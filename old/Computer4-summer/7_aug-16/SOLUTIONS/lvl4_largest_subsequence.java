import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), last[] = new int[n];
		String [] s = new String[n]; List<Character> ans = new ArrayList();
		for(int i=0; i<n; i++) s[i] = readLine();
		for(char i='z'; i>='a'; ) {
			boolean found = true;
			int [] tmp = new int[n];
			for(int j=0; j<n; j++) {
				tmp[j] = s[j].indexOf(i, last[j]);
				if(tmp[j] == -1) { found = false; break; }
			}
			if(found) {
				for(int j=0; j<n; j++) last[j] = tmp[j]+1;
				ans.add(i);
			}else i--;
		}
		if(! ans.isEmpty()) {
			for(char x: ans) System.out.print(x); 
			System.out.println();
		}else System.out.println(-1);
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