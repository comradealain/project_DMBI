#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	string l; string a,b; float lt,gt; lt=gt= 0;
    
    ifstream w("workclass.data"); 

    vector<string> work; 

    while(getline(w,l)){
     work.push_back(l);
    }
    
    ifstream e("education.data");
   
    vector<string> ed;
    while(getline(e,l)){
     ed.push_back(l);
    }
    
    w.close(); e.close();

    cout<<"Attribute values for Workclass:\n";

    for(int i=0;i<work.size();i++)
      cout<<work.at(i)<<"\n";

    cout<<"Attribute values for Education:\n";
  
    for(int i=0;i<ed.size();i++)
      cout<<ed.at(i)<<"\n";

    cout<<"\nEnter Workclass:"; cin>>a;
    cout<<"\nEnter Education:"; cin>>b;
    a.insert(0," ");
    b.insert(0," ");


    ifstream f("b.data");
    ofstream x("less.data");
    ofstream y("more.data");
    //int i=1
    while(getline(f,l)){
      //cout<<l<<" "<<l.size();
      if(l[l.size()-4] == '='){
      	lt++;
        x<<l<<"\n";
      }
      else{ 
      	gt++;
      	y<<l<<"\n";
      }
    
  

    }


    f.close();  x.close(); y.close();

  
    ifstream m("less.data");
        
    float wcless,edless;
    while(getline(m,l)){
    string c; 
    stringstream lineStream(l);  
    while(getline(lineStream,c,',') ){
    
    if(a == c) wcless++;

    if(b == c) edless++;
    }
}   
    m.close();
   
    ifstream n("more.data");

    float wcmore,edmore;
    while(getline(n,l)){
    string c; 
    stringstream lineStream(l);  
    while(getline(lineStream,c,',') ){
 
    if(a == c) wcmore++;

    if(b == c) edmore++;
    }
}
   m.close(); n.close(); 

//cout<<wcless<<" "<<edless<<" "<<wcmore<<" "<<edmore;


float dl = wcless/lt * edless/lt * lt/1500;

float dm = wcmore/gt * edmore/gt * gt/1500;

cout<<"\nPosteriror probablities:";
cout<<"\nP[Decision = <=50K|"<<a<<","<<b<<"]: "<<dl;
cout<<"\nP[Decision = >50K|"<<a<<","<<b<<"]: "<<dm;
  
string c = ">50K";  
if(dm<dl){
	dm = dm + dl;
	dl = dm - dl;
	dm = dm - dl;
	c = "<=50K";
}
 
cout<<"\n\nAs "<<dm<<">"<<dl<<" ,we conclude that the new entry with workclass ="<<a<<" and education ="<<b<<" will be classified as "<<c<<".\n";
return 0;

}