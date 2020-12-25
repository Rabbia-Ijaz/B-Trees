/*
* BTrees.h
*
*  Created on: Dec 27, 2018
*      Author: linux
*/

#ifndef BTREES_H_
#define BTREES_H_
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<sstream>
#include<direct.h>
using namespace std;

template <class T>
class Node
{
public:
	string path;
	Node<T>* next;
};
template <class T>
class LinkedList
{
public:
	Node<T>* head;
	int numItems;
	LinkedList(int ignored=0)
	{
		head=NULL;
		numItems=0;
	}
	void insert(string p)
	{
		if(head==NULL)
		{
			head=new Node<T>();
			head->path=p;
			head->next=NULL;
			numItems++;
		}
		else
		{
			Node<T>* temp=head;
			Node<T>* newNode=new Node<T>();
			newNode->path=p;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode->next=NULL;
			numItems++;
		}
	}

	bool isEmpty ()
	{
		return(head==NULL);
	}
	void display()
	{
		if(isEmpty())
		{
			cout<<endl;
			return ;
		}
		Node<T>* temp;
		temp=head;
		while(temp->next)
		{
			cout<<temp->path<<"  ";
			temp=temp->next;
		}
		cout<<temp->path<< endl;
	}
	void Printpath()
	{
		if(isEmpty())
		{
			return ;
		}
		Node<T>* temp;
		temp=head;
		while(temp)
		{
			PrintFileData(temp->path);
			temp=temp->next;
		}
	}

	void PrintFileData(string path)
	{
		string data;
		ifstream ofile;
		ofile.open((path).c_str());
		cout<< "____________________________"<<endl;
		getline(ofile,data);
		cout<<"ID: "<<data<<endl;

		getline(ofile,data);
		cout<<"Year: "<<data<<endl;

		getline(ofile,data);
		cout<<"113 Cause Name: "<<data<<endl;

		getline(ofile,data);
		cout<<"Cause Name: "<<data<<endl;

		getline(ofile,data);
		cout<<"State: "<<data<<endl;

		getline(ofile,data);
		cout<<"Deaths: "<<data<<endl;

		getline(ofile,data);
		cout<<"Adjusted Death Rate "<<data<<endl;

		cout<< "____________________________"<<endl<<endl;

	}

	void deleteNode(string p)
	{

		Node<T>* curr=head;
		Node<T>* prev=NULL;
		int currIndex=1;
		while(curr && curr->path!=p)
		{
			prev=curr;
			curr=curr->next;
			currIndex++;
		}
		if(curr)
		{
			if(prev)
			{
				prev->next=curr->next;
				delete curr;
				numItems--;
			}
			else
			{
				head=curr->next;
				delete curr;
				numItems--;
			}
		}
	}

	void FindAndDelete(string field, string fieldtype)
	{
		int count=0;
        bool found=true;
		while(found)
		{
			if(isEmpty())
			{
				return ;
			}
			found=false;
			Node<T>* temp=head;
			while(temp->next)
			{
				string data;
				ifstream ofile;
				ofile.open((temp->path).c_str());
				if(fieldtype=="ID")
				{
					getline(ofile,data);
					if(data==field)
					{
						cout<<"ID: "<<data<<endl;
						found=true;
						deleteNode(temp->path);
						count++;
						temp=NULL;
						break;
					}
				}

				else if(fieldtype=="Year")
				{
					getline(ofile,data);
					getline(ofile,data);
					if(data==field)
					{
						cout<<"Deleted tuple "<<temp->path <<" where Year is equal to " <<data<<endl;
						found=true;
						deleteNode(temp->path);
						count++;
						temp=NULL;
						break;
					}
				}

				else if(fieldtype=="113 Cause Name")
				{
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					if(data==field)
					{
						cout<<"Deleted tuple "<<temp->path<< " where 113 Cause Name is equal to " <<data<<endl;
						found=true;
						deleteNode(temp->path);
						count++;
						temp=NULL;
						break;
					}
				}

				else if(fieldtype=="Cause Name")
				{
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					if(data==field)
					{
						cout<<"Deleted tuple "<<temp->path <<" where Cause Name is equal to " <<data<<endl;
						found=true;
						deleteNode(temp->path);
						count++;
						temp=NULL;
						break;
					}
				}

				else if(fieldtype=="State")
				{
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					if(data==field)
					{
						cout<<"Deleted tuple "<<temp->path <<" where State is equal to " <<data<<endl;
						found=true;
						deleteNode(temp->path);
						count++;
						temp=NULL;
						break;
					}
				}

				else if(fieldtype=="Deaths")
				{
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					if(data==field)
					{
						cout<<"Deleted tuple "<<temp->path <<" where Deaths are equal to " <<data<<endl;
						found=true;
						deleteNode(temp->path);
						count++;
						temp=NULL;
						break;
					}
				}
				else if(fieldtype=="Age-adjusted Death Rate")
				{
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					getline(ofile,data);
					if(data==field)
					{
						cout<<"Deleted tuple "<<temp->path <<" where Age-adjusted Death Rate is equal to " <<data<<endl;
						found=true;
						deleteNode(temp->path);
						count++;
						temp=NULL;
						break;
					}
				}
				temp=temp->next;

			}
		}
		if(count ==0)
		{
			cout<<"*"<<field<< "* of *"<<fieldtype<<"* is Not Found"<<endl;
		}
	}

	void UpdateTuple(string fieldtype, string oldval, string newval)
	{
		int count=0;
		bool found=true;
		if(isEmpty())
		{
			return ;
		}
		found=false;
		Node<T>* temp=head;
		while(temp->next)
		{
			string file[6]={""};
			string data;
			ifstream ofile;
			ofile.open((temp->path).c_str());


			if(fieldtype=="ID")
			{

				getline(ofile,data);
				if(data==oldval)
				{
					cout<<"file name is: "<<temp->path<<endl;
					cout<<"field type is *ID* ";
					cout<<"old value is *"<<oldval<<"* and new value is *"<< newval<<"*"<<endl;
					getline(ofile,file[0]);
					getline(ofile,file[1]);
					getline(ofile,file[2]);
					getline(ofile,file[3]);
					getline(ofile,file[4]);
					getline(ofile,file[5]);

					ofile.close();
					ofstream odfile;
					odfile.open((temp->path).c_str());
					odfile<<newval<<endl;
					odfile<<file[0]<<endl;
					odfile<<file[1]<<endl;
					odfile<<file[2]<<endl;
					odfile<<file[3]<<endl;
					odfile<<file[4]<<endl;
					odfile<<file[5]<<endl;
					count++;
					temp=NULL;
					odfile.close();
					break;
				}
			}
			else if(fieldtype=="Year")
			{
				getline(ofile,file[0]);
				getline(ofile,data);
				if(data==oldval)
				{
					cout<<"file name is: "<<temp->path<<endl;
					cout<<"field type is *Year* ";
					cout<<"old value is *"<<oldval<<"* and new value is *"<< newval<<"*"<<endl;								getline(ofile,file[1]);
					getline(ofile,file[2]);
					getline(ofile,file[3]);
					getline(ofile,file[4]);
					getline(ofile,file[5]);

					ofile.close();
					ofstream odfile;
					odfile.open((temp->path).c_str());
					odfile<<file[0]<<endl;
					odfile<<newval<<endl;
					odfile<<file[1]<<endl;
					odfile<<file[2]<<endl;
					odfile<<file[3]<<endl;
					odfile<<file[4]<<endl;
					odfile<<file[5]<<endl;
					count++;
					temp=NULL;
					odfile.close();
					break;

				}
			}

			else if(fieldtype=="113 Cause Name")
			{
				getline(ofile,file[0]);
				getline(ofile,file[1]);
				getline(ofile,data);
				if(data==oldval)
				{
					cout<<"file name is: "<<temp->path<<endl;
					cout<<"field type is *113 Cause Name* ";
					cout<<"old value is *"<<oldval<<"* and new value is *"<< newval<<"*"<<endl;								getline(ofile,file[2]);
					getline(ofile,file[3]);
					getline(ofile,file[4]);
					getline(ofile,file[5]);

					ofile.close();
					ofstream odfile;
					odfile.open((temp->path).c_str());
					odfile<<file[0]<<endl;
					odfile<<file[1]<<endl;
					odfile<<newval<<endl;
					odfile<<file[2]<<endl;
					odfile<<file[3]<<endl;
					odfile<<file[4]<<endl;
					odfile<<file[5]<<endl;
					count++;
					temp=NULL;
					odfile.close();
					break;

				}
			}

			else if(fieldtype=="Cause Name")
			{
				getline(ofile,file[0]);
				getline(ofile,file[1]);
				getline(ofile,file[2]);
				getline(ofile,data);
				if(data==oldval)
				{
					cout<<"file name is: "<<temp->path<<endl;
					cout<<"field type is *Cause Name* ";
					cout<<"old value is *"<<oldval<<"* and new value is *"<< newval<<"*"<<endl;								getline(ofile,file[3]);
					getline(ofile,file[4]);
					getline(ofile,file[5]);

					ofile.close();
					ofstream odfile;
					odfile.open((temp->path).c_str());
					odfile<<file[0]<<endl;
					odfile<<file[1]<<endl;
					odfile<<file[2]<<endl;
					odfile<<newval<<endl;
					odfile<<file[3]<<endl;
					odfile<<file[4]<<endl;
					odfile<<file[5]<<endl;
					count++;
					temp=NULL;
					odfile.close();
					break;
				}
			}

			else if(fieldtype=="State")
			{
				getline(ofile,file[0]);
				getline(ofile,file[1]);
				getline(ofile,file[2]);
				getline(ofile,file[3]);
				getline(ofile,data);
				if(data==oldval)
				{
					cout<<"file name is: "<<temp->path<<endl;
					cout<<"field type is *State* ";
					cout<<"old value is *"<<oldval<<"* and new value is *"<< newval<<"*"<<endl;								getline(ofile,file[4]);
					getline(ofile,file[5]);

					ofile.close();
					ofstream odfile;
					odfile.open((temp->path).c_str());
					odfile<<file[0]<<endl;
					odfile<<file[1]<<endl;
					odfile<<file[2]<<endl;
					odfile<<file[3]<<endl;
					odfile<<newval<<endl;
					odfile<<file[4]<<endl;
					odfile<<file[5]<<endl;
					count++;
					temp=NULL;
					odfile.close();
					break;
				}
			}

			else if(fieldtype=="Deaths")
			{
				getline(ofile,file[0]);
				getline(ofile,file[1]);
				getline(ofile,file[2]);
				getline(ofile,file[3]);
				getline(ofile,file[4]);
				getline(ofile,data);
				if(data==oldval)
				{
					cout<<"file name is: "<<temp->path<<endl;
					cout<<"field type is *Deaths* ";
					cout<<"old value is *"<<oldval<<"* and new value is *"<< newval<<"*"<<endl;								getline(ofile,file[5]);

					ofile.close();
					ofstream odfile;
					odfile.open((temp->path).c_str());
					odfile<<file[0]<<endl;
					odfile<<file[1]<<endl;
					odfile<<file[2]<<endl;
					odfile<<file[3]<<endl;
					odfile<<file[4]<<endl;
					odfile<<newval<<endl;
					odfile<<file[5]<<endl;
					count++;
					temp=NULL;
					odfile.close();
					break;
				}
			}
			else if(fieldtype=="Death Rate")
			{
				getline(ofile,file[0]);
				getline(ofile,file[1]);
				getline(ofile,file[2]);
				getline(ofile,file[3]);
				getline(ofile,file[4]);
				getline(ofile,file[5]);
				getline(ofile,data);
				if(data==oldval)
				{
					cout<<"file name is: "<<temp->path<<endl;
					cout<<"field type is *Death Rate* ";
					cout<<"old value is *"<<oldval<<"* and new value is *"<< newval<<"*"<<endl;								ofile.close();
					ofstream odfile;
					odfile.open((temp->path).c_str());
					odfile<<file[0]<<endl;
					odfile<<file[1]<<endl;
					odfile<<file[2]<<endl;
					odfile<<file[3]<<endl;
					odfile<<file[4]<<endl;
					odfile<<file[5]<<endl;
					odfile<<newval<<endl;
					count++;
					temp=NULL;
					odfile.close();
					break;
				}
			}
			temp=temp->next;

		}
		if(count==0)
		{
			cout<<"Old value *"<<oldval<< "* in *"<<fieldtype<<"* Field is Not Found"<<endl;
		}

	}


	void destroy()
	{
		Node<T>* curr=head;
		Node<T> *nextNode=NULL;
		while(curr!=NULL)
		{
			nextNode=curr->next;
			delete curr;
			curr=nextNode;
		}
	}
	~LinkedList()
	{
		destroy();
	}
};


template<class T>
class TempNode
{
public:
	string path;
	T key;
	TempNode<T>* next;
};

template <class T>
class TempLinkedList
{
public:
	TempNode<T>* head;
	int numItems;
	TempLinkedList<T>(int ignored=0)
	{
		head=NULL;
		numItems=0;
	}
	void insert(string p, T k)
	{
		if(head==NULL)
		{
			head=new TempNode<T>();
			head->path=p;
			head->next=NULL;
			head->key=k;
		}
		else
		{
			TempNode<T>* temp=head;
			TempNode<T>* newNode=new TempNode<T>();
			newNode->path=p;
			newNode->key=k;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode->next=NULL;
			numItems++;
		}
	}

	bool isEmpty ()
	{
		return(head==NULL);
	}
	void display()
	{
		if(isEmpty())
		{
			return ;
		}
		TempNode<T>* temp;
		temp=head;
		while(temp)
		{
			cout<<"key "<< temp->key<<" "<<temp->path<<endl;
			temp=temp->next;
		}
	}

	void deleteNode(string p)
	{

		TempNode<T>* curr=head;
		TempNode<T>* prev=NULL;
		int currIndex=1;
		while(curr && curr->path!=p)
		{
			prev=curr;
			curr=curr->next;
			currIndex++;
		}
		if(curr)
		{
			if(prev)
			{
				prev->next=curr->next;
				delete curr;
			}
			else
			{
				head=curr->next;
				delete curr;
			}
		}
	}
	void destroy()
	{
		TempNode<T>* curr=head;
		TempNode<T> *nextNode=NULL;
		while(curr!=NULL)
		{
			nextNode=curr->next;
			delete curr;
			curr=nextNode;
		}
	}
	~TempLinkedList()
	{
		destroy();
	}
};




template<class T>
class LIST{
public:
	T key;
	LinkedList<string> P;
};


template<class T>
class BTreeNode {
public:
	int recCount;					//total number of records/keys
	LIST<T> *list;						//keys
	BTreeNode<T> **children;			//children
	int currRec;					//current number of records/keys
	bool leaf;						//leaf or not
	int Deg;
	BTreeNode(int order = 0, bool l = true) {
		recCount = order - 1;
		currRec = 0;
		Deg = order;
		children = new BTreeNode<T>*[2 * Deg];
		leaf = l;
		list = new LIST<T>[2 * Deg - 1];
	}
	void splitNode(int index, BTreeNode<T>* NodeSplit) {
		BTreeNode<T>* temp = new BTreeNode(NodeSplit->Deg, NodeSplit->leaf);
		temp->currRec = Deg - 1;
		for (int i = 0; i < Deg - 1; ++i) {
			temp->list[i].key = NodeSplit->list[i + Deg].key;
			//temp->list[i].P = NodeSplit->list[i + Deg].P;
		}
		if (NodeSplit->leaf == false) {
			for (int i = 0; i < Deg; ++i) {
				temp->children[i] = NodeSplit->children[i + Deg];
			}
		}
		NodeSplit->currRec = Deg - 1;
		for (int i = currRec; i >= index + 1; i--) {
			children[i + 1] = children[i];
		}
		children[index + 1] = temp;
		for (int i = currRec - 1; i >= index; i--) {
			list[i + 1] .key= list[i].key;
			//list[i + 1] .P= list[i].P;
		}
		list[index].key = NodeSplit->list[Deg - 1].key;
		//list[index].P = NodeSplit->list[Deg - 1].P;
		currRec = currRec + 1;
	}
	void insertIfNotFull(T key) {
		int i = currRec - 1;
		if (leaf == true) {
			while (i >= 0 && list[i] .key> key) {
				list[i + 1].key = list[i].key;
				//list[i + 1].P= list[i].P;
				i--;
			}
			list[i + 1].key = key;
			list[i+1].P=NULL;
			////list[i+1].P.insert(p);
			currRec = currRec + 1;
		} else {
			while (i >= 0 && list[i].key > key) {
				i--;
			}
			if (children[i + 1]->currRec == 2 * Deg -1 ) {
				splitNode(i + 1, children[i + 1]);
				if (list[i + 1] .key < key) {
					i++;
				}
			}
			children[i+1]->insertIfNotFull(key);
		}
	}
	bool searchBtree(T item) {
		int i = 0;
		while (i < currRec && item > list[i].key) {
			i++;
		}
		if (list[i].key == item) {
			return true;
		}
		if (leaf == true) {
			return false;
		}
		bool b = children[i]->searchBtree(item);
		return b;
	}
	void traverse() {
		int i;
		for (i = 0; i < currRec; ++i) {
			if (leaf == false) {
				children[i]->traverse();
			}
			cout <<"Key: "<< list[i].key<< endl;
			cout<<"Files: ";
			list[i].P.display();
			cout<<endl;
		}
		if (leaf == false) {
			children[i]->traverse();
		}
	}

	void InsertIfFound(T k, string p) {
		int i;
		for (i = 0; i < currRec; ++i) {
			if (leaf == false) {
				children[i]->InsertIfFound(k,p);
			}
			if(list[i].key==k)
			{
				list[i].P.insert(p);
				return;
			}
		}
		if (leaf == false) {
			children[i]->InsertIfFound(k,p);
		}
	}

	void SearchKey(T k)
	{
		int i;
		for (i = 0; i < currRec; ++i) {
			if (leaf == false) {
				children[i]->SearchKey(k);
			}
			if(list[i].key==k)
			{
				cout<<"        ****Key: "<<k<<"****"<<endl;
				list[i].P.Printpath();
				return;
			}
		}
		if (leaf == false) {
			children[i]->SearchKey(k);
		}
	}

	void SearchRangeKeys(bool &found,T s, T d)
	{
		int i;
		for (i = 0; i < currRec; ++i) {
			if (leaf == false) {
				children[i]->SearchRangeKeys(found,s,d);
			}
			if(list[i].key>=s && list[i].key<=d)
			{
				found=true;
				if(found)
				{
					cout<<"        ****Key: "<<list[i].key<<"****"<<endl;
				    list[i].P.Printpath();
				}

			}
			else{
				found=false;
			}
		}
		if (leaf == false) {
			children[i]->SearchRangeKeys(found,s,d);
		}

	}

	void SearchKeyWhereField(T k, string field,string fieldtype)
	{
		int i;
		for (i = 0; i < currRec; ++i) {
			if (leaf == false) {
				children[i]->SearchKeyWhereField(k,field,fieldtype);
			}
			if(list[i].key==k)
			{
				cout<<"        ****Key: "<<k<<"****"<<endl;
				list[i].P.FindAndDelete(field,fieldtype);
				//return;
			}
			/*else
			{
				cout<<"        ****Key: "<<k<<" Not Found****"<<endl;
			}*/
		}
		if (leaf == false) {
			children[i]->SearchKeyWhereField(k,field,fieldtype);
		}
	}

	void SearchAndUpdate(T k, string field, string oldval,string newval) {
			int i;
			for (i = 0; i < currRec; ++i) {
				if (leaf == false) {
					children[i]->SearchAndUpdate(k,field,oldval,newval);
				}
				if (list[i].key == k) {
					cout<<endl;
					cout << "****Key: " << k << "****" << endl;
					list[i].P.UpdateTuple(field,oldval,newval);
				}
			}
			if (leaf == false) {
				children[i]->SearchAndUpdate(k,field,oldval,newval);
			}
		}

	int findKey(T k) {
		int idx = 0;
		while (idx < currRec && list[idx].key < k)
			++idx;
		return idx;
	}
	void remove(T k) {
		int idx = findKey(k);
		if (idx < currRec && list[idx].key == k) {
			if (leaf)
				removeFromLeaf(idx);
			else
				removeFromNonLeaf(idx);
		} else {
			if (leaf) {
				cout << "The key " << k << " is does not exist in the tree\n";
				return;
			}
			bool flag = ((idx == currRec) ? true : false);
			if (children[idx]->currRec < Deg)
				fill(idx);
			if (flag && idx > currRec)
				children[idx - 1]->remove(k);
			else
				children[idx]->remove(k);
		}
		return;
	}
	void removeFromLeaf(int key){
		for (int i = key + 1; i < currRec; ++i)
			list[i - 1] = list[i];

		// Reduce the count of keys
		currRec--;

		return;
	}
	void removeFromNonLeaf(int key){
		T k = list[key].key;
		    if (children[key]->currRec >= Deg)
		    {
		        T pred = getPred(key);
		        list[key].key = pred;
		        children[key]->remove(pred);
		    }
		    else if  (children[key+1]->currRec >= Deg)
		    {
		        T succ = getSucc(key);
		        list[key].key = succ;
		        children[key+1]->remove(succ);
		    }
		    else
		    {
		        merge(key);
		        children[key]->remove(k);
		    }
		    return;
	}
	T getPred(int idx)
	{
	    BTreeNode *cur=children[idx];
	    while (!cur->leaf)
	        cur = cur->children[cur->currRec];
	    return cur->list[cur->currRec-1].key;
	}

	T getSucc(int idx)
	{
	    BTreeNode *cur = children[idx+1];
	    while (!cur->leaf)
	        cur = cur->children[0];
	    return cur->list[0].key;
	}
	void fill(int idx)
	{
	    if (idx!=0 && children[idx-1]->currRec>=Deg)
	        borrowFromPrev(idx);
	    else if (idx!=currRec && children[idx+1]->currRec>=Deg)
	        borrowFromNext(idx);
	    {
	        if (idx != currRec)
	            merge(idx);
	        else
	            merge(idx-1);
	    }
	    return;
	}
	void borrowFromPrev(int idx)
	{

	    BTreeNode<T> *child=children[idx];
	    BTreeNode<T> *sibling=children[idx-1];
	    for (int i=child->currRec-1; i>=0; --i)
	        child->list[i+1] = child->list[i];
	    if (!child->leaf)
	    {
	        for(int i=child->currRec; i>=0; --i)
	            child->children[i+1] = child->children[i];
	    }
	    child->list[0] = list[idx-1];
	    if(!child->leaf)
	        child->children[0] = sibling->children[sibling->currRec];
	    list[idx-1] = sibling->list[sibling->currRec-1];

	    child->currRec += 1;
	    sibling->currRec -= 1;

	    return;
	}
	void borrowFromNext(int idx)
	{

	    BTreeNode<T> *child=children[idx];
	    BTreeNode<T> *sibling=children[idx+1];
	    child->list[(child->currRec)] = list[idx];
	    if (!(child->leaf))
	        child->children[(child->currRec)+1] = sibling->children[0];
	    list[idx] = sibling->list[0];
	    for (int i=1; i<sibling->currRec; ++i)
	        sibling->list[i-1] = sibling->list[i];
	    if (!sibling->leaf)
	    {
	        for(int i=1; i<=sibling->currRec; ++i)
	            sibling->children[i-1] = sibling->children[i];
	    }
	    child->currRec += 1;
	    sibling->currRec -= 1;

	    return;
	}
	void merge(int idx)
	{
	    BTreeNode<T> *child = children[idx];
	    BTreeNode<T> *sibling = children[idx+1];
	    child->list[Deg-1] = list[idx];
	    for (int i=0; i<sibling->currRec; ++i)
	        child->list[i+Deg] = sibling->list[i];
	    if (!child->leaf)
	    {
	        for(int i=0; i<=sibling->currRec; ++i)
	            child->children[i+Deg] = sibling->children[i];
	    }
	    for (int i=idx+1; i<currRec; ++i)
	        list[i-1] = list[i];
	    for (int i=idx+2; i<=currRec; ++i)
	        children[i-1] = children[i];
	    child->currRec += sibling->currRec+1;
	    currRec--;
	    delete(sibling);
	    return;
	}


};
template<class T>
class BTrees {
public:
	BTreeNode<T> *root;
	int Deg;
	BTrees(int order = 0) {

		Deg = order;
		root = NULL;
	}
	void inorder() {
		recInorder(root);
	}
	void traverse() {
		if (root != NULL) {
			root->traverse();
		}
	}
	bool searchB(T item) {
		if (root != NULL) {
			bool b = root->searchBtree(item);
			return b;
		} else {
			return false;
		}
	}

	void InsertData(T k, string p)
	{
		if (root != NULL) {
			root->InsertIfFound(k,p);
		}
	}
	bool search(T & searchitem) {
		bool found = false;
		int loc = 0;
		BTreeNode<T> *curr;
		curr = root;
		while (curr != NULL && !found) {
			searchNode(curr, searchitem, found, loc);
			if (!found)
				curr = curr->children[loc];
		}
		return found;
	}

	void searchNode(BTreeNode<T>*& curr, T &item, bool &found, int & loc) {
		loc = 0;
		while (loc < curr->currRec && item > curr->list[loc]) {
			loc++;
		}
		if (loc < curr->currRec && item == curr->list[loc]) {
			found = true;
		} else {
			found = false;
		}
	}
	void recInorder(BTreeNode<T> *curr) {
		if (curr != NULL) {
			recInorder(curr->children[0]);
			for (int i = 0; i < curr->currRec; ++i) {
				cout << curr->list[i] << " ";
				recInorder(curr->children[i + 1]);
			}
		}
	}
	void insert(T data) {
		if(!searchB(data)){
			if (root == NULL) {
				root = new BTreeNode<T>(Deg, true);
				root->list[0].key = data;
				//root->list[0].P.insert(p);
				root->currRec = 1;
			} else {
				if (root->currRec == 2 * Deg - 1) {
					BTreeNode<T>* newRoot = new BTreeNode<T>(Deg, false);
					newRoot->children[0] = root;
					newRoot->splitNode(0, root);
					int i = 0;
					if (newRoot->list[0].key < data) {
						i++;
					}
					newRoot->children[i]->insertIfNotFull(data);
					root = newRoot;
				} else {
					root->insertIfNotFull(data);
				}
			}
		}
		else
		{
			return;
		}
	}
	string Num2Str(long i) {
		stringstream ss;
		ss << i;
		string str = ss.str();
		return str;
	}
	void MakeBTree(string index = "Year", int filekey=1 )
	{
		string temp;
		ifstream ifile;
		ifile.open(("NCHS_-_Leading_Causes_of_Death__United_States_"+Num2Str(filekey)+".csv").c_str());
		if (ifile.bad()) {
			cout << "can't open the file" << endl;
		}
		getline(ifile, temp);
		if (index == "ID") {
			TempLinkedList<int> Container;
			string records;
			long count = 1;
			ofstream idfile;
			long id = 0;
			while (ifile.good() ) {
				records = "";
				getline(ifile, records);
				idfile.open(("files\\"+ Num2Str(count) + ".txt").c_str());
				for(int i=0;i<records.length();++i){
					if(records[i]!=',' && records[i]!='"'){
						idfile<<records[i];
					}
					else if(records[i]==','){
						idfile<<'\n';
					}
					else if(records[i]=='"'){
						++i;
						while(records[i]!='"'){
							idfile<<records[i];
							++i;
						}

					}
				}
				idfile.close();
				fstream odfile;
				odfile.open(("files\\"+ Num2Str(count) + ".txt").c_str());
				getline(odfile,records);
				id=atoi(records.c_str());
				Container.insert((("files\\"+ Num2Str(count) + ".txt").c_str()),id);
				insert(id);
				count++;
				odfile.close();
			}

			TempNode<T>* temp=Container.head;
			while(temp)
			{
				InsertData(temp->key,temp->path);
				temp=temp->next;
			}
			traverse();
			ifile.close();
		} 
		else if (index == "Year") {
			TempLinkedList<int> Container;
			string records;
			long count = 1;
			ofstream idfile;
			long id = 0;
			while (ifile.good() ) {
				records = "";
				getline(ifile, records);
				//cout << records << " ";
				idfile.open(
					("files\\"+ Num2Str(count) + ".txt").c_str());
				for (int i = 0; i < records.length(); ++i) {
					if (records[i] != ',' && records[i] != '"') {
						idfile << records[i];
					} else if (records[i] == ',') {
						idfile << '\n';
					} else if (records[i] == '"') {
						++i;
						while (records[i] != '"') {
							idfile << records[i];
							++i;
						}

					}
				}
				idfile.close();
				fstream odfile;
				odfile.open(("files\\"+Num2Str(count) + ".txt").c_str());
				getline(odfile, records);
				getline(odfile, records);
				id = atoi(records.c_str());
				Container.insert((("files\\"+Num2Str(count) + ".txt").c_str()),id);
				insert(id);
				count++;
				odfile.close();
			}

			TempNode<T>* temp=Container.head;
			while(temp)
			{
				InsertData(temp->key,temp->path);
				temp=temp->next;
			}
			traverse();

			ifile.close();
		} 
		else if (index == "Deaths") {
			TempLinkedList<int> Container;
			string records;
			long count = 1;
			ofstream idfile;
			long id = 0;
			while (ifile.good() ) {
				records = "";
				getline(ifile, records);
				//cout << records << " ";
				idfile.open(("files\\"+Num2Str(count) + ".txt").c_str());
				for (int i = 0; i < records.length(); ++i) {
					if (records[i] != ',' && records[i] != '"') {
						idfile << records[i];
					} else if (records[i] == ',') {
						idfile << '\n';
					} else if (records[i] == '"') {
						++i;
						while (records[i] != '"') {
							idfile << records[i];
							++i;
						}

					}
				}
				idfile.close();
				fstream odfile;
				odfile.open(("files\\"+Num2Str(count) + ".txt").c_str());
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				id = atoi(records.c_str());
				Container.insert((("files\\"+Num2Str(count) + ".txt").c_str()),id);
				insert(id);
				count++;
				odfile.close();
			}
			TempNode<T>* temp=Container.head;
			while(temp)
			{
				InsertData(temp->key,temp->path);
				temp=temp->next;
			}
			traverse();
			//Container.display();
			ifile.close();
		}

	}


	void MakeSTree(string index="State",int filekey=1){
		string temp1;
		ifstream ifile;
		ifile.open(("NCHS_-_Leading_Causes_of_Death__United_States_"+Num2Str(filekey)+".csv").c_str());
		if (ifile.bad()) {
			cout << "can't open the file" << endl;
		}
		getline(ifile, temp1);
		if (index == "State") 
		{
			TempLinkedList<string> Container;
			string records;
			long count = 1;
			ofstream idfile;
			string id = "";
			while (ifile.good() ) {
				records = "";
				getline(ifile, records);
				//cout << records << " ";
				idfile.open(("files\\"+Num2Str(count) + ".txt").c_str());
				for (int i = 0; i < records.length(); ++i) {
					if (records[i] != ',' && records[i] != '"') {
						idfile << records[i];
					} else if (records[i] == ',') {
						idfile << '\n';
					} else if (records[i] == '"') {
						++i;
						while (records[i] != '"') {
							idfile << records[i];
							++i;
						}

					}
				}
				idfile.close();
				fstream odfile;
				odfile.open(("files\\"+Num2Str(count) + ".txt").c_str());
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				id = records;
				Container.insert((("files\\"+Num2Str(count) + ".txt").c_str()), id);
				insert(id);
				count++;
				odfile.close();
			}
			TempNode<T> *temp = Container.head;
			while (temp) {
				InsertData(temp->key, temp->path);
				temp = temp->next;
			}
			traverse();
			//Container.display();
			ifile.close();
		}
		else if(index=="Cause Name"){
			TempLinkedList<string> Container;
			string records;
			long count = 1;
			ofstream idfile;
			string id = "";
			while (ifile.good()) {
				records = "";
				getline(ifile, records);
				//cout << records << " ";
				idfile.open(("files\\"+Num2Str(count) + ".txt").c_str());
				for (int i = 0; i < records.length(); ++i) {
					if (records[i] != ',' && records[i] != '"') {
						idfile << records[i];
					} else if (records[i] == ',') {
						idfile << '\n';
					} else if (records[i] == '"') {
						++i;
						while (records[i] != '"') {
							idfile << records[i];
							++i;
						}

					}
				}
				idfile.close();
				fstream odfile;
				odfile.open(("files\\"+Num2Str(count) + ".txt").c_str());
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				id = records;
				Container.insert((("files\\"+ Num2Str(count) + ".txt").c_str()), id);
				insert(id);
				count++;
				odfile.close();
			}
			TempNode<T> *temp = Container.head;
			while (temp) {
				InsertData(temp->key, temp->path);
				temp = temp->next;
			}
			traverse();
			//Container.display();
			ifile.close();
		}
	}

	void MakeFtree(string index/*="Death Rate"*/,int filekey/*=1*/){
			string temp1;
			ifstream ifile;
			ifile.open(("NCHS_-_Leading_Causes_of_Death__United_States_"+Num2Str(filekey)+".csv").c_str());
			if (ifile.bad()) {
				cout << "can't open the file" << endl;
			}
			getline(ifile, temp1);
			TempLinkedList<float> Container;
			string records;
			long count = 1;
			ofstream idfile;
			float id=0;
			while (ifile.good() ) {
				records = "";
				getline(ifile, records);
				//cout << records << " ";
				idfile.open(("files\\"+ Num2Str(count) + ".txt").c_str());
				for (int i = 0; i < records.length(); ++i) {
					if (records[i] != ',' && records[i] != '"') {
						idfile << records[i];
					} else if (records[i] == ',') {
						idfile << '\n';
					} else if (records[i] == '"') {
						++i;
						while (records[i] != '"') {
							idfile << records[i];
							++i;
						}

					}
				}
				idfile.close();
				fstream odfile;
				odfile.open(("files\\"+Num2Str(count) + ".txt").c_str());
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				getline(odfile, records);
				//id=stof(records);
				id = atof(records.c_str());
				Container.insert((("files\\"+Num2Str(count) + ".txt").c_str()), id);
				insert(id);
				count++;
				odfile.close();
			}
			TempNode<T> *temp = Container.head;
			while (temp) {
				InsertData(temp->key, temp->path);
				temp = temp->next;
			}
			traverse();
			ifile.close();
	}

	void PointSearch( T key)
	{
		if (root != NULL) {
			root->SearchKey(key);
		}
	}

	void RangeSearch(T source, T destination)
	{
		bool f=false;
		if(root !=NULL)
		{
			root->SearchRangeKeys(f,source,destination);
		}
	}


	void remove(T k)
		{
			if(searchB(k))
			{
				if (!root)
				{
					cout << "The tree is empty\n";
					return;
				}
				root->remove(k);

				if (root->currRec==0)
				{
					BTreeNode<T> *tmp = root;
					if (root->leaf)
						root = NULL;
					else
						root = root->children[0];
					delete tmp;
				}
				traverse();
				return;
			}
			else
			{
				cout<<"***Key " << k <<" Not Found***"<<endl;
			}
		}

	void UpdateKey(T key ,string field, string oldval ,string newval)
	{
		if(root!=NULL){
			root->SearchAndUpdate(key,field,oldval,newval);
		}
	}

	void DeleteKeyWhereField(T key, string field,string fieldtype)
	{
		if(root !=NULL)
		{
			root->SearchKeyWhereField(key,field,fieldtype);
		}
	}
};

#endif
