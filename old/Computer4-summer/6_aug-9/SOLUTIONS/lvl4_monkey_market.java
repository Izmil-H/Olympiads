import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), a[] = new int[n]; 
		for(int i=0; i<n; i++) a[i] = readInt();
		Arrays.sort(a);
		List<Integer> price = new ArrayList();
		List<Character> ans = new ArrayList();
		for(int i=0, j=n-1; i<=j; i++, j--) {
			price.add(a[i]); price.add(a[j]);
			if(i != j) { ans.add('B'); ans.add('S'); }
			else ans.add('E');
		}
		for(int i=0; i<n; i++) {
			System.out.print(price.get(i) + (i==n-1? "\n" : " "));
		}
		for(char c : ans) System.out.print(c);
		System.out.println();
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