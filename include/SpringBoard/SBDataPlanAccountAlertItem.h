/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:06 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <SpringBoard/SBDataPlanAlertItem.h>

@class NSURL;

@interface SBDataPlanAccountAlertItem : SBDataPlanAlertItem {

	NSURL* _accountURL;

}

@property (nonatomic,copy) NSURL * accountURL;              //@synthesize accountURL=_accountURL - In the implementation block
+(id)laterButtonTitle;
+(id)nowButtonTitle;
-(void)alertView:(id)arg1 clickedButtonAtIndex:(long long)arg2 ;
-(id)initWithAccountURL:(id)arg1 ;
-(void)configure:(BOOL)arg1 requirePasscodeForActions:(BOOL)arg2 ;
-(void)setAccountURL:(NSURL *)arg1 ;
-(NSURL *)accountURL;
@end

