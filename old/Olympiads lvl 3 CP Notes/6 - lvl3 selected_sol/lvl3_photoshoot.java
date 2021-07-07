import java.util.*;
public class homework {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), a[] = new int[n+1], b[] = new int[n];
		for(int i=1; i<n; i++) b[i] = in.nextInt();
		for(int i=1; i<=n; i++) {
			boolean vis[] = new boolean[n+1], found = true;
			a[i] = 1; vis[1] = true;
	        for(int j=i-1; j>0 && found; j--){
	            a[j] = b[j] - a[j+1];
	            if(a[j] < 1 || a[j] > n || vis[a[j]] ){
	            	found = false; break;
	            }
	            vis[a[j]] = true;
	        }
	        for(int j=i+1; j<=n && found; j++){
	            a[j] = b[j-1] - a[j-1];
	            if(a[j] < 1 || a[j] > n || vis[a[j]] ){
	            	found = false; break;
	            }
	            vis[a[j]] = true;
	        }
	        if(found){
	            for(int j=1; j<=n; j++) System.out.print(a[j]+" "); 
	            return;
	        }	
		}
	}
}