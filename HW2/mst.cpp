#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> v;

struct str{
    int s,e,w;
    str(int s,int e,int w):s(s),e(e),w(w){};
};

bool operator<(str s1,str s2){
    return s1.w<s2.w;
}

int parent[1001]={0};
int find(int k){
    while(parent[k]!=k){
        k=parent[k];
    }
    return k;
}
int main(){

    while(true) {
        int N, M;

        string c;
        fflush(stdin);
        getline(cin, c);
        if(c[0]=='\0') break;

        for(int i=0; i<(int)c.length(); i++){
            if(c[i]==' ') continue;
            else v.push_back(c[i]-48);
        }
        N=v[0];
        M=v[1];

        int s, e, w;
        vector<str> vec;
        for (int i = 0; i < M; i++) {
            cin >> s >> e >> w;
            vec.push_back(str(s, e, w));
        }

        int ans = 0;
        int p1, p2 = 0;
        sort(vec.begin(), vec.end());

        for (int i = 1; i <= N; i++)
            parent[i] = i;

        for (int i = 0; i < (int)vec.size(); i++) {

            p1 = find(vec[i].s);
            p2 = find(vec[i].e);

            if (p1 == p2)
                continue;

            if (p1 < p2) parent[p1] = p2;
            else parent[p2] = p1;
            ans += vec[i].w;
        }

        cout << ans << endl;

        vec.clear();
        v.clear();
    }
    return 0;
}
