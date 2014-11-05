#include <iostream>
using std::cout;

class tree {
  public:
    tree(void)=default;
    ~tree(void)=default;
    void insert(int j)
    {
      _insert(j, root, nullptr);
    }
 public:
   struct node {
     int i;
     node * u = nullptr;// add a ref to parent node for iterator
     node * l = nullptr;
     node * r = nullptr;
     node(int j):i(j){}
   };
   typedef node* iterator;
  private:
   void _insert(int j, node *&n, node *p)
   {
     // p must be the parent node of n ,i.e. p == n->u
     if (!n)
     {
       n =new node(j);
       n->u =p;
     }
     else if(j > n->i)
     {
        _insert(j, n->r, n);
     }
     else if (j < n->i)
     {
         _insert(j, n->l, n);
     }
     // j == n->i  , do not insert
   }

     node * root = nullptr;
     //iterator part
  public:
     iterator begin(void)
     {
       return leftmost(root);
     }
     iterator next(iterator c)
     {
       if(!c) return nullptr;// guard, no next.
       if(c->r)  return leftmost(c->r);// the least one in right tree
       //if it is a right node of of its upper one, go up.
       while(c->u &&c->u->r==c)
          c= c->u;
       //Here c has no parent, or it is not a right child.
       //If no parent, no one will larger than c. return null;
       //If c is a left child, the parent is larger.
       //In either case, c->u is the right one to return.
        return c->u;
     }
 private:
     iterator leftmost(iterator i){
       if (!i) return nullptr;
       while( i->l )
           i =i->l;
       return i;
     }
};

