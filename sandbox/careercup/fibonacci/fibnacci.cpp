#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo(int range);

int main()
{
  vector<int> sum;
  int range;
  cout<<"Enter the number range: "<<endl;
  cin>>range;
  sum = fibo(range);
  cout<<"Output : ";
  for(unsigned int i=0 ; i<sum.size() ; i++){
    cout<<sum[i]<<" ";
  }

  return 0;
}

vector<int> fibo(int range) {

  vector<int> temp;
  temp.push_back(0);
  temp.push_back(1);
  int i=0;
  while(temp.size() < range) {
    temp.push_back(temp[i+1]+temp[i]);
    i++;
  }
  return temp;
}
