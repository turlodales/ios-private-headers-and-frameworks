/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:07 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <SpringBoardUI/SBAlertItem.h>

@class NSString;

@interface SBInsecureDrawingAlertItem : SBAlertItem {

	NSString* _processName;

}

@property (nonatomic,copy) NSString * processName;              //@synthesize processName=_processName - In the implementation block
-(NSString *)processName;
-(void)setProcessName:(NSString *)arg1 ;
-(BOOL)ignoreIfAlreadyDisplaying;
-(BOOL)dismissOnLock;
-(void)configure:(BOOL)arg1 requirePasscodeForActions:(BOOL)arg2 ;
-(BOOL)shouldShowInLockScreen;
@end

