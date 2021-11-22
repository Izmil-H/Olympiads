import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
    public static void main(String [] args) throws IOException{
    	for(int t=1; t<=10; t++) {
    		int N = readInt(), mx = 0; pair[] a = new pair[N];
    		for(int i=0; i<N; i++) {
    			a[i] = new pair(readInt(), readDouble());
    			mx = Math.max(mx, a[i].d);
    		}
    		Arrays.sort(a);  int p[] = new int[mx+1]; double ans = 0.0;
    		for(int i=0; i<=mx; i++) p[i] = i;
    		for(int i=0; i<N; i++) {
    			int f = find(a[i].d, p);
    			if(f != 0) { p[f] = f-1; ans += a[i].w; }
    		}
    		System.out.printf("%.4f\n", ans);
    	}
    }
    static int find(int d, int p[]) {
    	if(d != p[d]) p[d] = find(p[d], p);
    	return p[d];
    }
    static class pair implements Comparable<pair>{
    	int d; double w;
    	pair(int d0, double w0){ d=d0; w=w0; }
    	public int compareTo(pair x) {
    		return -Double.compare(w, x.w);
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
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}