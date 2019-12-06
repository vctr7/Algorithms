#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
int inf=0xfffffff;
vector<vector<int> > W;
vector<int> v;

void dijkstra(int start,int end){

    vector<bool> visited(n+1,false);
    vector<int> dist(n+1,inf);

    for(int i=1;i<=n;i++)
        dist[i]=W[start][i];

    int cnt=n;
    int vnear=start;
    visited[start]=true;

    while(cnt--){

        int min_dist=inf;
        for(int i=1;i<=n;i++){ //vnear 구하기
            if(!visited[i] && min_dist>dist[i]){
                vnear=i;
                min_dist=dist[i];
            }
        }

        for(int i=1;i<=n;i++){
            if(visited[i] || W[vnear][i]==inf)
                continue;

            if(dist[vnear]+W[vnear][i]<dist[i])
                dist[i]=dist[vnear]+W[vnear][i];
        }
        visited[vnear]=true;
    }

    cout<<dist[end]<<endl;
}
int main(){

    while(true) {
        string c;
        fflush(stdin);
        getline(cin, c);
        if(c[0]=='\0') break;

        for(int i=0; i<(int)c.length(); i++){
            if(c[i]==' ') continue;
            else v.push_back(c[i]-48);
        }
        n=v[0];
        m=v[1];

        W = vector<vector<int> >(n + 1, vector<int>(n + 1, inf));

        int start, end, cost;
        for (int i = 0; i < m; i++) {
            cin >> start >> end >> cost;
            W[start][end] = min(W[start][end], cost);
        }


        dijkstra(1, n);
        W.clear();
        v.clear();
    }

    return 0;
}

