#include <iostream>
#include "tree_iterator_demo.h"
#include <cstdlib>
using std::cout;

int main()
{
  tree a;
  for(int i =0;i<20;++i)
    a.insert(std::rand()%5000);
  tree::node * s = a.begin();
  while(s)
  {
    cout<<s->i<<std::endl;
    s=a.next(s);
  }
  return 0;
}
