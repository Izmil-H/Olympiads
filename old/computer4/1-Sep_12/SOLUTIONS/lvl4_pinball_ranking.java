import java.util.*;
import java.io.*;
public class ccc05s5 {
	static int [] a = new int[100002];
	static TreeSet<Integer> b = new TreeSet<Integer>();
	static int [] c = new int [100002];
	static int [] bit = new int [100002];
	static long ans = 0;
	static int N = 0;
	public static void main(String [] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		for(int i=0; i<N; i++){
			a[i] = Integer.parseInt(br.readLine());
			b.add(a[i]);
		}
		int cnt = 0;
		for(int m : b) c[cnt++] = m;
		for(int i=0; i<N; i++){
			int rk = Arrays.binarySearch(c, 0, cnt, a[i])+1;
			ans += i - query(rk) + 1;
			update(rk, 1);
		}
		System.out.printf("%.2f", (ans*100/N)/100.0);
	}
	static void update(int pos, int v){
		for(int i=pos; i<=N; i+= i&-i)
			bit[i] += v;
	}
	static int query(int pos){
		int sum = 0;
		for(int i=pos; i>0; i-= i&-i)
			sum += bit[i];
		return sum;
	}
}