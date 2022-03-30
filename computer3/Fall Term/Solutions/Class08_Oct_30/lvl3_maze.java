import java.util.*;
public class ccc08s3 {
	static int [][] d = {{0, 1}, {1,0}, {0,-1}, {-1,0}};
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		for(int t=in.nextInt(); t!=0; t--){
			int r=in.nextInt(), c=in.nextInt();
			char [][] grid = new char[r][c];
			int [][] step = new int[r][c];
			for(int i=0; i<r; i++){
				grid[i] = in.next().toCharArray();
			}
			Queue<Point> Q = new LinkedList<Point>();
			Q.add(new Point(0, 0)); step[0][0]=1;
			while(!Q.isEmpty()){
				Point cur = Q.poll();
				if(grid[cur.x][cur.y]=='+'){
					for(int k=0; k<4; k++){
						int nr = cur.x+d[k][0], nc=cur.y+d[k][1];
						if(nr>=0&&nr<r&&nc>=0&&nc<c&&grid[nr][nc]!='*'&&step[nr][nc]==0){
							Q.add(new Point(nr, nc)); step[nr][nc]=step[cur.x][cur.y]+1;
						}
					}
				}else if(grid[cur.x][cur.y]=='-'){
					for(int k=0; k<4; k+=2){
						int nr = cur.x+d[k][0], nc=cur.y+d[k][1];
						if(nr>=0&&nr<r&&nc>=0&&nc<c&&grid[nr][nc]!='*'&&step[nr][nc]==0){
							Q.add(new Point(nr, nc)); step[nr][nc]=step[cur.x][cur.y]+1;
						}
					}
				}else if(grid[cur.x][cur.y]=='|'){
					for(int k=1; k<4; k+=2){
						int nr = cur.x+d[k][0], nc=cur.y+d[k][1];
						if(nr>=0&&nr<r&&nc>=0&&nc<c&&grid[nr][nc]!='*'&&step[nr][nc]==0){
							Q.add(new Point(nr, nc)); step[nr][nc]=step[cur.x][cur.y]+1;
						}
					}
				}
			}
			if(step[r-1][c-1]==0) System.out.println(-1);
			else System.out.println(step[r-1][c-1]);
		}
	}
	static class Point{
		int x, y;
		Point(int x0, int y0){
			x=x0; y=y0;
		}
	}
	
}