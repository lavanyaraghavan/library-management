#include<iostream>
#include<math.h>
#include<string.h>
#include<cstdio>
#include<stdlib.h>
#define count 5
using namespace std;
template <class T>

class AvlTree
{
  struct AvlNode
 {
	T e;
	AvlNode* r;
	AvlNode* l;
	int h;
	AvlNode(T &x,AvlNode *lt,AvlNode *rt,int he=0) : e(x),l(lt),r(rt),h(he) {}
 };
 AvlNode* root;
 void makeEmpty (AvlNode* &t);
 void printTree(AvlNode* t) const;
 bool Contains(AvlNode* &t,string ele);
 int Height (AvlNode* t) const;
 void Insert( T &x,AvlNode* &t);
 void balance(AvlNode *&t);
 void Display(AvlNode *root, int space);
 void singlerotatewithleft(AvlNode* &k2);
 void doublerotatewithleft(AvlNode* &k2);
 void singlerotatewithright(AvlNode* &l2);
 void doublerotatewithright(AvlNode* &l2);
 void del (T &x,AvlNode* &t);
 const T& findMin(AvlNode *t);

 public:
	AvlTree():root(NULL) {}
	~AvlTree()
	{
	}
	void Insert(T &x);
	void makeEmpty() ;
	void printTree() const;
	bool isEmpty() const ;
	bool Contains(string ele);
	void Display();
    void del(T &x);
};

template <class T>
void AvlTree<T> :: Insert(T &x){Insert (x,root);}
template <class T>
void AvlTree<T> :: makeEmpty() { makeEmpty(root); }
template <class T>
void AvlTree<T> :: printTree() const
	{
	  if(isEmpty())
		cout<<"Tree is empty"<<endl;
	  else
		printTree(root);
	}
template <class T>
bool AvlTree<T> :: isEmpty() const { return (root==NULL); }
template <class T>
bool AvlTree<T> :: Contains(string ele)
	{
	   if(isEmpty())
		cout<<"The tree is empty"<<endl;
	   return Contains(root,ele);
	}
template <class T>
void AvlTree<T> :: del(T &x) { del(x,root);  }
template <class T>
void AvlTree<T> :: Display(){Display(root,0);}
template <class T>
void AvlTree<T> :: makeEmpty(AvlNode *&t)
{
  if(t!=NULL)
	{
	   makeEmpty(t->l);
	   makeEmpty(t->r);
	   delete t;
	}
  t=NULL;
}

template <class T>
void AvlTree<T> :: printTree(AvlNode *t) const
{
  if(t!=NULL)
	{
	  cout<<t->e<<endl;
	  printTree(t->l);
	  printTree(t->r);
	}
}
template <class T>
bool AvlTree<T> :: Contains(AvlNode* &t,string ele)
{
	if(t==NULL)
	  return false;
	else if(ele<t->e)
	   return Contains(t->l,ele);
	else if(ele>t->e)
	  return Contains(t->r,ele);
	else
	  return true;
}

template <class T>
int AvlTree<T> :: Height(AvlNode* t) const
{
	return (t==NULL?-1:t->h);
}
template <class T>
void AvlTree<T> :: Insert (T&x,AvlNode* &t)
{
  if(t==NULL)
	t=new AvlNode(x,NULL,NULL);
  else if(x<t->e)
	Insert(x,t->l);
  else if(x>t->e)
	Insert(x,t->r);
  balance(t);
}
template <class T>
void AvlTree<T> :: balance(AvlNode *&t)
{
  if(t==NULL)
	return;
  if(Height(t->l)-Height(t->r)>1)
	if(Height(t->l->l)>=Height(t->l->r))
	     singlerotatewithleft(t);
	else
	     doublerotatewithleft(t);
  t->h=max(Height(t->l),Height(t->r))+1;
}
template <class T>
const T& AvlTree<T> :: findMin(AvlNode* t)
{
 if(t==NULL)
	return NULL;
 if(t->l==NULL)
	return t->e;
	return findMin(t->l);
}
template <class T>
void AvlTree<T> :: singlerotatewithleft(AvlNode* &k2)
{
	AvlNode *k1;
	k1=k2->l;
	k2->l=k1->r;
	k1->r=k2;
	k1->h=max(Height(k2->l),Height(k2->r))+1;
	k2->h=max(Height(k1->l),Height(k1->r))+1;
	k2=k1;
}
template <class T>
void AvlTree<T> :: doublerotatewithleft(AvlNode* &k2)
{
	singlerotatewithright(k2->l);
	singlerotatewithleft(k2);
}
template <class T>
void AvlTree<T> :: singlerotatewithright(AvlNode* &l2)
{
	AvlNode *l1;
	l1=l2->r;
	l2->r=l1->l;
	l1->l=l2;
	l2->h=max(Height(l2->l),Height(l2->r))+1;
	l2->h=max(Height(l1->l),Height(l1->r))+1;
	l2=l1;
}
template <class T>
void AvlTree<T> :: doublerotatewithright(AvlNode* &l2)
{
	singlerotatewithleft(l2->r);
	singlerotatewithleft(l2);
}
template <class T>
void AvlTree<T> :: del (T &x,AvlNode* &t)
{
	if(t==NULL)
	  return;
	else if(x<t->e)
	  del(x,t->l);
	else if(x>t->e)
	  del(x,t->r);
	else if(t->l!=NULL && t->r!=NULL)
 	{
	   t->e=findMin(t->r);
	   del(t->e,t->r);
	}
	else
	{
	 AvlNode *oldnode=t;
	 t=(t->l!=NULL)?t->l:t->r;
	 delete oldnode;
	}
    balance(t);
}
template <class T>
void AvlTree<T> :: Display(AvlNode* root, int space)
{
    if(root==NULL)
    	return;
    space+=count;
    Display(root->r,space);
    cout<<endl;
    for(int i=count;i<space;i++)
    	cout<<" ";
    cout<<root->e<<"\n";
    Display(root->l,space);
}

int main()
{
	AvlTree <string>A;
	int ch,t;
	string item,st;
while (1)
	{
		cout<<"\n-------------------------------------------------------------------------------------"<<endl;
        cout<<"                                BOOK STORE"<<endl;
        cout<<"\n--------------------------------------------------------------------------------------"<<endl;
        cout<<"1.BOOK IN STOCK"<<endl;
        cout<<"2.DATABASE"<<endl;
        cout<<"3.LIST OF BOOKS AVAILABLE"<<endl;
        cout<<"4.BOOKS OUT OF STOCK"<<endl;
        cout<<"5.CUSTOMER SEARCH"<<endl;
         cout<<"ENTER YOUR CHOICE: ";
        cin>>ch;

        switch(ch)
        {
				case 1:
                	cout<<"BOOK NAME(IN STOCK): ";
                	cin>>item;
                	A.Insert(item);
                break;

            case 2:
                cout<<"Balanced AVL Tree:"<<endl;
                A.Display();
                break;

            case 3:
                cout<<"LIST OF BOOKS AVAILABLE:"<<endl;
                A.printTree();
                cout<<endl;
                break;
            case 4:
               cout<<"BOOK NAME(OUT OF STOCK):";
				cin>>item;
				A.del(item);
				cout<<item<<"\t"<<"IS OUT OF STOCK";
				break;

			case 5:

				 cout<<"ENTER THE WANTED BOOK:";
                cin>>item;
                 if(A.Contains(item))
                 	cout<<item<<" IS IN STOCK!!"<<endl;
                 else
                 	cout<<"SORRY "<<item<<" IS NOT IN STOCK";
                break;
            default:
                cout<<"ENTER THE VALID CHOICE";
                exit(1);
                }
     }
	return 0;
}


