//
//  NativeDelegate.h
//  TaijiLibClient
//
//  Created by Garrett Taiji on 9/23/13.
//  Copyright (c) 2013 Garrett Taiji. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TaijiCppLib/INativeAdapter.hpp"

// a native class that will implement INativeDelegate
@interface NativeAdapter : NSObject
{
    
}

// the method that will implement native code wrapped in the delegate method
-(std::string) modifyInput:(std::string) x;
@end
