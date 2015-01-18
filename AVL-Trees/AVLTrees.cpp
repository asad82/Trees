# include <iostream.h>
# include <conio.h>
# include <ctype.h>
int count=0;
struct node
{
int data;
node *left,*right;
};
node *newnode;

node *address[100];
int global=0;

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int findheight(node *ld)
{
if(ld==NULL)
{ return -1;}

int i=findheight(ld->left);
int j=findheight(ld->right);

if(i>j)
{//cout<<"\n Data="<<ld->data<< "------Height="<<(i+1);
return 1+i; }

else
{//cout<<"\n Data="<<ld->data<< "------Height="<<(j+1);
return 1+j;  }


}
///////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////

void insertleft(int info,node *leftf)
{
if(leftf->data>info)
   {	if(leftf->left==NULL)
   			{  address[global]=leftf;
              global++;
     				newnode=new node;
	  				newnode->data=info;
	  				newnode->left=NULL;
	  				newnode->right=NULL;
	  				leftf->left=newnode;

	         }
  		else
            {  address[global]=leftf;
              global++;
            insertleft(info,leftf->left); }
   }
else if(leftf->data<=info)
	{ 	if(leftf->right==NULL)
   			{   address[global]=leftf;
              global++;
               newnode=new node;
	  				newnode->data=info;
	  				newnode->left=NULL;
	  				newnode->right=NULL;
	  				leftf->right=newnode;
             }
      else
             {  address[global]=leftf;
                 global++;
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
   			{  address[global]=leftr;
              global++;
     				newnode=new node;
	  				newnode->data=info;
	  				newnode->left=NULL;
	  				newnode->right=NULL;
	  				leftr->left=newnode;
	         }
  		else
            { address[global]=leftr;
              global++;
            insertright(info,leftr->left); }
   }
else if(leftr->data<=info)
	{ 	if(leftr->right==NULL)
   			{
               address[global]=leftr;
              global++;
               newnode=new node;
	  				newnode->data=info;
	  				newnode->left=NULL;
	  				newnode->right=NULL;
	  				leftr->right=newnode;
             }
      else
             {  address[global]=leftr;
              global++;
             insertright(info,leftr->right); }
    }

}

/////////////////////////////////////////////////////////////////////

 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////

void display(node *root)
{
  node *current=root;
while(current->right!=NULL)
	{ cout<<"\n Data Is="<<current->data;
	current=current->right;
	}
       cout<<"\n The Data Is="<<current->data;
     current=root;
while(current->left!=NULL)
	{ cout<<"\n Data Is="<<current->data;
	current=current->left;
	}
       cout<<"\n The Data Is="<<current->data;
}

 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
void preorder(node *root)
{
node* troot=root;
if(troot!=NULL)
	{ cout<<root->data<<"\n";

	preorder(root->left);
	preorder(root->right);

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
REINITIALIZE:
   node *root,*newnode, *troot;
  int info=0, rootcount=0,rememberroot;
  char choice;
  int choice1;

do
{ clrscr();
cout<<"\n Press 1 To Enter Numbers In the Tree."
     <<"\n Press 2 For Pre-Order Traversal."
     <<"\n Press 3 For In-Order Traversal."
     <<"\n Press 4 For Post-Order Traversal."
     <<"\n Press 5 To Re-initialize The Program.(All Data Will be Lost)"
     <<"\n Press 0 To Exit.";
cout<<"\n Enter Your Choice=";
cin>>choice1;

if(choice1==1)
{
global=0;
if(rootcount==0)
	{
	root=new node;
	cout<<"\n Enter Data For Root Node=";
	cin>>root->data ;
	root->left=NULL;
	root->right=NULL;
	troot=root;
   rememberroot=root->data;
	}
   rootcount++;
//do
//{
 global=0;
//troot=address[global];
	cout<<" Enter Data In the Tree Node=";
	cin>>info;
if(root->data>info)
	{
   insertleft(info,troot);
	}
if(root->data<info)
	{
   insertright(info,troot);
	}

// cout<<" Make Another Node In the Tree(y/n)=";
// cin>>choice;
// }
//while(tolower(choice)!='n');

}


if(choice1==2)
{  clrscr();
cout<<"\n Preorder Traversal Is.\n";
preorder(troot);  getch();     }
else if(choice1==3)
{
clrscr();
cout<<"\n Inorder Traversal Is.\n";
inorder(troot);   getch();          }

else if(choice1==4)
{ clrscr();
cout<<"\n Postorder Traversal Is.\n";
postorder(troot);   getch();    }

else if(choice1==1) //5
{ clrscr();
int k,l,p,preservek,preservel;
for( p=global-1;p>-1;p--)
{    k=findheight(address[p]->left);
     l=findheight(address[p]->right);
cout<<"\n Address Of Nodes="<<address[p]<<"---------"<<address[p]->data<<"----Height Left="<<k<<"----Height Right="<<l;
k=k+1;
l=l+1;
if(preservek==0 && preservel==1 && k==2 && l==0 && info<rememberroot)
{
//////////////////////////////////////////////////////////////
    //  if( address[p]->left!=NULL && address[p]->right!=NULL  && address[p+1]->right!=NULL  && address[p+1]->left==NULL && address[p]->data!=rememberroot)
         //{
          cout<<"\n In Normal Node Double Rotation(Left Side).";
            node *tempnode=address[p+1]->right;
             node *tempnode1=tempnode->right;
             node *tempnode2=tempnode->left;             // double rotation along
             tempnode->left=address[p+1];
             tempnode->right=address[p];            // the normal nodes on left side.
             address[p+1]->right=tempnode2;               // data-set
             address[p]->left=tempnode1;
             address[p-1]->left=tempnode;
       //  }

/////////////////////////////////////////////////////////////
 }
 if(preservek==1 && preservel==0 && k==0 && l==2 && info<rememberroot)
{    cout<<"\n In Normal Node Double Rotation(Right Side).";
            node *tempnode=address[p+1]->left;
             node *tempnode1=tempnode->right;
             node *tempnode2=tempnode->left;             // double rotation along
             tempnode->left=address[p];
             tempnode->right=address[p+1];            // the normal nodes on left side.
             address[p+1]->left=tempnode1;               // data-set
             address[p]->right=tempnode2;
             address[p-1]->left=tempnode;                                   }
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
if(preservek==0 && preservel==1 && k==2 && l==0 && info>rememberroot)
{
//////////////////////////////////////////////////////////////
    //  if( address[p]->left!=NULL && address[p]->right!=NULL  && address[p+1]->right!=NULL  && address[p+1]->left==NULL && address[p]->data!=rememberroot)
         //{
          cout<<"\n In Normal Node Double Rotation(Left Side).";
            node *tempnode=address[p+1]->right;
             node *tempnode1=tempnode->right;
             node *tempnode2=tempnode->left;             // double rotation along
             tempnode->left=address[p+1];
             tempnode->right=address[p];            // the normal nodes on left side.
             address[p+1]->right=tempnode2;               // data-set
             address[p]->left=tempnode1;
             address[p-1]->right=tempnode;
       //  }

/////////////////////////////////////////////////////////////
 }
 if(preservek==1 && preservel==0 && k==0 && l==2 && info>rememberroot)
{    cout<<"\n In Normal Node Double Rotation(Right Side).";
            node *tempnode=address[p+1]->left;
             node *tempnode1=tempnode->right;
             node *tempnode2=tempnode->left;             // double rotation along
             tempnode->left=address[p];
             tempnode->right=address[p+1];            // the normal nodes on left side.
             address[p+1]->left=tempnode1;               // data-set
             address[p]->right=tempnode2;
             address[p-1]->right=tempnode;                                   }
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

if((k-l)>1 && k>l)
{   if( address[p]->left!=NULL && address[p]->right==NULL && rememberroot==address[p]->data && address[p+1]->right==NULL)
         {   cout<<"\n In Here Root 1(Left Side Single Rotation).";

             address[p]->left=address[p+1]->right;
             address[p+1]->right=address[p];
              if(rememberroot==address[p]->data)
                  {       rememberroot=address[p+1]->data;
                           troot=address[p+1];}
         }

//////////////////////////////////////////////////////////////////////////////////
else if( address[p]->left!=NULL && address[p]->right==NULL && rememberroot==address[p]->data && address[p+1]->right!=NULL)
         {   cout<<"\n In Here Root 2(Left Side Double Rotation).";
            node *tempnode=address[p+1]->right;
             tempnode->right=address[p];             // double rotation along
             tempnode->left=address[p+1];            // the root node on left side.
             address[p+1]->right=NULL;               // data-set  50,30,40
             address[p]->left=NULL;
              if(rememberroot==address[p]->data)
                  {       rememberroot=tempnode->data;
                           troot=tempnode;}
         }


/////////////////////////////////////////////////////////////////////////////////

     else if(address[p]->left!=NULL && address[p]->right==NULL && address[p]->data!=rememberroot && address[p+1]->right==NULL && address[p-1]->data>address[p+1]->data)
          {       cout<<"\n In Normal Node(Left Side Single Rotation).";
                  address[p]->left=address[p+1]->right;
                  address[p-1]->left=address[p+1];
                  address[p+1]->right=address[p];
               }


//////////////////////////////////////////////////////////////////////////////////////////
     else if(address[p]->left!=NULL && address[p]->right!=NULL && rememberroot==address[p]->data)// && address[p+1]->right==NULL)
        {        cout<<"\n In Here Root 3(Left Side Single Rotation).";
                ///// cout<<"\n Address 1="<<address[p+1]->data;
                /////cout<<"\n Address 2="<<address[p-1]->data;
                 address[p]->left=address[p+1]->right;
                 address[p+1]->right=address[p];
                  if(rememberroot==address[p]->data)
                  {       rememberroot=address[p+1]->data;
                           troot=address[p+1];}

                 }

//////////////////////////////////////////////////////////////////////////////////////////////
     else if(address[p]->left!=NULL && address[p]->right==NULL && address[p]->data!=rememberroot && address[p+1]->right==NULL && address[p-1]->data<address[p+1]->data)
          {       cout<<"\n In Normal Node(Right-Left Side Single Rotation).";
                  address[p-1]->right=address[p]->left;
                  address[p+1]->right=address[p];
                  address[p]->left=NULL;
                  //cout<<"\n Address[p-1]="<<address[p-1]->data;
               }

///////////////////////////////////////////////////////////////////////////////////////////






                 }        //// outer bracket

///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
else if((l-k)>1 && l>k)
{   if( address[p]->left==NULL && address[p]->right!=NULL && rememberroot==address[p]->data && address[p+1]->left==NULL)
         {   cout<<"\n In Here Root 1(Right Rotation).";
             address[p]->right=address[p+1]->left;
             address[p+1]->left=address[p];

                           if(rememberroot==address[p]->data)
                  {       rememberroot=address[p+1]->data;
                           troot=address[p+1];}
         }
////////////////////////////////////////////////////////////////////////////////////
     else if(address[p]->left==NULL && address[p]->right!=NULL && address[p]->data!=rememberroot && address[p+1]->left==NULL && address[p-1]->data<address[p+1]->data)
          {       cout<<"\n In Normal Node(Right Side Single Rotation).";
                  address[p-1]->right=address[p]->right;
                  address[p+1]->left=address[p];
                  address[p]->right=NULL;
                  //cout<<"\n Address[p-1]="<<address[p-1]->data;
               }
///////////////////////////////////////////////////////////////////////////////////
     else if(address[p]->left==NULL && address[p]->right!=NULL && address[p]->data!=rememberroot && address[p+1]->left==NULL && address[p-1]->data>address[p+1]->data)
          {       cout<<"\n In Normal Node(Left-Right Side Single Rotation).";
                  address[p-1]->left=address[p]->right;
                  address[p+1]->left=address[p];
                  address[p]->right=NULL;
                  //cout<<"\n Address[p-1]="<<address[p-1]->data;
               }

////////////////////////////////////////////////////////////////////////////////////
else if( address[p]->left==NULL && address[p]->right!=NULL && rememberroot==address[p]->data && address[p+1]->left!=NULL)
         {   cout<<"\n In Here Root 2(Right Side Double Rotation).";
            node *tempnode=address[p+1]->left;
             tempnode->left=address[p];             // double rotation along
             tempnode->right=address[p+1];            // the root node on left side.
             address[p+1]->left=NULL;               // data-set  50,70,60
             address[p]->right=NULL;
              if(rememberroot==address[p]->data)
                  {       rememberroot=tempnode->data;
                           troot=tempnode;}
         }

///////////////////////////////////////////////////////////////////////////////////
     else if(address[p]->left!=NULL && address[p]->right!=NULL && rememberroot==address[p]->data)
        {        cout<<"\n In Here Root 3(Right Side Single Rotation).";
                ///// cout<<"\n Address 1="<<address[p+1]->data;
                /////cout<<"\n Address 2="<<address[p-1]->data;
                 address[p]->right=address[p+1]->left;
                 address[p+1]->left=address[p];
                  if(rememberroot==address[p]->data)
                  {       rememberroot=address[p+1]->data;
                           troot=address[p+1];}

                 }

////////////////////////////////////////////////////////////////////////////////////
     else if(address[p]->left!=NULL && address[p]->right!=NULL && rememberroot!=address[p]->data)// && address[p+1]->right==NULL)
        {        cout<<"\n In Normal Node(Hight Length)(Right Side Single Rotation).";
                ///// cout<<"\n Address 1="<<address[p+1]->data;
                /////cout<<"\n Address 2="<<address[p-1]->data;
                 address[p]->left=address[p+1]->right;
                 address[p+1]->right=address[p];
       //test           if(rememberroot==address[p]->data)
         // test        {       rememberroot=address[p+1]->data;
          // test                troot=address[p+1];}

                 }

////////////////////////////////////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
preservek=k;
preservel=l;
                 }  /// outer bracket for, for loop
getch();  }

else if(choice1==5)
{  cout<<"\n Press Any Key To Reinitialize.";
    getch();
goto REINITIALIZE ;             }


}
while(choice1!=0);

      }
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////