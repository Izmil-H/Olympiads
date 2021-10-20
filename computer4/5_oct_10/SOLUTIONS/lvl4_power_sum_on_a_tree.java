import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int MM = (int)3e5+5, LOG = 19, mod = 998244353;
    static int N, Q, dep[] = new int[MM], anc[][] = new int[LOG][MM];
    static ArrayList<Integer> adj[] = new ArrayList[MM];
    static long p[][] = new long[MM][51];
    static void dfs(int u, int pa){
        dep[u] = dep[pa]+1; anc[0][u] = pa; p[u][0] = 1;
        for(int i = 1; i < LOG; i++) anc[i][u] = anc[i-1][anc[i-1][u]];
        for(int i = 1; i <= 50; i++) p[u][i] = p[u][i-1]*(dep[u]-1)%mod;
        for(int i = 1; i <= 50; i++) p[u][i] = (p[pa][i] + p[u][i])%mod;
        for(int v:adj[u]){
            if(v != pa) dfs(v, u);
        }
    }
    static int LCA(int u, int v){
        if(dep[u] < dep[v]){
            int temp = u;
            u = v;
            v = temp;
        }
        for(int i = LOG-1; i >= 0; i--)
            if(dep[anc[i][u]] >= dep[v])
                u = anc[i][u];
        if(u == v)
            return u;
        for(int i = LOG-1; i >= 0; i--){
            if(anc[i][u] != anc[i][v]){
                u = anc[i][u];
                v = anc[i][v];
            }
        }
        return anc[0][u];
    }
    public static void main(String[] args) throws IOException {
        
        N = readInt();
        for(int i = 0; i < MM; i++){
            adj[i] = new ArrayList<>();
        }
        for(int i = 1, u, v; i<N; i++){
            u = readInt(); v = readInt();
            adj[u].add(v); 
            adj[v].add(u);
        }
        dfs(1, 0);
        Q = readInt();
        for(int i = 1, u, v, k; i <= Q; i++){
            u = readInt(); v = readInt(); k = readInt();
            int rt = LCA(u, v);
            System.out.println(((p[u][k]+p[v][k]-p[rt][k]-p[anc[0][rt]][k])%mod+mod)%mod);
        }
    }
    
    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        }
        return st.nextToken();
        
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    
    static char readCharacter() throws IOException {
        return next().charAt(0);
        
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}