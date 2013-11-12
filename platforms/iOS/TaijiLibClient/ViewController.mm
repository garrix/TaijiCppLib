//
//  ViewController.m
//  TaijiLibClient
//
//  Created by Garrett Taiji on 9/11/13.
//  Copyright (c) 2013 Garrett Taiji. All rights reserved.
//

#import "ViewController.h" 
using namespace TaijiLib;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
  
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma CustomStuff
-(IBAction)toggleSwitch{
    l = new TaijiLib::LibClass();
    std::string x = l->CallNativeDelegate([[textIn text] UTF8String]);
    textOut.text = [NSString stringWithUTF8String:x.c_str()];
    LibClass::LoadLib(!LibClass::LibLoaded());
    statusSwitch.on = LibClass::LibLoaded();
}
#pragma end
@end
