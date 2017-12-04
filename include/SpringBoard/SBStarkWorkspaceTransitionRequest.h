/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:07 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <SpringBoard/SBWorkspaceTransitionRequest.h>

@class SBStarkScreenController;

@interface SBStarkWorkspaceTransitionRequest : SBWorkspaceTransitionRequest {

	SBStarkScreenController* _screenController;

}

@property (nonatomic,retain) SBStarkScreenController * screenController;              //@synthesize screenController=_screenController - In the implementation block
+(id)requestWithScreenController:(id)arg1 ;
-(id)initWithWorkspace:(id)arg1 display:(id)arg2 ;
-(id)initWithScreenController:(id)arg1 ;
-(SBStarkScreenController *)screenController;
-(void)setScreenController:(SBStarkScreenController *)arg1 ;
@end
