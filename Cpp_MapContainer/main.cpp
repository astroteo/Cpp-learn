#include <iostream>
#include<vector>
#include <map>

using namespace std;


int main()
{
  map< string , vector<int> > m;

  vector<int> v1;
  vector<int> v2;
  for(int i=0; i< 10; ++i)
  {
    if(i % 2 ==0 )
    {
      v1.push_back(i);
    }
    else
    {
      v2.push_back(i);
    }
  }

  m["even"]= v1;
  m["odd"] = v2;

  vector<int> v_even = m["even"];
  vector<int> v_odd = m["odd"];

  cout << "even numbers..."<<endl;
  for(int i =0; i< v_even.size(); ++i)
  {
    cout <<v_even[i]<<endl;
  }

  cout << "odd numbers..."<<endl;
  for(int i =0; i< v_even.size(); ++i)
  {
    cout <<v_odd[i]<<endl;
  }


  cout << "Map-> python dictionaries ==> perfect match" << endl;

  return 0;
}
