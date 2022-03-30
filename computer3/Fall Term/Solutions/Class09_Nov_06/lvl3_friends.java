import java.util.*;
public class Test{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		int [] friend = new int [10000];
		int n = in.nextInt();
		for(int i=0; i<n; i++)
			friend[in.nextInt()] = in.nextInt();
		while(true){
			int x = in.nextInt(), y = in.nextInt();
			if( x==0 && y==0 ) break;
			boolean [] vis = new boolean[10000];
			int dis = 0;
			while(!vis[x] && x != y){
				vis[x] = true;  x = friend[x]; dis++;
			}
			if(x==y) System.out.println("Yes "+(dis-1));
			else System.out.println("No");
		}
		
	}
}