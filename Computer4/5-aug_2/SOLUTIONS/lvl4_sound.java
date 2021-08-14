import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(), c = readInt(), a[] = new int[n+1];  boolean found = false;
		for(int i=1; i<=n; i++) a[i] = readInt();
		Deque<Integer> min = new ArrayDeque(), max = new ArrayDeque();
		for(int l=1, r=1; r<=n; r++) {
			while(l <= r-m) { 
				if(min.peekFirst()==a[l]) min.pollFirst();
				if(max.peekFirst()==a[l]) max.pollFirst();
				l++;
			}
			while(!min.isEmpty() && min.peekLast() > a[r]) min.pollLast();
			while(!max.isEmpty() && max.peekLast() < a[r]) max.pollLast();
			min.addLast(a[r]); max.addLast(a[r]);
			if(r>=m && max.peekFirst() - min.peekFirst() <= c) {
				System.out.println(r-m+1);  found=true;
			}
		}
		if(!found) System.out.println("NONE");
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