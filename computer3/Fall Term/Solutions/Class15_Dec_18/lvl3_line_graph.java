import java.util.*;

import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int [] p = new int[100002];
    public static void main(String[] args) throws IOException {
    	int n = readInt(), k = readInt(), ans = 0, cnt=0;  edge[] e = new edge[n-1];
    	for(int i=0; i<=n; i++) p[i] = i % k;
    	for(int i=0; i<n-1; i++){
    		int w = readInt(); e[i] = new edge(i+1, i+2, w);
    	}
    	Arrays.sort(e);
    	for(edge t: e){
    		int fu = find(t.u), fv = find(t.v);
    		if(fu != fv) { ans+=t.w; p[fu] = fv; cnt++;}
    		if(cnt == k-1) break;
    	}
    	System.out.println(ans);
    }
    public static class edge implements Comparable<edge>{
    	int u, v, w;
    	edge(int u0, int v0, int w0){ u=u0; v=v0; w=w0; }
    	public int compareTo(edge x){ return w-x.w; }
    }
    public static int find(int d){
    	if(d != p[d]) p[d] = find(p[d]);
    	return p[d];
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