#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define mrepd(i,a,b) for (int i=(b-1);i>=(a);i--)
#define rep(i,n) repd(i,0,n)
#define mrep(i,n) mrepd(i,0,n)

#define M 1000000
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
}

/* convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){
  return key % M;
}

int h2(int key){
  return 1 + (key % M);
}

bool find(char str[]){
  int this_key = getKey(str);
  int temp = h1(this_key);
  int this_h2 = h2(this_key);
  bool flg;
  while (H[temp][0] != '\0') {
    flg = true;
    rep(i, strlen(str)) {
      if (H[temp][i] != str[i]) {
        flg = false;
        break;
      }
    }
    if (flg) return true;
    temp = (temp + this_h2) % M;
  }
  return false;
}

void insert(char str[]){
  int this_key = getKey(str);
  int first_h1 = h1(this_key);
  int this_h2 = h2(this_key);
  int temp = first_h1;
  while (true) {
    if (H[temp][0] != '\0') {
      rep(i, strlen(str)) H[temp][i] = str[i];
      return;
    }
    temp = (temp + this_h2) % M;
    if (temp == first_h1) {
      cout << "ERROR" << endl;
      return;
    }
  }
}

int main(){
  int i, n, h;
  char str[L], com[9];
  for ( i = 0; i < M; i++ ) H[i][0] = '\0';

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ){
    scanf("%s %s", com, str);

    if ( com[0] == 'i' ){
      insert(str);
    } else {
      if (find(str)){
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }

  return 0;
}
