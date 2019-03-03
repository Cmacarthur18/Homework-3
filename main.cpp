//
//  main.cpp
//  maze.cpp
//
//  Created by Chet MacArthur on 2/9/19.
//  Copyright © 2019 Chet MacArthur. All rights reserved.
//

//#include <iostream>
//#include <cassert>
//#include <string>
//using namespace std;


bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    
    maze[sr][sc] = '#';
    if(sr == er && sc == ec)
        return true; // found the path;
    if(maze[sr-1][sc] == '.' && pathExists( maze,  nRows, nCols, sr-1, sc, er, ec) )
        return true;
    if(maze[sr+1][sc] == '.' &&  pathExists( maze,  nRows, nCols, sr+1, sc, er, ec))
        return true;
    if(maze[sr][sc-1] == '.' && pathExists( maze,  nRows, nCols, sr, sc-1, er, ec) )
        return true;
    if(maze[sr][sc+1] == '.' && pathExists( maze,  nRows, nCols, sr, sc+1, er, ec) )
        return true;
    
    return false;
    
}

//int main()
//{
//    string maze1[10] = {
//        "XXXXXXXXXX",
//        "X...X....X",
//        "XX.X..XX.X",
//        "XX...X...X",
//        "X.X.X..XXX",
//        "X...X.X.XX",
//        "X.X.X....X",
//        "XXX.X.XX.X",
//        "X...X..X.X",
//        "XXXXXXXXXX",
//    };
//
//    string maze2[10] = {
//        "XXXXXXXXXX",
//        "X...X....X",
//        "XX.X..XX.X",
//        "XX...X...X",
//        "X.X.X..XXX",
//        "X...X.X.XX",
//        "X.X.X....X",
//        "XXX.X.XXXX",
//        "X...X..X.X",
//        "XXXXXXXXXX",
//    };
//
//    string maze3[10] = {
//        "XXXXXXXXXX",
//        "XXXXXXX..X",
//        "XX.......X",
//        "X..X....XX",
//        "X..X..XXXX",
//        "X..XXX.X.X",
//        "XX...X...X",
//        "X....XX..X",
//        "XXX.....XX",
//        "XXXXXXXXXX",
//    };
//
//    string maze4[10] = {
//        "XXXXXXXXXX",
//        "XXXXXXX..X",
//        "XX.....X.X",
//        "X..X....XX",
//        "X..X..XXXX",
//        "X..XXX.X.X",
//        "XX...X...X",
//        "X....XX..X",
//        "XXX.....XX",
//        "XXXXXXXXXX",
//    };
//
//    assert(pathExists(maze1, 10, 10, 1, 3, 8, 8));
//    assert(!pathExists(maze2, 10, 10, 1, 3, 8, 8));
//    assert(pathExists(maze3, 10, 10, 5, 6, 2, 8));
//    assert(!pathExists(maze4, 10, 10, 5, 6, 2, 8));
//
//    cout << "all tests passed" << endl;
//}
