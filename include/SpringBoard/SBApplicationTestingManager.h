/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:04 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@class NSString;

@interface SBApplicationTestingManager : NSObject {

	NSString* _currentTestName;
	NSString* _scrollTestActiveSubtest;

}

@property (nonatomic,copy) NSString * currentTestName;                      //@synthesize currentTestName=_currentTestName - In the implementation block
@property (nonatomic,copy) NSString * scrollTestActiveSubtest;              //@synthesize scrollTestActiveSubtest=_scrollTestActiveSubtest - In the implementation block
+(id)sharedInstance;
-(NSString *)scrollTestActiveSubtest;
-(void)setScrollTestActiveSubtest:(NSString *)arg1 ;
-(NSString *)currentTestName;
-(void)setCurrentTestName:(NSString *)arg1 ;
@end
