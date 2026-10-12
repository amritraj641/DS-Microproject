#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
struct Request{
    int id,priority;
    string name,item;
};
Request r[20];
int n=0;
string items[]={"Water","Food","Blanket","Medicine"};
int stock[]={800,500,200,100};
void add(){
    if (n>=20){
        cout<<"Limit reached!\n";
        return;
    }
    cout<<"\nEnter ID,Name,Item,Priority: ";
    cin>>r[n].id>>r[n].name>>r[n].item>>r[n].priority;
    if (r[n].priority<1 || r[n].priority>5) {
        cout<<"Invalid priority!\n";
        return;
    }
    if (r[n].item!="Water" && r[n].item!="Food" && r[n].item!="Blanket" && r[n].item!="Medicine") {
        cout<<"Invalid item!\n";
        return;
    }
    n++;
    cout<<"Request added!\n";
}
void display() {
    cout<<"\nID\tName\tItem\tPriority\n";
    for (int i=0;i<n;i++)
        cout<<r[i].id<<"\t"<<r[i].name<<"\t"<<r[i].item<<"\t"<<r[i].priority<<endl;
}
void search() {
    int id;
    cout<<"\nEnter ID: ";
    cin>>id;
    for (int i=0;i<n;i++)
        if (r[i].id==id) {
            cout<<"Found: "<<r[i].name<<" needs "<<r[i].item<<endl;
            return;
        }
    cout<<"Not found!\n";
}
void sortRequests() {
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (r[i].priority<r[j].priority)
                swap(r[i],r[j]);
    cout<<"Sorted by priority!\n";
}
void inventory() {
    cout<<"\nInventory:\n";
    for (int i=0;i<4;i++)
        cout<<items[i]<<" : "<<stock[i]<<endl;
}
void allocate() {
    int id,q;
    cout<<"\nEnter ID and quantity: ";
    cin>>id>>q;
    if (q<=0) {
        cout<<"Invalid quantity!\n";
        return;
    }
    for (int i=0;i<n;i++)
        if (r[i].id==id)
            for (int j=0;j<4;j++)
                if (r[i].item==items[j]) {
                    if (stock[j]>=q) {
                        stock[j]-=q;
                        cout<<"Relief allocated!\n";
                    }else
                        cout<<"Not enough stock!\n";
                    return;
                }
    cout<<"Request not found!\n";
}
int main() {
    int ch;
    while (true) {
        cout<<"\n====FLOOD RELIEF SYSTEM ====\n1.Add\n2.Display\n3.Search\n4.Sort\n5.Inventory\n6.Allocate\n7.Exit";
        cout<<"\nChoice: ";
        cin>>ch;
        switch (ch) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: sortRequests(); break;
            case 5: inventory(); break;
            case 6: allocate(); break;
            case 7: cout <<"Thank you!\n"; return 0;
            default: cout<<"Invalid choice!\n";
        }
    }
}
