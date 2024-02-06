#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;
void merge(vector <string> &leftv, vector <string> &rightv, vector <string> &v){
  int len=v.size();
  int lSize=len/2;
  int rSize=len-lSize;
  int i=0,l=0,r=0;
  while(l<lSize && r<rSize){
    if(leftv[l].size()<rightv[r].size()){
      v[i]=leftv[l];
      l++;
    }
    else if(leftv[l].size()>rightv[r].size()){
      v[i]=rightv[r];
      r++;
    }
    else{
      v[i]=leftv[l];
      l++;
    }
    i++;
  }
  while(l<lSize){
    v[i]=leftv[l];
    l++;
    i++;
  }
  while(r<rSize){
    v[i]=rightv[r];
    r++;
    i++;
  }
}
void mergeSort(vector <string> &v){
  int len=v.size();
  if(len<=1){
    return;
  }
  int mid=len/2;
  vector <string> leftv(mid);
  vector <string> rightv(len-mid);
  int i=0,j=0;
  for(;i<len;i++){
    if(i<mid){
      leftv[i]=v[i];
    }
    else{
      rightv[j]=v[i];
      j++;
    }
  }
  mergeSort(leftv);
  mergeSort(rightv);
  merge(leftv, rightv, v);
}
int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        vector<string> v;
        istringstream iss(s);
        string t;

        while (iss >> t) {
            v.push_back(t);
        }
        mergeSort(v);
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }

}