//rat in a maze
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>>& visited,int rows,int cols,int maze[][4]){
    if((newx >= 0 && newx <= rows-1) && (newy >= 0 && newy <= cols-1) && (maze[newx][newy] == 1) && (visited[newx][newy]==false)){
        return true;
    }
    else{
        return false;
    }
}

void permutation(int maze[][4], int rows,int cols, int srcx, int srcy, string& output, vector<vector<bool>>& visited){
    //base case
    if(srcx == rows-1 && srcy == cols-1){
        cout<<output<<endl;
        return;
    }
    
    //up
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(newx,newy,visited,rows,cols,maze)){
        output.push_back('U');
        visited[newx][newy] = true;
        permutation(maze,rows,cols,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    
    //down
    newx = srcx+1;
    newy = srcy;
    if(isSafe(newx,newy,visited,rows,cols,maze)){
        output.push_back('D');
         visited[newx][newy] = true;
        permutation(maze,rows,cols,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    
    //right
    newx = srcx;
    newy = srcy+1;
    if(isSafe(newx,newy,visited,rows,cols,maze)){
        output.push_back('R');
         visited[newx][newy] = true;
        permutation(maze,rows,cols,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    
    //left
    newx = srcx;
    newy = srcy-1;
    if(isSafe(newx,newy,visited,rows,cols,maze)){
        output.push_back('L');
         visited[newx][newy] = true;
        permutation(maze,rows,cols,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    
}

int main(){
    int maze[][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int rows = 4;
    int cols = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";
    vector<vector<bool>>visited(rows,vector<bool>(cols,false));
    if(maze[0][0] == 0){
        cout<<"Rate can't be reached to the destination"<<endl;
        return 0;
    }
    else{
        visited[srcx][srcy] = true;
        permutation(maze,rows,cols,srcx,srcy,output,visited);
    }
}