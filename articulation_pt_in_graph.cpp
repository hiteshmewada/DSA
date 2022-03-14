// ARTICULATION point is the vertex in an undirected connected graph which after removing it disconnects graph
// It is also known as Trajan's Algorithm
#include<bits/stdc++.h>;
using namespace std;
/*  recursive function that finds articulation point using dfs
    u->Vertex to be visited next
    disc[]-> stores discovery time of visited vertices
    low[]-> vertex with min discovery time that can be reached from subtree rooted with current vertx
    parent-> stores parent vertex in DFS tree
    isAP[]->stores articulation points
*/
void APUtil(vector<int>adj[],int u,bool vis[],int disc[],int low[],int &time,int par, bool isAP[]){
    // Count of children in dfs tree
    int child=0;
    // Mark current node visited
    vis[u]=true;
    // Initialise discovery time and low value
    disc[u]=low[u]=++time;
    for(auto x:adj[u]){
        // if x is not visited yet then make it a child of u in dfs tree and recur for it
        if(!vis[x]){
            child++;
            APUtil(adj,x,vis,disc,low,time,u,isAP);
            // check if subtree rooted with x has a connection to one of ancestors of u
            low[u]=min(low[u],low[x]);
            // if u is not root and low value of one of its child is more than discovery value of u
            if(par!=-1 and low[x]>=disc[u]) isAP[u]=true;
        }
        else if(x!=par)
            low[u]=min(low[u],disc[x]);
    }
    // if u is root of dfs tree and has two or more children
    if(par==-1 and child>1) isAP[u]=true;
}
void AP(vector<int>adj[],int v){
    int disc[v]={0};
    int low[v];
    bool vis[v]={false};
    bool isAP[v]={false};
    int time=0,par=-1;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            APUtil(adj,i,vis,disc,low,time,par,isAP);
        }
    }
    // printing APS
    for(int i=0;i<v;i++){
        if(isAP[i]) cout<<i<<" ";
    }
}
void addEdge(vector<int>adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    /// Call function and create graph to print articulation points
}