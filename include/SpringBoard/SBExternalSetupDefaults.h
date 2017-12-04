/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:09 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <BaseBoard/BSAbstractDefaultDomain.h>

@class NSString;

@interface SBExternalSetupDefaults : BSAbstractDefaultDomain

@property (assign,getter=isDeviceSetup,nonatomic) BOOL deviceSetup; 
@property (nonatomic,readonly) BOOL setupFinishedAllSteps; 
@property (nonatomic,readonly) NSString * setupState; 
-(void)setSetupFinishedAllSteps:(BOOL)arg1 ;
-(BOOL)setupFinishedAllSteps;
-(void)setSetupState:(NSString *)arg1 ;
-(NSString *)setupState;
-(void)setDeviceSetup:(BOOL)arg1 ;
-(BOOL)isDeviceSetup;
-(void)synchronizeBuddyPreferences;
-(id)init;
-(void)_bindAndRegisterDefaults;
@end
