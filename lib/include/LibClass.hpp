//
//  LibStatus.hpp
//  TaijiCppLib
//
//  Created by Garrett Taiji on 9/11/13.
//  Copyright (c) 2013 Garrett Taiji. All rights reserved.
//

#ifndef __TaijiCppLib__LibStatus__
#define __TaijiCppLib__LibStatus__

#include <iostream>
#include "INativeAdapter.hpp"

namespace TaijiLib {
    
    class LibClass {
        
    private:
        static bool loaded;
        
        // pointer to a delegate that will be implemented in native code
        INativeAdapter * _del;

    public:
        LibClass();
        ~LibClass();
        static bool LibLoaded(){return loaded;};
        static void LoadLib(bool load){loaded = load;};
        void InstanceLoadLib(bool load);
        std::string CallNativeDelegate(std::string);
    };
}
#endif /* defined(__TaijiCppLib__LibStatus__) */
