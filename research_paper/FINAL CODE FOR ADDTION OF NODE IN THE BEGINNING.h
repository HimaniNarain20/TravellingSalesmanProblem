#include<iostream>
 
using namespace std;
 
int ary[4][4],completed[4],n=4,cost=0;
 
void takeInput()
{
    int i,j,int newar[n][n],int newcomp[n],choice,k1,k2,k3,k4,k5,k6,k7;
 
    cout<<"Enter the number of villages: ";
    cin>>n;
 
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
	
	
	cout<<"Do you want to add a node in the beginning of the journey?? 1 for yes and 0 for no...";
	cin>>choice;
	if(choice==1)
	{
		n=n+1;
		cout<<"You will have to enter the distance of the newly added city with ever other city";
		for(k3=0;k3<n;k3++)
		{
			cin>>newar[0][k3];
		}
		for(k4=1;k4<n;k4++)	
		{
			for(k5=1;k5<n;k5++)
			{
				newar[k4][k5]=ary[k4][k5];
			}
			
		}
		for(k6=0;k6<n-1;k6++)
		{
			newcomp[k6]=completed[k6];
		}
		newcomp[n]=0;
	}
	
	
	
	 
	
	
}
 
int least(int c)
{
    int i,nc=999;
    int min=999,kmin;
 
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
 
    if(min!=999)
        cost+=kmin;
 
    return nc;
}
 
void mincost(int city)
{
    int i,ncity;
	
    if(choice==1)
	{
    newcomp[city]=1;
 
    cout<<city+1<<"--->";
    ncity=least(city);
 
    if(ncity==999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=newar[city][ncity];
 
        return;
    }
 
    mincost(ncity);
	}
	else if(choice==0)
	{
		 completed[city]=1;
 
    cout<<city+1<<"--->";
    ncity=least(city);
 
    if(ncity==999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=ary[city][ncity];
 
        return;
    }
 
    mincost(ncity);
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

