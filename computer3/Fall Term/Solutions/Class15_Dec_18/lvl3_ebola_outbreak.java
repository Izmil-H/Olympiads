import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int [] p = new int[100002], rk = new int[100002], sz = new int[100002];
    public static void main(String[] args) throws IOException {
    	int n = readInt(), k = readInt();
    	for(int i=1; i<=n; i++) { p[i] = i; sz[i] = 1; }
    	for(int i=1; i<=k; i++){
    		int num = readInt(), x = readInt();
    		for(int j=1; j<num; j++){
    			int y = readInt(), fy = find(y), fx = find(x);
    			if(fx != fy) merge(fx, fy);
    		}
    		
    	}
    	int f1 = find(1);  System.out.println(sz[f1]);
    	for(int i=1; i<=n; i++)
    		if(find(i) == f1) System.out.print(i+" ");
    }
    public static int find(int d){
    	if(d != p[d]) p[d] = find(p[d]);
    	return p[d];
    }
    public static void merge(int x, int y){
    	if(rk[x] > rk[y]) { p[y] = x;  sz[x] += sz[y]; }
    	else { 
    		p[x] = y; sz[y] += sz[x]; 
    		if(rk[x] == rk[y]) rk[y]++;
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