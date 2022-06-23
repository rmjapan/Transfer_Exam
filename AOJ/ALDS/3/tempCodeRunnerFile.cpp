#include<bits/stdc++.h>
using namespace std;

int main(){
  int q,x;
  char com[20];
  list<int> v;
  scanf("%s",com);
  if(com[0] == 'i'){
    scanf("%d",&x);
    v.push_front(x);
  }else if(com[6] == 'L'){
    v.pop_back();
  }else if(com[6] == 'F'){
    v.pop_front();
  }else if(com[0] == 'd'){
    scanf("%d",&x);
    for(list<int>::iterator it = v.begin(); it!=v.end(); it++){
      if(*it == x){
        v.erase(it);
        break;
      }
    }
  }
  int i = 0;
  for(list<int>::iterator it = v.begin(); it!=v.end(); it++){
    if(i>0) printf(" ");
    printf("%d", *it);
  }
  printf("\n");
  return 0;
}