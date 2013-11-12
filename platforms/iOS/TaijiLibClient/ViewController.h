//
//  ViewController.h
//  TaijiLibClient
//
//  Created by Garrett Taiji on 9/11/13.
//  Copyright (c) 2013 Garrett Taiji. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TaijiCppLib/LibClass.hpp" 
@interface ViewController : UIViewController{
    IBOutlet  UIButton* statusButton;
    IBOutlet  UISwitch* statusSwitch;
    IBOutlet UITextField * textIn;
    IBOutlet UILabel * textOut;
    TaijiLib::LibClass * l;

}
-(IBAction)toggleSwitch;
//
//@property (nonatomic, retain) UIButton* statusButton;
//@property (nonatomic, retain) UISwitch* statusSwitch;

@end

