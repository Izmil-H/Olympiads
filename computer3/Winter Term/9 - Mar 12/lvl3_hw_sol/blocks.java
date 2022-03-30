import java.util.*;
import java.io.*;
import java.time.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static String blocks[], word;
	public static void main(String[] args) throws IOException {
		int n = readInt();  blocks = new String[4];
		for(int i=0; i<4; i++) blocks[i] = readLine(); 
		for(int i=0; i<n; i++) {
			int a[] = new int[4]; boolean used[] = new boolean[4];
			for(int j=0; j<4; j++) a[j] = j;
			List<Integer> perm = new ArrayList();
			word = readLine();
			if(fun(a, used, perm)) System.out.println("YES");
			else System.out.println("NO");
		}
	}
	static boolean fun(int a[], boolean used[], List<Integer> perm) {
		if(perm.size() == a.length) {
			for(int k=0; k<word.length(); k++) {
				if(blocks[perm.get(k)].indexOf(word.charAt(k)) == -1)
					return false;
			}
			return true;
		}
		for(int i=0; i<a.length; i++) {
			if(!used[i]) {
				perm.add(a[i]); used[i] = true;
				if(fun(a, used, perm)) return true;
				perm.remove(perm.size()-1); used[i] = false;
			}
		}
		return false;
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