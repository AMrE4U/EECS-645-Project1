/*
*  <main.cpp filename>
*
*  Created by Ronald Henderson
*  Contact Email: rjhender@ku.edu
*  Description: 
*  Copyright 2012 University of Kansas, EECS Department. All rights reserved
*  Date: 10/22/12
*  Update: 10/22/12
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
    //Open the file stream.
    if( argc < 2)
    {
        cout << "Input File Needed" << endl;
        return(0);
    }

    ifstream inFile( argv[1] );
    if(inFile.fail() )
    {
        cout << "Failed to open the file, closing program.\n";
        return(0);
    }
    
    //Declare maps for registers and memory locations.
    map<string,int> regs;
    map<int, int> mem;
    
    //Declare variables for registers and memory addresses.
    string input;
    int value;
    inFile >> input;
    cout << input << endl;
    if(input == "REGISTERS")
    {
        cout << "Read regs.\n";
        inFile >> input;
        while(input != "MEMORY"){
            inFile >> value;
            regs[input] = value;
            inFile >> input;
        }
    }
    cout << input << endl;
    if(input == "MEMORY")
    {
        cout << "Read mem.\n";
        inFile >> input;
        while(input != "CODE")
        {
            inFile >> value;
            mem[atoi(input.c_str())] = value;
            inFile >> input;
        }
    }
    
    cout << "Output of maps.\n";
    map<string,int>::iterator iter;
    for( iter = regs.begin(); iter != regs.end(); ++iter ) {
      cout << "Key: '" << iter->first << "', Value: " << iter->second << endl; 
    }
    
    map<int, int>::iterator seciter;
    for( seciter = mem.begin(); seciter != mem.end(); ++seciter ) {
      cout << "Key: '" << seciter->first << "', Value: " << seciter->second << endl; 
    }
    
    return(0);
}