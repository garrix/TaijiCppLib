//
//  NativeDelegate.m
//  TaijiLibClient
//
//  Created by Garrett Taiji on 9/23/13.
//  Copyright (c) 2013 Garrett Taiji. All rights reserved.
//

#import "NativeAdapter.h"
#import <iostream>

@implementation NativeAdapter

#pragma mark Interface Implementation

INativeAdapter::INativeAdapter( void )
{   }

/* implement the destructor of the adapter to dealloc memory of the
 native object
*/
 INativeAdapter::~INativeAdapter( void )
{
    [(id)self dealloc];
}

/* implement the init method which will allocate the native object
 this could, hypothetically, be done in the constructor but i understand
 it to be unadvisable... for reasons i don's quite understand.
*/
void INativeAdapter::init( void )
{
    self = [[NativeAdapter alloc] init];
}

/* 
 implement the adapter method that will call native code
*/
std::string INativeAdapter::modifyInput(std::string message)
{
    return [(id)self modifyInput:message];
}

#pragma mark Native Implementation

/* 
 implementation of native code
 */
-(std::string) modifyInput:(std::string)x
{ 
    return x += "Platform Modified";
}
@end
