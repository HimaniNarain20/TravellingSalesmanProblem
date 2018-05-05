#include<iostream>
 
using namespace std;
 
int ary[5][5],completed[5],n=5,cost=0, path[6], z = 0;
 
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
}
 
int least(int c)
{
    int i,nc=9999;
    int min=9999,kmin;
 
    for(i=0;i < n;i++)
    {
        if((ary[c][i]!=0)&&(completed[i]==0))
            if(ary[c][i]+ary[i][c] < min)
            {
                min=ary[i][0]+ary[c][i];
                kmin=ary[c][i];
                nc=i;
            }
    }
 
    if(min!=9999)
        cost+=kmin;
 
    return nc;
}
 
void mincost(int city)
{
    int i,j,ncity,prev,choice,newar[n][n];
    int k1,k2,k3,k4,k;
    for(k1=0;k1<n;k1++)
    {
        for(k2=0;k2<n;k2++)
        {
            newar[k1][k2]=ary[k1][k2];
        }
    }
    
    cout<<"\nDo you want to delete a city? 1 for yes and 0 for no\n";
    cin>>choice;

	if(choice==1)
	{
	    cout<<"\nEnter the city you want to delete\n";
        cin>>k;
        k = k-1;
    
		int prevar[n][n];
		for(k3=0;k3<n;k3++)
		{
		    for(k4=0;k4<n;k4++)
		        prevar[k3][k4]=newar[k3][k4];
		}
		
		prev=n-1;
		n=n-1;
		int newar[n][n];
		
        for(i = 0; i < k; i++)
        {
            for(j = 0; j < k; j++)
                newar[i][j] = prevar[i][j];
        }
    
        for(i = 0 ; i < k; i++)
        {
            for(j = k+1; j <= n; j++)
                newar[i][j-1] = prevar[i][j];
        }
    
        for(i = k+1 ; i <= n; i++)
        {
            for(j = 0; j < k; j++)
                newar[i-1][j] = prevar[i][j];
        }
    
        for(i = k+1 ; i <= n; i++)
        {
            for(j = k+1; j <= n; j++)
                newar[i-1][j-1] = prevar[i][j];
        }
    
        cout<<"\n\nThe new matrix is:";
 
        for( i=0;i < n;i++)
        {
            cout<<"\n";
     
            for(j=0;j < n;j++)
                cout<<"\t"<<newar[i][j];
        }
    }
    
    completed[city]=1;
 
    path[z] = city+1;
    z = z+1;
    //cout<<city+1<<"--->";
    ncity=least(city);
 
    if(ncity==9999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=newar[city][ncity];
 
        return;
    }
 
    mincost(ncity);
}
 
int main()
{
    takeInput();
 
    cout<<"\n\nThe Path is:\n";
    mincost(0); //passing 0 because starting vertex
    for(int i = 0; i < n; i++)
        cout<<path[i]<<"-->";
    cout<<"1";
 
    cout<<"\n\nMinimum cost is "<<cost;
 
    return 0;
}