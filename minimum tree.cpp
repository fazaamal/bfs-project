#include <iostream>
#include <cstring>
#include <random>
#include <cmath>

using namespace std;

int main(){

    //initialize no of vertices 
    const int V = 5;
    //initilizing large no. to max graph weight
    const int high = 99999999;

    //adjacency matrix for sample weighted graph
    int G[V][V] = {
        {3,4,12,5,2},
        {4,10,1,3,3},
        {0,1,0,8,0},
        {5,3,8,0,2},
        {1,9,0,1,10}
    };

    //Taking note of visited vertices 
    int visited[V];

    //Initializing visited array to 0 (not yet visited)
    for (int i = 0; i < 5 ; i++){
        visited[i] = false;
    }

    //Initialize first visited index (0) as true
    visited[0]= true;

    cout << endl;
    cout <<"EDGE : WEIGHT" << endl;

    int noOfEdges = 0;
    int sum1 = 0;

    while (noOfEdges < V-1){ //using formula [Number of edges = Number of vertices = 1]

        //Initializing minimum edge weight to large no. 
        int min = high;

        // Initialiaze edge values for output 
        int row = 0;
        int column = 0;
        
        for(int i =  0 ; i < 5; i++){ //graph traversal - row 
            //checking if vertex is vistited 
             if(visited[i]){
               
                for(int j = 0; j <5 ; ++j){  //graph traversal - columns

                    if (min > G[i][j]){ // checking for minimum

                        if(!visited[j] && G[i][j]){ //picking only non visited edges/vertices
                            min = G[i][j]; //assigning new minimum 
                            row = i; 
                            column = j;
                        }
                    }
                }
             }

        }

        //Printing out the edge with corresponding lowest weight
        cout << " " << row << "-" <<  column<< " : " << G[row][column] <<endl ;
        sum1 += min;
        
        //changing hte column to visited 
        visited[column] = true;

        //iterating through the edges
        noOfEdges++;
   
    }

    cout << "\nMinimum cost is " << sum1;
}