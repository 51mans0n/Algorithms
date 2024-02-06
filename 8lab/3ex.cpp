#include <iostream>
#include <vector>
using namespace std;
long long int calcHash(string s){
  long long int hash=0;
  int q=10000000000007;
  for(int i=0;i<s.size();i++){
    hash=(hash*31+s[i])%q;
  }
  return hash;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  int n;
  cin>>n;
  string t;
  int k=s.size();
  vector<bool> v(k,false);
  for(int i=0;i<n;i++){
    cin>>t;
    long long int pattern=0;
    int c=t.size();
    long long int hash=0,q=10000000000007,exp=1;
    for (int j = 0; j < c - 1; j++)
        exp = (exp * 31) % q;
//    string str;
    for(int j=0;j< c;j++){
//      str+=s[j];
      hash=(31*hash + s[j]) % q;
      pattern=(31*pattern + t[j]) % q;
    }
//    cout<<str<<endl;
    for(int j=0;j<=k-c;j++){
      if(pattern==hash){
        for(int l=j;l<j+c;l++){
          v[l]=true;
        }
      }
      if(j<k-c){
        hash = ((31 * (hash - s[j] * exp) + s[j+c]) % q);
      }
      if(hash<0){
        hash+=q;
      }
    }
  }
  
  
  bool res=true;
  for(int i=0;i<k;i++){
    if(v[i]==false){
      res=false;
      break;
    }
  }
  if(res){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
  
  return 0;
}