import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		String [] cow = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
		Arrays.sort(cow);
		int n = readInt(); String [] a = new String[n], b = new String[n];
		for(int i=0; i<n; i++) {
			a[i] = next();
			for(int j=0; j<5; j++) b[i] = next();
		}
		do {
			boolean flag = true;
			for(int i=0; i<n; i++) {
				if(Math.abs(getIndex(a[i], cow) - getIndex(b[i], cow)) != 1) { flag = false; break; }
			}
			if(flag) break;

		}while(next_permutation(cow));
		for(String x : cow) System.out.println(x);
	}
	static int getIndex(String x, String [] cow) {
		for(int i=0; i<cow.length; i++)
			if(cow[i].equals(x)) return i;
		return 0;
	}
	static boolean next_permutation(String a[]) {
		if(a.length <= 1) return false;
		int p = a.length - 2, q = a.length - 1;
		while(p>=0 && a[p].compareTo(a[p+1])>=0) p--;
		if(p < 0) return false;
		while(a[q].compareTo(a[p]) <= 0) q--;
		String tmp = a[p]; a[p] = a[q]; a[q] = tmp;
		for(int l=p+1, r=a.length-1; l<r; l++, r--) {
			tmp = a[l]; a[l] = a[r]; a[r] = tmp;
		}
		return true;
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