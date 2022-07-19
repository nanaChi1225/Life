//
//  main.cpp
//  life3
//
//  Created by nana on 2022/7/19.
//

#include <iostream>
#include "utility.hpp"
#include "life.hpp"
using namespace std;

int main() {
    Life configuration;
    instructions( );
    configuration.initialize( );
    configuration.print( );
    cout << "Continue viewing new generations? " << endl;
    while(user_says_yes( )){
        configuration.update( );
        configuration.print( );
        cout << "Continue viewing new generations? " << endl;
    }
    return 0;
}
