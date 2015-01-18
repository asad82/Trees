# include <iostream.h>
# include <conio.h>
# include <ctype.h>
# include <string.h>
#define SIZE 20

/*               READ ME               */
// Insert the Numbers In to the tree and to get a view whether
// the link is RED or Black Use option 2 Which is the Pre order
// traversal. The Program Can be tested using the example
// of 1,2,3.... insertion. The Option 2 Of the program tells
// the pointer color of both left and right sub-trees. The Pointer
// color of the leaf nodes is colorless. Mean there is no further
// right or left sub tree in that direction.

int increase=0;

struct node
{
int data;
node *left,*right;
char *rit,*lef;
};
node *newnode;
node *address[SIZE];
/////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////

void insertleft(int info,node *leftf)
{
if(leftf->data>info)
   {	if(leftf->left==NULL)
			{       address[increase-1]->lef="RED";
				newnode=new node;
					//newnode->lef="RED";
					newnode->data=info;
					newnode->left=NULL;
					newnode->right=NULL;
					newnode->lef="Color Less";
					newnode->rit="Color Less";

					leftf->left=newnode;
		 }
		else
	    {    address[increase++]=leftf->left;
	    insertleft(info,leftf->left); }
   }
else if(leftf->data<info)
	{ 	if(leftf->right==NULL)
			{   address[increase-1]->rit="RED";
	       newnode=new node;
	       //newnode->rit="RED";
					newnode->data=info;
					newnode->left=NULL;
					newnode->right=NULL;
					newnode->lef="Color Less";
					newnode->rit="Color Less";

					leftf->right=newnode;
	     }
      else
	     {  address[increase++]=leftf->right;
	     insertleft(info,leftf->right); }
    }

}

/////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////

void insertright(int info,node *leftr)
{
if(leftr->data>info)
   {	if(leftr->left==NULL)
			{   address[increase-1]->lef="RED";
				newnode=new node;
			 //		newnode->lef="RED";
					newnode->data=info;
					newnode->left=NULL;
					newnode->right=NULL;
					newnode->lef="Color Less";
					newnode->rit="Color Less";

					leftr->left=newnode;
		 }
		else
	    { address[increase++]=leftr->left;
	    insertright(info,leftr->left); }
   }
else if(leftr->data<info)
	{ 	if(leftr->right==NULL)
			{       address[increase-1]->rit="RED";
					newnode=new node;
			       //		newnode->rit="RED";
					newnode->data=info;
					newnode->left=NULL;
					newnode->right=NULL;
					newnode->lef="Color Less";
					newnode->rit="Color Less";

					leftr->right=newnode;
	     }
      else
	     { address[increase++]=leftr->right;
	     insertright(info,leftr->right); }
    }

}

/////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////

 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
void preorder(node *root)
{
node* troot=root;
if(troot!=NULL)
	{
	cout<<root->data<<"\t";
	int j=strcmp(root->lef,"RED");
	int h=strcmp(root->rit,"RED");
	int l=strcmp(root->lef,"BLACK");
	int m=strcmp(root->rit,"BLACK");

	if(j==0)
	{ textcolor(4);}
	if(l==0)
	{ textcolor(2);}
	cputs(root->lef);
	textcolor(15);
	if(h==0)
	{ textcolor(4);}
	if(m==0)
	{ textcolor(2);}

	cout<<"\t";cputs(root->rit);cout<<"\n";
	textcolor(15);
	preorder(root->left);
	preorder(root->right);
	j=1;h=1;
	}
}

/////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
void inorder(node *root)
{
node* troot=root;
if(troot!=NULL)
	{
	inorder(root->left);
   cout<<root->data<<"\n";
	inorder(root->right);
   }
}

/////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////

void postorder(node *root)
{
node* troot=root;
if(troot!=NULL)
	{
	postorder(root->left);
	postorder(root->right);
   cout<<root->data<<"\n";

	}
}
/////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////

void main()
{ clrscr();
   node *root,*newnode, *troot,*current,*change;
  int count=0;
  int info=0;
  int choice;
do
{ clrscr();
//highvideo();
textcolor(15);
textcolor(2);
textbackground(4);
cout<<"\n\t\t";
cputs("*------ RED-BLACK TREES ------*\n");
textcolor(15);
textbackground(0);
cout<<"\n Press 1 To Enter Data In The Tree."
    <<"\n Press 2 For Pre-Order Traversal."
    <<"\n Press 3 For In-Order Traversal."
    <<"\n Press 4 For Post-Order Traversal."
    <<"\n Press 5 To See Path Of Latest Insertion."
    <<"\n Any Other Number To Exit.";
cout<<"\n Enter Your Choice=";
cin>>choice;

if(choice==1)
{   clrscr();
increase=0;
if(count==0)
{root=new node;
cout<<"\n Enter Data For Root Node=";
cin>>root->data ;
root->left=NULL;
root->right=NULL;
root->lef="Color Less";
root->rit="Color Less";
troot=root;
address[increase++]=troot;
}

else {
//troot=root;
address[increase++]=troot;
	cout<<"\n Enter Data For R-B Tree=";
	cin>>info;
if(root->data>info)
{ insertleft(info,troot); }

if(root->data<info)
{ insertright(info,troot); }
}
count++;
int done=0;
int global=0;
///////////////////////////////////////////////////
for(int k=0;k<increase;k++)
{  cout<<"\n For Loop Executed.";
current=address[k];
int r=strcmp(current->lef,"RED") ;
int p=strcmp(current->rit,"RED") ;
int dfc=1;
int drc=1;
if(k+1<increase && info<troot->data)
   dfc=strcmp(address[k+1]->rit,"RED");
if(k+1<increase && info>troot->data)
   drc=strcmp(address[k+1]->lef,"RED");
   /////////////////////////////////////////////////////start of new

if(r==0 && dfc==0 && global<=1)
{             global++;
change=address[k+1]->right;
address[k]->left=change->right;
address[k]->lef=change->rit;
address[k+1]->right=change->left;
address[k+1]->rit=change->lef;
change->right=address[k];
change->rit="RED";
change->left=address[k+1];
change->lef="RED";
if(k>0)
 address[k-1]->left=change;

	if(address[k]->data==troot->data)
	{
   troot=change;
	  cout<<"\n Root Changed.";     }

cout<<"\n Double Rotation On Left Side.";
}
///////////////////////////////************************
/*********************/
if(p==0 && drc==0 && global<=1)
{             global++;
change=address[k+1]->left;
address[k]->right=change->left;
address[k]->rit=change->lef;
address[k+1]->left=change->right;
address[k+1]->lef=change->rit;
change->right=address[k+1];
change->rit="RED";
change->left=address[k];
change->lef="RED";
if(k>0)
 address[k-1]->right=change;

	if(address[k]->data==troot->data)
	{
   troot=change;
	  cout<<"\n Root Changed.";     }

cout<<"\n Double Rotation On Right Side.";
}

/*********************************/
/////////////////////////////////////////////////////end of new

if(r==0 && p==0 && global<=1)
{   global++;   current->lef="BLACK";
                current->rit="BLACK";
     cout<<"\n Color Of Pointers On Left And Right Side Changed.";
	if(k>0)
	{   change=address[k-2];
	    cout<<"\n Change="<<change->data;
	    int b=strcmp(change->rit,"RED");
	    int e=strcmp(change->rit,"BLACK");
	    int t=strcmp(change->lef,"RED");
	    int s=strcmp(change->lef,"BLACK");

	    if(address[k]->data>address[k-1]->data)
	    { if(b==0)//change->rit=="RED")
	       { change->rit="BLACK";}
	      else if(e==0)//change->rit=="BLACK")
	      { change->rit="RED";}
	     done++;
	     }
	    //////////////////
	     if(address[k]->data<address[k-1]->data)
	    { if(t==0)//change->lef=="RED")
	       { change->lef="BLACK";}
	      else if(s==0)//change->lef=="BLACK")
	      { change->lef="RED";}
	     done++;
	     }
	    //////////////////
	 }

}

/////////////////////////////////////////////
if(k+1<increase && global<=1)
{   r=strcmp(current->lef,"RED") ;   ////test
if(r==0 && address[k+1]->data<current->data)
{        cout<<"\n On Left Side Of The Tree.";
   //int q=1;
   //if(k+1<increase)
	 int q=strcmp(address[k+1]->lef,"RED");
	if(q==0)
    {        global++;
	if(current->data!=troot->data)
	{
	current->left=address[k+1]->right;
	current->lef=address[k+1]->rit;
	address[k-1]->left=address[k+1];
	address[k+1]->right=current;
	address[k+1]->rit="RED";         done++;
	}
	else if(current->data==troot->data)
	{
	current->left=address[k+1]->right;
	current->lef=address[k+1]->rit;
	address[k+1]->right=current;
	address[k+1]->rit="RED";   done++;
	}
       //	cout<<"\n In Here 1.";
	if(current->data==troot->data)
	{ troot=address[k+1];
	  cout<<"\n Root Changed.";     }
      }

}

}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
if(k+1<increase && global<=1)
{   p=strcmp(current->rit,"RED") ;
 if(p==0 && address[k+1]->data>current->data)
{       cout<<"\n On Right Side Of The Tree.";
	int q=strcmp(address[k+1]->rit,"RED");
	if(q==0)
    {          global++;
	if(current->data!=troot->data)
	{
	current->right=address[k+1]->left;
	current->rit=address[k+1]->lef;
	address[k-1]->right=address[k+1];
	address[k+1]->left=current;
	address[k+1]->lef="RED";         done++;
	}
	else if(current->data==troot->data)
	{
	current->right=address[k+1]->left;
	current->rit=address[k+1]->lef;
	address[k+1]->left=current;
	address[k+1]->lef="RED";   done++;
	}
	cout<<"\n In Here 1.";
	if(current->data==troot->data)
	{ troot=address[k+1];
	  cout<<"\n Root Changed.";     }
      }

}

}

			  }  // for loop bracket
//////////////////////////////////////
getch();
}

else if(choice==2)
{  clrscr();
cout<<"\n Preorder Traversal Is.\n";
cout<<"\n Data \t Left\t\t Right\n";
cout<<"------------------------------------\n";
preorder(troot);
getch();
}

else if(choice==3)
{ clrscr();
cout<<"\n Inorder Traversal Is.\n";
inorder(troot);
getch();  }

else if(choice==4)
{ clrscr();
cout<<"\n Postorder Traversal Is.\n";
postorder(troot);
getch(); }

else if(choice==5)
{  clrscr();
cout<<"\n No.-- "<<"--Data Element--"<<"--Left Color--"<<"--Right Color--";
for(int k=0;k<increase;k++)
{ cout<<"\n"<<k<<".\t "<<address[k]->data<<" <-----> \t"<<address[k]->lef<<"\t <-----> "<<address[k]->rit;
}
getch();
}

//////////////////////
}
while(choice!=0);
      }
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////