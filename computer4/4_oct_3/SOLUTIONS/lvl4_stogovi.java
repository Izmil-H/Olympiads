import java.util.*;
import java.io.*;

public class Test {
	static final int D = 19; static int dep[] = new int[300002], v[] = new int[300002], lca[][] = new int[D][300002];
	public static void main(String[] args) throws IOException {
		for(int i=0; i<D; i++)
			Arrays.fill(lca[i], -1);
		int N = readInt();
		for(int i = 1; i<=N; i++) {
			String cmd = read(); int cp = readInt();  
			if(cmd.equals("a")) {
				int t = v[cp]; v[i]=i; dep[i] = dep[t] + 1; lca[0][i] = t;
				for(int j=1; j<D; j++) 
					if(lca[j-1][i]>=0) lca[j][i] = lca[j-1][lca[j-1][i]];
					else break;
			}else if(cmd.equals("b")) { println(v[cp]); v[i] = lca[0][v[cp]]; }
			else {
				int pp = readInt(); v[i] = v[cp]; 
				println(dep[lca(v[cp], v[pp])]);
			}
		}
		exit();
	}
	public static int lca(int u, int v){
		int x = u, y = v;
		if(dep[u] < dep[v]) {x = v; y = u;}
		for(int i=D-1; i>=0; i--)
			if(lca[i][x] != -1 && dep[lca[i][x]] >= dep[y]) x = lca[i][x];
		if(x == y) return y;
		for(int i=D-1; i>=0; i--)
			if(lca[i][x]!=-1 && lca[i][y]!=-1 && lca[i][x]!=lca[i][y]){
				x = lca[i][x]; y = lca[i][y];
			}
		return lca[0][x];
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[64]; // line length
		int cnt = 0, c;
		while ((c = Read()) != -1) {
			if (c == '\n')
				break;
			buf[cnt++] = (byte) c;
		}
		return new String(buf, 0, cnt);
	}
	public static String read() throws IOException{
		byte[] ret = new byte[1024];
        int idx = 0;
        byte c = Read();
        while (c <= ' ') {
            c = Read();
        }
        do {
            ret[idx++] = c;
            c = Read();
        } while (c != -1 && c != ' ' && c != '\n' && c != '\r');
        return new String(ret, 0, idx);
	}
	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}

	public static double readDouble() throws IOException {
		double ret = 0, div = 1;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();

		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (c == '.') {
			while ((c = Read()) >= '0' && c <= '9') {
				ret += (c - '0') / (div *= 10);
			}
		}

		if (neg)
			return -ret;
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}