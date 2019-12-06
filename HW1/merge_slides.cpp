//merge

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999L
int cnt=0;
using namespace std;

void MinMult(int **mArray, int **mArrayIndex,int *mWeight, int mSize);
void PrintOrder(int *mWeight, int **mArrayIndex, int num1, int num2);
pair<int, int> MinPath(const vector<pair<int, int> > & mVec);



int main() {

    while (true) {
        cnt=0;

        string strInput;
        getline(cin, strInput);
        string strNum = "";
        vector<int> p;

        for (int i = 0; i < (int) strInput.length(); i++) {
            if(strInput.at(i)==' ' && strInput.at(i+1)==' ') return 0;
            if (strInput.at(i) == ' ' || strInput.at(i) == '\t') {
                p.push_back(atoi(strNum.c_str()));
                strNum = "";
            } else {
                strNum += strInput.at(i);
                continue;
            }
        }
        p.push_back(atoi(strNum.c_str()));

        //2차원 배열 동적할당 과정
        int n = (int) p.size();
        int *mWeight = new int[n];
        int **mArray=new int*[n];
        int **mArrayIndex=new int*[n];
        for(int i=0; i<n; i++){
            mArray[i] = new int[n];
            mArrayIndex[i] = new int[n];
        }

        for (int i = 1; i < n; i++) {
            mArray[i][i] = mArrayIndex[i][i] = 0;
        }

        for (int i = 0; i < n; i++) {
            mWeight[i] = p[i];
        }

        if (mWeight[0] == '\0') break;


        MinMult(mArray, mArrayIndex,mWeight, n);
        PrintOrder(mWeight, mArrayIndex,0, n - 1);

        cout << endl;

        for(int i=0; i<n; i++){
            delete [] mArray[i];
            delete [] mArrayIndex[i];
        }
        delete[] mWeight;
        delete[] mArray;
        delete[] mArrayIndex;

    }
    return 0;

}

void MinMult(int **mArray, int **mArrayIndex, int *mWeight, int mSize) {
    vector<pair<int, int> > mVector;

    for (int i = 1; i < mSize; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int sum = 0;
            for (int s = j; s <= i; s++) {
                sum += mWeight[s];
            }

            mVector.clear();
            for (int k = j; k < i; k++) {
                mVector.push_back(
                        make_pair(mArray[j][k] + mArray[k + 1][i] + sum, k));
            }
            const pair<int, int> mTemp_Pair = MinPath(mVector);
            mArray[j][i] = mTemp_Pair.first;
            mArrayIndex[j][i] = mTemp_Pair.second;
        }
    }
    cout << mArray[0][mSize - 1] << " ";
}

void PrintOrder(int *mWeight, int **mArrayIndex, int num1, int num2) {
    if (num1 == num2) {
        if(cnt==0) cout << mWeight[num1];
        else cout << "," << mWeight[num1];

        cnt++;
        return;
    }
    else {
        const int mTemp = mArrayIndex[num1][num2];
        cout << '(';
        cnt=0;
        PrintOrder(mWeight, mArrayIndex, num1, mTemp);
        PrintOrder(mWeight, mArrayIndex, mTemp + 1, num2);
        cout << ')';
    }
}


pair<int,int> MinPath(const vector<pair<int,int> > & mVec){
    int mMin = INF;
    int mSize = mVec.size();
    int mMarker = 0;

    for(int i=0; i<mSize; i++){
        if(mMin>mVec[i].first){
            mMin=mVec[i].first;
            mMarker=mVec[i].second;
        }
    }
    return make_pair(mMin, mMarker);
}

