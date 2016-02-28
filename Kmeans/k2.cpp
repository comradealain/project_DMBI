#include <iostream>
#include <vector>
#include <fstream>
#include <RInside.h>                    // for the embedded R via RInside
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	int k,d;  

	 cout<<"Enter number of clusters:"; cin>>k;
     //k = 6;

	//cout<<"Enter data[Enter -1 to terminate]:"; cin>>d;
	
	vector<int> v[k],w[k-1],data; vector<float> center;
	
	/*do{
		data.push_back(d);
		cin>>d;

	}while(d != -1); */

	/*for (int i = 0; i < 1500; ++i)   // original data input;
    {
        cin>>d;
        data.push_back(d);
    }*/

	//sort(data.begin(),data.end());

	cout<<"\nEnter values for cluster centers:";

	for(int i=0; i<k; i++){
		cin>>d;
		center.push_back(d);
	}
	/*	center.push_back(10); 
		center.push_back(30);  
        center.push_back(50);
        center.push_back(60);
		center.push_back(80); 
		center.push_back(100);      */
    //int d;
    string l; char a,b;
    ifstream f("a.data");
    //int i=1;
    while(getline(f,l)){
    
    //string c;
   // stringstream lineStream(l);  
    //while(getline(lineStream,c,',') ){
    a = l[0]; b = l[1];
    d = (a-48)*10 + (b-48);
    data.push_back(d);
  //cout<<"\n";
}
    //cout<<"\n";
    //}
    f.close();

      //  center.push_back(20); center.push_back(40);      center.push_back(60);
       // center.push_back(80); center.push_back(100);

    cout<<"Computations:";
    float min,diff; int t;
    
    for(int n=0; n<10; n++){
        cout<<"\nIteration "<<n+1<<":";
	for(int i=0; i<data.size(); i++){
		if(center.at(0)>=data.at(i))
			min = center.at(0) - data.at(i); 

		else
			min = data.at(i) - center.at(0);

		t = 0;

		cout<<"\nFor "<<data.at(i)<<": "<<min<<" ";
		for(int j=1; j<k; j++){

        	if(center.at(j)>=data.at(i))
        		diff = center.at(j) - data.at(i);
        	else
        		diff = data.at(i) - center.at(j);

        	cout<<diff<<" ";



        	if(diff < min){
        		t = j;
        		min = diff;
        
        	}
    }

    v[t].push_back(data.at(i));

    cout<<"Pushed in cluster "<<t+1;

    if(n==0 && t!=k-1) w[t].push_back(data.at(i)); 


 
	}

	for(int i=0; i<k; i++){
		float sum = 0;
		for(int j=0; j<v[i].size(); j++)
			sum += v[i].at(j);
		center.at(i) = sum/v[i].size();
	}
	/*if(n){
    int flag = 0;
    for(int i=0; i<k-1; i++){
    	for(int j=0; j<w[i].size(); j++)
    		if(v[i].at(j) != w[i].at(j)){
    			flag = 1;
    			break;
    		}

        	if(flag) break;
    }


    cout<<flag<<"\n";


    if(!flag) break;

    for(int i=0; i<k-1; i++){
    	for(int j=0; j<w[i].size(); j++)
    		cout<<w[i].at(j);
    	cout<<"\n";
    }
    	
    for(int i=0; i<k-1; i++){
    	for(int j=0; j<v[i].size(); j++)
    		w[i].at(j) = v[i].at(j);

       }
    } */
    
    if(n != 9)
    for(int i=0; i<k; i++)
    	v[i].clear();


}
    ofstream  x("t3.csv");
    for(int i=0; i<k; i++){
    	cout<<"\n\nCluster "<<i+1<<": Mean "<<center.at(i)<<" Number of elements: "<<v[i].size()<<" Elements stored :";
    	for(int j=0; j<v[i].size(); j++){
    		cout<<v[i].at(j)<<" ";
            x<<v[i].at(j)<<"\n"; 
        }
    }
    	
    x.close();

    RInside R(argc, argv);  

  std::string cmd = "tmpf <- tempfile('plot'); "  
    "png(tmpf); "
    "a1 = read.csv('t3.csv'); "
    "plot(a1$X2,main='Clusters',xlab='Young, Mid Aged and Senior Citizens', ylab='Age'); "
    "dev.off();"
    "tmpf"; 
  // by running parseEval, we get the last assignment back, here the filename
  std::string tmpfile = R.parseEval(cmd);

  std::cout << "Could now use plot in " << tmpfile << std::endl;
  unlink(tmpfile.c_str());      // cleaning up

  // alternatively, by forcing a display we can plot to screen
  cmd = "x11(); plot(a1$X2,main='Clusters',xlab='Young, Mid Aged and Senior Citizens', ylab='Age'); Sys.sleep(30);";
  // parseEvalQ evluates without assignment
  R.parseEvalQ(cmd);
    
  exit(0);
	return 0;
}
