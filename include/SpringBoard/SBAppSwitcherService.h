/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:06 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@class NSString;

@interface SBAppSwitcherService : NSObject {

	NSString* _bundleIdentifier;
	NSString* _viewServiceClassName;

}

@property (nonatomic,copy) NSString * bundleIdentifier;                  //@synthesize bundleIdentifier=_bundleIdentifier - In the implementation block
@property (nonatomic,copy) NSString * viewServiceClassName;              //@synthesize viewServiceClassName=_viewServiceClassName - In the implementation block
+(id)switcherServiceWithName:(id)arg1 viewServiceClassName:(id)arg2 ;
-(NSString *)viewServiceClassName;
-(void)setViewServiceClassName:(NSString *)arg1 ;
-(NSString *)bundleIdentifier;
-(void)setBundleIdentifier:(NSString *)arg1 ;
@end

