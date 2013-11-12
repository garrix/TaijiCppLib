//
//  LibStatus.cpp
//  TaijiCppLib
//
//  Created by Garrett Taiji on 9/11/13.
//  Copyright (c) 2013 Garrett Taiji. All rights reserved.
//

#include "LibClass.hpp"

namespace TaijiLib {
 
    // initialize static variables;
    bool LibClass::loaded = false;
    
    LibClass::LibClass() {
        _del = new INativeAdapter();
        _del->init();
    }
    
    LibClass::~LibClass() {
        if(_del){
            delete _del;
            _del = nullptr;}}
    
    
    void LibClass::InstanceLoadLib(bool load){
        loaded = load;
    }
    
    std::string LibClass::CallNativeDelegate(std::string input){

        input += "Native Modified.\n";
        return _del->modifyInput(input);
    }
    
}