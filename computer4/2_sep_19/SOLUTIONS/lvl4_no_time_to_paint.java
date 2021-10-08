import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner k =new Scanner(System.in);
		
		int n = k.nextInt();
		int q = k.nextInt();
		
		String a = k.next();
		
		int[] pre = new int[n+1];
		int[] suf = new int[n+2];
		proc(a, pre);
		proc(new StringBuilder(a).reverse().toString(), suf);
		
//		System.out.println(Arrays.toString(pre));
//		System.out.println(Arrays.toString(suf));
		for(int l=1, r=n; l<r; l++, r--) {
			int tmp = suf[l]; suf[l]=suf[r]; suf[r] = tmp;
		}
		for(int i = 0; i < q; i++) {
			int s = k.nextInt();
			int e = k.nextInt();
			
			System.out.println(pre[s-1]+suf[e+1]);
		}
	}
	static void proc(String a, int pre[]) {
		boolean [] vis = new boolean[26];
		for(int i = 0; i < a.length(); i++) {
			int c = a.charAt(i) - 'A';  
			if(!vis[c]) pre[i+1] = pre[i] + 1;
			else pre[i+1] = pre[i];
			vis[c] = true;
			for(int j=c+1; j<26; j++) vis[j] = false;
		}
	}

}