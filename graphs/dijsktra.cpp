class Solution {
public:
    void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt) { 
        adj[u].push_back(make_pair(v, wt)); 
    } 
    int mind(vector<int> &dis,vector<bool> &vis,int N)
    {
        int mn=INT_MAX,mi=-1;
        for(int i=1;i<N+1;i++)
            if(!vis[i] && dis[i]<=mn)
                mn=dis[i],mi=i;
        return mi;
    }
    vector<int> dijsktra(vector <pair<int, int>> adj[],int N,int K)
    {
        vector<bool> vis(N+1,false);
        vector<int> dis(N+1,INT_MAX);
        dis[K]=0;
        for(int cnt=0;cnt<N;cnt++)
        {
            int curr=mind(dis,vis,N);
            vis[curr]=true;
        
            for(int i=0;i<adj[curr].size();i++)
            {
            
                int v=adj[curr][i].first;
                if(!vis[v] && dis[curr]!=INT_MAX && dis[curr]+adj[curr][i].second < dis[v])
                    dis[v]= dis[curr] + adj[curr][i].second; 
                    
            }
            
        }
        return dis;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector <pair<int, int>> adj[N+1];
        for(int i=0;i<times.size();i++)
            addEdge(adj,times[i][0],times[i][1],times[i][2]);
        vector<int> v=dijsktra(adj,N,K);
        int mx=INT_MIN;
        for(int i=1;i<v.size();i++)
        {
        
            if(v[i]==INT_MAX)
                return -1;
            mx=max(mx,v[i]);
        }
        return mx;
        
        
        
    }
};
