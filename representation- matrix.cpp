//for undirected unweighted graph
#include<iostream>
#include<vector>
using namespace std;

class graph{  //graph class
vector<vector<int> > arr;  //vector of vectors for adjacency matrix
public:
    graph(int a){  //default initializer
        vector<int>c;  //extra vector to help initialize our adjacency matrix
        for(int i=0;i<a;++i)
            c.push_back(0);
        initialize(a,c);  //function to help initialize matrix
    }
    void initialize(int a, vector<int> c){ //function to help initialize matrix
        for(int i=0;i<a;++i)
            arr.push_back(c);
    }
    void addEdge(int a, int b){  //function to add an edge

        arr[a][b]=1;
        arr[b][a]=1;
    }
    void removeEdge(int a, int b){  //function to remover an edge
        arr[a][b]=0;
        arr[b][a]=0;
    }
    void displayGraph(){  //function to display our graph
        cout<<"----------------"<<endl;
        cout<<"  ";
        for(int i=0;i<arr.size();++i)  //to display the row number
            cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<arr.size();++i){
            for(int j=0;j<arr.size();++j)
                if(!j)
                    cout<<i<<" "<<arr[i][j]<<" ";  //to display the column number and the element
                else
                    cout<<arr[i][j]<<" ";  //to display the element
        cout<<endl;
    }
    }

};

int main(){
    cout<<"Enter number of vertices: ";
    int n;
    cin>>n;
    graph g(n);  //declaring an object of graph
    cout<<"Make a selection: "<<endl;
    cout<<"1. Add an edge"<<endl;
    cout<<"2. Remove an edge"<<endl;
    cout<<"3. Display the graph"<<endl;
    int a;
    while(cin>>a){  //while input will be valid
        switch(a){
        case 1:
            int f,t;
            cout<<"Enter edge from: ";
            cin>>f;
            cout<<"Enter edge to: ";
            cin>>t;
            if((f>n-1)||(t>n-1)){  //checking if is out of range
            cout<<"Out of Range!"<<endl;
            }else{
            g.addEdge(f,t);  //calling addEdge() function
            cout<<"Edge added!"<<endl;}
            break;
        case 2:
            cout<<"Enter edge from: ";
            cin>>f;
            cout<<"Enter edge to: ";
            cin>>t;
            if((f>n-1)||(t>n-1)){  //checking if in the range
            cout<<"Out of Range!"<<endl;
            }else{
            g.removeEdge(f,t);
            cout<<"Edge removed!"<<endl;}
            break;
        case 3:
            g.displayGraph();  //display function
            break;
        default:  //default case
            cout<<"Invalid Input!"<<endl;
        }
    }

}

