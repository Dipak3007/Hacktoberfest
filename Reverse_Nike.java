class Reverse{
	public static void main(String arg[]){
		int n=Integer.parseInt(arg[0]);
		int t=n,rev=0,r;
		while(t!=0){
			r=t%10;
			rev=rev*10+r;
			t/=10;
		}
		System.out.print("Reverse of "+n+" = "+rev);
	}
}
