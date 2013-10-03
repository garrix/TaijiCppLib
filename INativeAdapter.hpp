//
//  NativeDelegate.hpp
//  TaijiCppLib
//
//  Created by Garrett Taiji on 9/23/13.
//  Copyright (c) 2013 Garrett Taiji. All rights reserved.
//

#ifndef TaijiCppLib_NativeAdapter_hpp
#define TaijiCppLib_NativeAdapter_hpp

#include <iostream>
// Define an interface for Native code to implement
class INativeAdapter{

private:

    void * self; // void pointer to self, which will implement the interface

public:

    INativeAdapter(void);
    ~INativeAdapter(void);

    // an init method to be implemented by the delegate
    void init( void );
    
    // a parameterized method to be implemented by the delegate
    int showMessage( std::string message );
};


#endif
