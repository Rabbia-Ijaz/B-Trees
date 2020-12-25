#include <iostream>
	using namespace std;
	#include "BTrees.h"

	int main() {
		int order;
		cout<<"***********************************************************"<<endl;
		cout<<"Please enter the order of B tree: ";
		cin>>order;
		order=ceil(double(order)/2);
		char* field=new char;
		cout<<"Please enter the data field for indexing: ";
		cin.ignore();
		cin.getline(field,100,'\n');
		int file;
		cout<<"Please enter file number (1-10): ";
		cin>>file;
		cout<<"***********************************************************"<<endl;
		if(strcmp(field,"ID")==0)
		{
			BTrees<int> IBtree(order);
			IBtree.MakeBTree("ID",file);
			cout<<"***********************************************************"<<endl;
			int option;
			cout<<"Options:"<<endl;
			cout<<"1) Point Search"<<endl;
			cout<<"2) Range Search"<<endl;
			cout<<"3) Update Key"<<endl;
			cout<<"4) Delete key where field"<<endl;
			cout<<"5) Delete Key"<<endl;
			cout<<"Please enter any option from above:";
			cin>>option;
			if(option==1)
			{
				cout<<"************* Point Search **************"<<endl;
				int k;
				cout<<"Please enter the key: ";
				cin>>k;
				IBtree.PointSearch(k);
			}
			else if(option==2)
			{
				int start,end;
				cout<<"************* Range Search **************"<<endl;
				cout<<"Please enter starting key: ";
				cin>>start;
				cout<<"Please enter ending key: ";
				cin>>end;
				IBtree.RangeSearch(start,end);
			}
			else if(option==3)
			{
				cout<<"************* Update Key **************"<<endl;
				int k1;
				string f,old1,new1;
				cout<<"Please enter field to be updated: ";
				cin>>f;
				cout<<"Please enter key: ";
				cin>>k1;
				cout<<"Please enter old value to be updated: ";
				cin>>old1;
				cout<<"Please enter new value: ";
				cin>>new1;
				IBtree.UpdateKey(k1,f,old1,new1);
			}
			else if(option==4)
			{
				cout<<"************* Delete Key where field **************"<<endl;
				int k;
				string f,ftype;
				cout<<"Please enter the key: ";
				cin>>k;
				cout<<"Please enter the field: ";
				cin>>f;
				cout<<"Please enter the field type: ";
				cin>>ftype;
				IBtree.DeleteKeyWhereField(k,f,ftype);
			}
			else if(option ==5 ){
				cout<<"************* Delete Key ********************"<<endl;
				int k;
				cout<<"Please Enter Key : ";
				cin>>k;
				IBtree.remove(k);
			}
			else
			{
				cout<<"Wrong Option selected"<<endl;
			}
		}
		else if(strcmp(field,"Year")==0)
		{
			BTrees<int> IBtree(order);
			IBtree.MakeBTree("Year",file);
			cout<<"***********************************************************"<<endl;
			int option;
			cout<<"Options:"<<endl;
			cout<<"1) Point Search"<<endl;
			cout<<"2) Range Search"<<endl;
			cout<<"3) Update Key"<<endl;
			cout<<"4) Delete key where field"<<endl;
			cout<<"5) Delete Key"<<endl;
			cout<<"Please enter any option from above:";
			cin>>option;
			if(option==1)
			{
				cout<<"************* Point Search **************"<<endl;
				int k;
				cout<<"Please enter the key: ";
				cin>>k;
				IBtree.PointSearch(k);
			}
			else if(option==2)
			{
				cout<<"************* Range Search **************"<<endl;
				int start;
				int end;
				cout<<"Please enter start key: ";
				cin>>start;
				cout<<"Please enter end key: ";
				cin>>end;
				IBtree.RangeSearch(start,end);
			}
			else if(option==3)
			{
				cout<<"************* Update Key **************"<<endl;
				int k1;
				string f,old1,new1;
				cout<<"Please enter field to be updated: ";
				cin>>f;
				cout<<"Please enter key: ";
				cin>>k1;
				cout<<"Please enter old value to be updated: ";
				cin>>old1;
				cout<<"Please enter new value: ";
				cin>>new1;
				IBtree.UpdateKey(k1,f,old1,new1);
			}
			else if(option==4)
			{
				cout<<"************* Delete Key where field **************"<<endl;
				int k;
				string f,ftype;
				cout<<"Please enter the key: ";
				cin>>k;
				cout<<"Please enter the field: ";
				cin>>f;
				cout<<"Please enter the field type: ";
				cin>>ftype;
				IBtree.DeleteKeyWhereField(k,f,ftype);
			}
			else if(option ==5 ){
				cout<<"************* Delete Key ********************"<<endl;
				int k;
				cout<<"Please Enter Key : ";
				cin>>k;
				IBtree.remove(k);
			}
			else
			{
				cout<<"Wrong Option selected"<<endl;
			}
		}
		else if(strcmp(field,"Deaths")==0)
		{
			BTrees<int> IBtree(order);
			IBtree.MakeBTree("Deaths",file);
			cout<<"***********************************************************"<<endl;
			int option;
			cout<<"Options:"<<endl;
			cout<<"1) Point Search"<<endl;
			cout<<"2) Range Search"<<endl;
			cout<<"3) Update Key"<<endl;
			cout<<"4) Delete key where field"<<endl;
			cout<<"5) Delete Key"<<endl;
			cout<<"Please enter any option from above:";
			cin>>option;
			if(option==1)
			{
				int k;
				cout<<"************* Point Search **************"<<endl;
				cout<<"Please enter the key: ";
				cin>>k;
				IBtree.PointSearch(k);
			}
			else if(option==2)
			{
				int start,end;
				cout<<"************* Range Search **************"<<endl;
				cout<<"Please enter start key"<<endl;
				cin>>start;
				cout<<"Please enter end key"<<endl;
				cin>>end;
				IBtree.RangeSearch(start,end);
			}
			else if(option==3)
			{
				cout<<"************* Update Key **************"<<endl;
				int k1;
				string f,old1,new1;
				cout<<"Please enter field to be updated: ";
				cin>>f;
				cout<<"Please enter key: ";
				cin>>k1;
				cout<<"Please enter old value to be updated: ";
				cin>>old1;
				cout<<"Please enter new value: ";
				cin>>new1;
				IBtree.UpdateKey(k1,f,old1,new1);
			}
			else if(option==4)
			{
				cout<<"************* Delete Key where field **************"<<endl;
				int k;
				string f,ftype;
				cout<<"Please enter the key: ";
				cin>>k;
				cout<<"Please enter the field: ";
				cin>>f;
				cout<<"Please enter the field type: ";
				cin>>ftype;
				IBtree.DeleteKeyWhereField(k,f,ftype);
			}
			else if(option ==5 ){
				cout<<"************* Delete Key ********************"<<endl;
				int k;
				cout<<"Please Enter Key : ";
				cin>>k;
				IBtree.remove(k);
			}
			else
			{
				cout<<"Wrong Option selected"<<endl;
			}
		}
		else if(strcmp(field,"Cause Name")==0)
		{
			BTrees<string> SBtree(order);
			SBtree.MakeSTree("Cause Name",file);
			cout<<"***********************************************************"<<endl;
			int option;
			cout<<"Options:"<<endl;
			cout<<"1) Point Search"<<endl;
			cout<<"2) Range Search"<<endl;
			cout<<"3) Update Key"<<endl;
			cout<<"4) Delete key where field"<<endl;
			cout<<"5) Delete Key"<<endl;
			cout<<"Please enter any option from above: ";
			cin>>option;
			string k;
			if(option==1)
			{
				cout<<"************* Point Search **************"<<endl;
				cout<<"Please enter the key: ";
				cin>>k;
				SBtree.PointSearch(k);
			}
			else if(option==2)
			{
				string oldk;
				string newk;
				cout<<"************* Range Search **************"<<endl;
				cout<<"Please enter start key: "<<endl;
				cin>>oldk;
				cout<<"Please enter end key: "<<endl;
				cin>>oldk;
				SBtree.RangeSearch(oldk,newk);
			}
			else if(option==3)
			{
				cout<<"************* Update Key **************"<<endl;
				string k1;
				string f,old1,new1;
				cout<<"Please enter field to be updated: ";
				cin>>f;
				cout<<"Please enter key: ";
				cin>>k1;
				cout<<"Please enter old value to be updated: ";
				cin>>old1;
				cout<<"Please enter new value: ";
				cin>>new1;
				SBtree.UpdateKey(k1,f,old1,new1);
			}
			else if(option==4)
			{
				cout<<"************* Delete Key where field **************"<<endl;
				string k;
				string f,ftype;
				cout<<"Please enter the key: ";
				cin>>k;
				cout<<"Please enter the field: ";
				cin>>f;
				cout<<"Please enter the field type: ";
				cin>>ftype;
				SBtree.DeleteKeyWhereField(k,f,ftype);
			}
			else if(option ==5 ){
				cout<<"************* Delete Key ********************"<<endl;
				string k;
				cout<<"Please Enter Key: ";
				cin>>k;
				SBtree.remove(k);
			}
			else
			{
				cout<<"Wrong Option selected"<<endl;
			}
		}
		else if(strcmp(field,"State")==0)
		{
			BTrees<string> SBtree(order);
			SBtree.MakeSTree("State",file);
			cout<<"***********************************************************"<<endl;
			int option;
			cout<<"Options:"<<endl;
			cout<<"1) Point Search"<<endl;
			cout<<"2) Range Search"<<endl;
			cout<<"3) Update Key"<<endl;
			cout<<"4) Delete key where field"<<endl;
			cout<<"5) Delete Key"<<endl;
			cout<<"Please enter any option from above: ";
			cin>>option;
			string k;
			if(option==1)
			{
				cout<<"************* Point Search **************"<<endl;
				cout<<"Please enter the key: ";
				cin>>k;
				SBtree.PointSearch(k);
			}
			else if(option==2)
			{
				string oldk;
				string newk;
				cout<<"************* Range Search **************"<<endl;
				cout<<"Please enter start key: "<<endl;
				cin>>oldk;
				cout<<"Please enter end key: "<<endl;
				cin>>oldk;
				SBtree.RangeSearch(oldk,newk);
			}
			else if(option==3)
			{
				cout<<"************* Update Key **************"<<endl;
				string k1;
				string f,old1,new1;
				cout<<"Please enter field to be updated: ";
				cin>>f;
				cout<<"Please enter key: ";
				cin>>k1;
				cout<<"Please enter old value to be updated: ";
				cin>>old1;
				cout<<"Please enter new value: ";
				cin>>new1;
				SBtree.UpdateKey(k1,f,old1,new1);
			}
			else if(option==4)
			{
				cout<<"************* Delete Key where field **************"<<endl;
				string k;
				string f,ftype;
				cout<<"Please enter the key: ";
				cin>>k;
				cout<<"Please enter the field: ";
				cin>>f;
				cout<<"Please enter the field type: ";
				cin>>ftype;
				SBtree.DeleteKeyWhereField(k,f,ftype);
			}
			else if(option ==5 ){
				cout<<"************* Delete Key ********************"<<endl;
				string k;
				cout<<"Please Enter Key : ";
				cin>>k;
				SBtree.remove(k);
			}
			else
			{
				cout<<"Wrong Option selected"<<endl;
			}
		}
		else if(strcmp(field,"Death Rate")==0)
		{
			BTrees<float> FBtree(order);
			FBtree.MakeFtree("Death Rate",file);
			cout<<"***********************************************************"<<endl;
			int option;
			cout<<"Options:"<<endl;
			cout<<"1) Point Search"<<endl;
			cout<<"2) Range Search"<<endl;
			cout<<"3) Update Key"<<endl;
			cout<<"4) Delete key where field"<<endl;
			cout<<"5) Delete Key"<<endl;
			cout<<"Please enter any option from above: ";
			cin>>option;
			
			if(option==1)
			{
				float k;
				cout<<"************* Point Search **************"<<endl;
				cout<<"Please enter the key: ";
				cin>>k;
				FBtree.PointSearch(k);
			}
			else if(option==2)
			{
				float startk,endk;
				cout<<"************* Range Search **************"<<endl;
				cout<<"Please enter start key: "<<endl;
				cin>>startk;
				cout<<"Please enter end key: "<<endl;
				cin>>endk;
				FBtree.RangeSearch(startk,endk);
			}
			else if(option==3)
			{
				cout<<"************* Update Key **************"<<endl;
				float k1;
				string f,old1,new1;
				cout<<"Please enter field to be updated: ";
				cin>>f;
				cout<<"Please enter key: ";
				cin>>k1;
				cout<<"Please enter old value to be updated: ";
				cin>>old1;
				cout<<"Please enter new value: ";
				cin>>new1;
				FBtree.UpdateKey(k1,f,old1,new1);
			}
			else if(option==4)
			{
				cout<<"************* Delete Key where field **************"<<endl;
				float k;
				string f,ftype;
				cout<<"Please enter the key: ";
				cin>>k;
				cout<<"Please enter the field: ";
				cin>>f;
				cout<<"Please enter the field type: ";
				cin>>ftype;
				FBtree.DeleteKeyWhereField(k,f,ftype);
			}
			else if(option ==5 ){
				cout<<"************* Delete Key ********************"<<endl;
				float k;
				cout<<"Please Enter Key : ";
				cin>>k;
				FBtree.remove(k);
			}
			else
			{
				cout<<"Wrong Option selected"<<endl;
			}
		}
		else
		{
			cout<<"**************Wrong field entered*****************"<<endl;
		}
		return 0;
}