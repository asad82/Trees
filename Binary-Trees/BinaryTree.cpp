/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		     : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

# include <iostream.h>
# include <conio.h>
# include <ctype.h>
int count = 0, loopcount = 0, savedepth = 0, hy = 0;
struct node
{
	int data, depth, height;
	node *left, *right;
};
node *newnode, *remember, *rem, *preserve;
int countr = 0, countf = 0, minimum, cnt = 0, cnt1 = 0;
int countrr = 0, countff = 0, minimumm, cntt = 0, cnt11 = 0;
int cd = 0, cp = 0;
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int returnminimumright(node *leftr)
{
	node *rightof;
	if (cnt == 0)
	{
		preserve = leftr;
		leftr = leftr->left;
		rightof = leftr->left;
		rem = leftr;
	}
	cntt++;
	cout << "\n Preserve=" << preserve->data;
	cout << "\n rem=" << rem->data;
	while (leftr->right != NULL)
	{
		leftr = leftr->right; cnt11++;
	}
	///////////////////////////////leftf=leftf->left;/////////////////////////
	cout << "\n Number Is=" << leftr->data;

	if (cnt11 == 0)
	{
		preserve->left = rightof;
	}

	///////////////////////////////rem->right=leftf->right;////////////////////
	else if (cnt11 != 0)
	{
		rem->right = leftr->left;
	}

	return leftr->data;
}



/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void deleteright(int info, node *leftr)
{

	if (leftr->data > info)
	{
		countff++; countrr = 0;
		remember = leftr;
		deleteright(info, leftr->left);

	}
	else if (leftr->data < info)
	{
		countrr++; countff = 0;
		remember = leftr;
		deleteright(info, leftr->right);

	}

	else  if (leftr->data == info  && leftr->left == NULL && leftr->right == NULL)
	{
		if (countff > 0)
		{
			remember->left = NULL;
		}
		else if (countrr > 0)
		{
			remember->right = NULL;
		}
	}
	/////////////////////////////////////////////////////////////////////

	else  if (leftr->data == info  && leftr->left != NULL && leftr->right == NULL)
	{
		if (countff > 0)
		{
			remember->left = leftr->left; cout << "\n Node Deleted.(left!=NULL && right==NULL)";
		}

		//remeber->right
	}
	/////////////////////////////////////////////////////////////////////

	else  if (leftr->data == info  && leftr->left == NULL && leftr->right != NULL)
	{
		if (countrr > 0)
		{
			remember->right = leftr->right; cout << "\n Node Deleted.(left==NULL && right!=NULL)";
		}

		//remember->left
	}

	//////////////////////////////////////////////////////////////////////

	else  if (leftr->data == info  && leftr->left != NULL && leftr->right != NULL)
	{

		//call a function which return the minimum element from the right side.
		minimumm = returnminimumright(leftr);
		cout << "\n Maximum Number Is=" << minimumm;
		leftr->data = minimumm;
	}
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int deleterootnode(node *leftf)
{
	node *rightof, *pchila;
	if (cnt == 0)
	{
		preserve = leftf;
		leftf = leftf->right;
		rem = leftf;
		rightof = leftf->right;
	}

	cnt++;
	cout << "\n Preserve=" << preserve->data;
	cout << "\n rem=" << rem->data;
	while (leftf->left != NULL)
	{
		pchila = leftf;
		leftf = leftf->left; cnt1++;
	}
	cout << "\n Number Is=" << leftf->data;


	if (cnt1 != 0)
	{
		pchila->left = leftf->right;
	}

	else if (cnt1 == 0)
	{
		preserve->right = rightof;
	}

	return leftf->data;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


int returnminimum(node *leftf)
{
	node *rightof, *aikpichla;
	if (cnt == 0)
	{
		preserve = leftf;
		leftf = leftf->right;
		rem = leftf;
		rightof = leftf->right;
		/////////////////////////////////////rightof=rightof->right///////////////////;
	}

	cnt++;
	cout << "\n Preserve=" << preserve->data;
	cout << "\n rem=" << rem->data;
	while (leftf->left != NULL)
	{
		aikpichla = leftf;
		leftf = leftf->left; cnt1++;
	}
	///////////////////////////////leftf=leftf->left;/////////////////////////
	cout << "\n Number Is=" << leftf->data;

	// if(cnt1==0)       //////////////////leftf->left==NULL
	// { preserve->right=NULL;}

	///////////////////////////////rem->right=leftf->right;////////////////////
	if (cnt1 != 0)
	{ //rem->left=leftf->right;

		aikpichla->left = leftf->right;
		//////////////// leftf->left=NULL;
		//////////////// leftf->right=NULL;
	}

	else if (cnt1 == 0)
	{ //preserve->right=rightof;//leftf->right;
		//leftf->left=NULL;
		preserve->right = rightof;
	}
	return leftf->data;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void deleteleft(int info, node *leftf)
{

	if (leftf->data > info)
	{
		countf++; countr = 0;
		remember = leftf;
		deleteleft(info, leftf->left);

	}
	else if (leftf->data < info)
	{
		countr++; countf = 0;
		remember = leftf;
		deleteleft(info, leftf->right);

	}

	else  if (leftf->data == info  && leftf->left == NULL && leftf->right == NULL)
	{
		if (countf > 0)
		{
			remember->left = NULL;
		}
		else if (countr > 0)
		{
			remember->right = NULL;
		}
	}
	/////////////////////////////////////////////////////////////////////

	else  if (leftf->data == info  && leftf->left != NULL && leftf->right == NULL)
	{
		if (countf > 0)       //countr>0
		{
			remember->left = leftf->left; cout << "\n Node Deleted.(left!=NULL && right==NULL)";
		}      //remember->left


	}
	/////////////////////////////////////////////////////////////////////

	else  if (leftf->data == info  && leftf->left == NULL && leftf->right != NULL)
	{
		if (countr > 0)          //countf>0
		{
			remember->right = leftf->right; cout << "\n Node Deleted.(left==NULL && right!=NULL)";
		}       //remember->left


	}

	//////////////////////////////////////////////////////////////////////

	else  if (leftf->data == info  && leftf->left != NULL && leftf->right != NULL)
	{

		//call a function which return the minimum element from the right side.
		minimum = returnminimum(leftf);
		cout << "\n Minimum Number Is=" << minimum;
		leftf->data = minimum;
	}
}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void deleterootnodepass(int info, node *leftf)
{
	//call a function which return the minimum element from the right side.
	minimum = deleterootnode(leftf);
	cout << "\n Minimum Number Is=" << minimum;
	leftf->data = minimum;

}

/////////////////////////////////////////////////////////////////////

void insertleft(int info, node *leftf)
{
	//if(loopcount==0)
	//{ savedepth=0;}
	if (leftf->data > info)
	{
		if (leftf->left == NULL)
		{
			savedepth++;
			newnode = new node;
			newnode->data = info;
			newnode->depth = savedepth;
			newnode->left = NULL;
			newnode->right = NULL;
			leftf->left = newnode;
		}
		else
		{
			savedepth++;
			insertleft(info, leftf->left);
		}
	}
	else if (leftf->data <= info)
	{
		if (leftf->right == NULL)
		{
			savedepth++;
			newnode = new node;
			newnode->data = info;
			newnode->depth = savedepth;
			newnode->left = NULL;
			newnode->right = NULL;
			leftf->right = newnode;
		}
		else
		{
			savedepth++;
			insertleft(info, leftf->right);
		}
	}


}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void insertright(int info, node *leftr)
{
	if (leftr->data > info)
	{
		if (leftr->left == NULL)
		{
			savedepth++;
			newnode = new node;
			newnode->data = info;
			newnode->depth = savedepth;
			newnode->left = NULL;
			newnode->right = NULL;
			leftr->left = newnode;
		}
		else
		{
			savedepth++;
			insertright(info, leftr->left);
		}
	}
	else if (leftr->data <= info)
	{
		if (leftr->right == NULL)
		{
			savedepth++;
			newnode = new node;
			newnode->data = info;
			newnode->depth = savedepth;
			newnode->left = NULL;
			newnode->right = NULL;
			leftr->right = newnode;
		}
		else
		{
			savedepth++;
			insertright(info, leftr->right);
		}
	}

}

/////////////////////////////////////////////////////////////////////
void depth(node *bisect)
{
	if (bisect != NULL)
	{
		count++;
		depth(bisect->right);
		count--;
		depth(bisect->left);
		count++;
		count--;
	}
	cout << "\n The depth Is=" << count;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void display(node *root)
{
	node *current = root;
	while (current->right != NULL)
	{
		cout << "\n Data Is=" << current->data;
		current = current->right;
	}
	cout << "\n The Data Is=" << current->data;
	current = root;
	while (current->left != NULL)
	{
		cout << "\n Data Is=" << current->data;
		current = current->left;
	}
	cout << "\n The Data Is=" << current->data;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
void preorder(node *root)
{
	node* troot = root;
	if (troot != NULL)
	{
		cout << root->data << "----Depth=";
		cout << root->depth << "\n";
		if (root->depth > hy)
		{
			hy = root->depth;
		}
		preorder(root->left);
		preorder(root->right);

	}
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
void inorder(node *root)
{
	node* troot = root;
	if (troot != NULL)
	{
		inorder(root->left);
		cout << root->data << "\n";
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
	node* troot = root;
	if (troot != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << "\n";

	}
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int findheight(node *ld)
{
	if (ld == NULL)
	{
		return -1;
	}

	int i = findheight(ld->left);
	int j = findheight(ld->right);

	if (i > j)
	{
		cout << "\n Data=" << ld->data << "------Height=" << (i + 1);
		return 1 + i;
	}

	else
	{
		cout << "\n Data=" << ld->data << "------Height=" << (j + 1);
		return 1 + j;
	}


}
///////////////////////////////

int finddepth(node *ld)
{
	if (ld->left == NULL && ld->right == NULL)
	{
		return cd;
	}

	if (ld->left != NULL)
	{
		cd++;
		int jk = finddepth(ld->left);
	}

	else if (ld->right != NULL)
	{
		cd++;
		int yu = finddepth(ld->right);
	}
	//if(cd>cp)
	//return cd;

	//else if(cd<cp)
	return cd;


}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void main()
{
	clrscr();
	node *root, *newnode, *troot;
	int info = 0;
	char choice;
	int choice1;
	root = new node;
	cout << "\n Enter Data For Root Node=";
	cin >> root->data;
	root->depth = 0;
	root->left = NULL;
	root->right = NULL;
	troot = root;
	do{
		clrscr();
		cout << "\n Press 1 To Enter Data In The Tree Node."
			<< "\n Press 2 For Pre-Order traversal."
			<< "\n Press 3 For In-Order Traversal."
			<< "\n Press 4 For Post-Order Traversal."
			<< "\n Press 5 To Find The Height."
			<< "\n Press 6 To Find The Depth."
			<< "\n Press 7 To Delete Any Element."
			<< "\n Press 0 To Exit.";
		cout << "\n Enter Your Choice=";
		cin >> choice1;

		if (choice1 == 1)
		{
			do
			{
				loopcount = 0;
				savedepth = 0;
				troot = root;
				cout << " Enter Data For Rest Of the Tree=";
				cin >> info;
				if (root->data > info)
				{       //savedepth++;
					insertleft(info, troot);
				}
				if (root->data <= info)
				{     //savedepth++;
					insertright(info, troot);
				}
				cout << " Make Another Node In the Tree(y/n)=";
				cin >> choice;
			} while (tolower(choice) != 'n');
		}

		if (choice1 == 2)
		{
			clrscr();
			cout << "\n Preorder Traversal Is.\n";
			preorder(troot); getch();
		}

		if (choice1 == 3)
		{
			clrscr();
			cout << "\n Inorder Traversal Is.\n";
			inorder(troot); getch();
		}

		if (choice1 == 4)
		{
			clrscr();
			cout << "\n Postorder Traversal Is.\n";
			postorder(troot); getch();
		}

		if (choice1 == 5)
		{
			int prt = findheight(troot);
			cout << "\n Height=" << prt;  getch();
		}

		if (choice1 == 6)
		{
			int pr = finddepth(troot);
			cout << "\n Depth=" << pr;    getch();
		}

		if (choice1 == 7)
		{

			do{
				int del;
				cout << "\n Enter Number You Want To Delete=";
				cin >> del;
				if (troot->data > del)
				{
					deleteleft(del, troot);
				}

				else if (troot->data < del)      //=
				{
					deleteright(del, troot);
				}

				else if (troot->data == del)
				{
					deleterootnodepass(del, troot);
				}

				cout << "\n Delete Another(y/n)=";
				cin >> choice;
				remember = NULL; rem = NULL; preserve = NULL;
				countr = 0; countf = 0; minimum = 0;
				cnt = 0; cnt1 = 0;
				countrr = 0; countff = 0; minimumm = 0;
				cntt = 0; cnt11 = 0;
			} while (choice != 'n');
		}

	} while (choice1 != 0);
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
