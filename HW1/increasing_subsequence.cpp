#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



//char v[1001];
vector<char> arr;
vector<char>answer;

void go(char *v, int index) {
    if (index == -1) {

        return;
    }
    answer.push_back(arr[index]);
    go(v, v[index]);

}

int main() {
    while(true){
        string input;



        getline(cin, input);
        for(int i=0; i<(int)input.length(); i++){
            if(input[i]==' ') break;
            arr.push_back(input[i]);
        }


        if(input[0]=='\0')break;

        int len=arr.size();
        int d[len+1];

        char *v = new char[len];

//        for (int i = 0; i < len; i++) {
//            cin >> arr[i];
//        }

        for (int i = 0; i < len; i++) {
            v[i] = -1;
            d[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                    v[i] = j;
                }
            }
        }

        int ans = 0;
//
        for (int i = 0; i < len; i++) {
            ans = max(ans, d[i]);
        }
//
//        cout << ans << endl;

        for (int i = 0; i < len; i++) {
            if (d[i]==ans){
                answer.push_back(arr[i]);
                go(v,v[i]);
                break;
            }
        }

        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i];
        }
        cout<<endl;

        arr.clear();
        answer.clear();

    }



    return 0;

}