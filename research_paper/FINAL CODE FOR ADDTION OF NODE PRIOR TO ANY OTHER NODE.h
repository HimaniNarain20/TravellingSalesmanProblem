#include<iostream>
 
using namespace std;
 
int ary[4][4],completed[4],n=4,cost=0;
  int newar[8][8],newcomp[8];
void takeInput()
{
    int i,j;
 
   
 
    cout<<"\nEnter the Cost Matrix\n";
 
    for(i=0;i < n;i++)
    {
        cout<<"\nEnter Elements of Row: "<<i+1<<"\n";
 
        for( j=0;j < n;j++)
            cin>>ary[i][j];
 
        completed[i]=0;
    }
 
    cout<<"\n\nThe cost list is:";
 
    for( i=0;i < n;i++)
    {
        cout<<"\n";
 
        for(j=0;j < n;j++)
            cout<<"\t"<<ary[i][j];
    }
   
 int k1,k2,k5;
    for(k5=0;k5<n;k5++)
    {
        newcomp[k5]=completed[k5];
    }
    for(k1=0;k1<n;k1++)
    {
        for(k2=0;k2<n;k2++)
        {
            newar[k1][k2]=ary[k1][k2];
        }
    }
}
 
int least(int c,int n,int newar[][8],int newcomp[8])
{
    int i,nc=9999;
    int min=9999,kmin;
 
    for(i=0;i < n;i++)
    {
        if((newar[c][i]!=0)&&(newcomp[i]==0))
            if(newar[c][i]+newar[i][c] < min)
            {
                min=newar[i][0]+newar[c][i];
                kmin=newar[c][i];
                nc=i;
            }
    }
 
    if(min!=9999)
        cost+=kmin;
 
    return nc;
}
 
void mincost(int city)
{
    int i,j,ncity,prev,choice;
   
    cout<<"\nDo you want to add a city ??1 for yes and 0 for no!!!\n";
    cin>>choice;
	if(choice==1)
	{
	    int k3,k4,k6;
		int prevar[n][n];
		int prevcomp[n];
		for(k3=0;k3<n;k3++)
		{
		    for(k4=0;k4<n;k4++)
		    {
		        prevar[k3][k4]=newar[k3][k4];
		    }
		    
		}
		for(k6=0;k6<n;k6++)
		{
		    prevcomp[k6]=newcomp[k6];
		}
		prev=n;
		n=n+1;
		int newar[n][n];
		cout<<"you will have enter the distance of the added city from each of the cities !!!";
		for(i=0;i<n;i++)
		{
			
			for(j=0;j<n;j++)
			{
			if(i<prev)
			{
				newar[i][j]=prevar[i][j];
			}
			else if(i=prev)
			{
				
				cin>>newar[i][j];
			}				
		}
		}
		newcomp[city]=1;
 
    cout<<city+1<<"--->";
    ncity=least(city,n,newar,newcomp);
 
    if(ncity==9999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=newar[city][ncity];
 
        return;
    }
 
    mincost(ncity);
	 
	}
	else if(choice=0)
	{
		newcomp[city]=1;
 
    cout<<city+1<<"--->";
    ncity=least(city,n,newar,newcomp);
 
    if(ncity==9999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=newar[city][ncity];
 
        return;
		
	}

	
    
}
 
int main()
{
    takeInput();
    
    cout<<"\n\nThe Path is:\n";
    mincost(0); //passing 0 because starting vertex
 
    cout<<"\n\nMinimum cost is "<<cost;
 
    return 0;
}

