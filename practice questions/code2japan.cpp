#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> s={{"VNV"},{"N.."}};
    int row=2,col=3;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    int i,j;
    int ans=0;
    vector<int> dir={1,-1,0,0};
    vector<int> dy={0,0,-1,1};
    vector<vector<int>>vis(row+1,vector<int>(col+1,0));
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            char a=(char)s[i][j];
            if( a=='V' && !vis[i][j])
            {
                int c=0;
                for(int k=0;k<4;k++)
                {
                    int ii=i+dir[k],jj=j+dy[k];
                    if(ii>=0 && ii<row && jj>=0 && jj<col && s[i+dir[k]][jj] == 'N' && !vis[ii][jj])
                        c++;
                }
                if(c==1)
                {
                    ans++;
                    vis[i][j]=1;
                     for(int k=0;k<4;k++)
                {
                         int ii=i+dir[k],jj=j+dy[k];
                    if(ii>=0 && ii<row && jj>=0 && jj<col && s[i+dir[k]][j+dy[k]] == 'N' && !vis[ii][jj]){
                        vis[i+dir[k]][j+dy[k]]=1;
                        break;
                     }
                }
                }
            }
            else 
                continue;
            
        }
    }
    
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            char a=(char)s[i][j];
            if( a=='V' && !vis[i][j])
            {
                int c=0;
                for(int k=0;k<4;k++)
                {
                    int ii=i+dir[k],jj=j+dy[k];
                    if(ii>=0 && ii<row && jj>=0 && jj<col && s[i+dir[k]][jj] == 'N' && !vis[ii][jj])
                        c++;
                }
                if(c>0)
                {
                    ans++;
                    vis[i][j]=1;
                     for(int k=0;k<4;k++)
                {
                         int ii=i+dir[k],jj=j+dy[k];
                    if(ii>=0 && ii<row && jj>=0 && jj<col && s[i+dir[k]][j+dy[k]] == 'N' && !vis[i+dir[k]][j+dy[k]]){
                        vis[i+dir[k]][j+dy[k]]=1;
                        break;
                     }
                }
                }
            }
            else 
                continue;
            
        }
    }  
    
    cout<<ans;
}