/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:05 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <SpringBoard/SBCenterZoomSettings.h>

@class SBAnimationSettings;

@interface SBCenterAppZoomSettings : SBCenterZoomSettings {

	double _appHeadStart;
	SBAnimationSettings* _appZoomSettings;
	SBAnimationSettings* _appFadeSettings;

}

@property (assign) double appHeadStart;                                //@synthesize appHeadStart=_appHeadStart - In the implementation block
@property (retain) SBAnimationSettings * appZoomSettings;              //@synthesize appZoomSettings=_appZoomSettings - In the implementation block
@property (retain) SBAnimationSettings * appFadeSettings;              //@synthesize appFadeSettings=_appFadeSettings - In the implementation block
+(id)settingsControllerModule;
-(double)appHeadStart;
-(void)setAppHeadStart:(double)arg1 ;
-(SBAnimationSettings *)appZoomSettings;
-(void)setAppZoomSettings:(SBAnimationSettings *)arg1 ;
-(SBAnimationSettings *)appFadeSettings;
-(void)setAppFadeSettings:(SBAnimationSettings *)arg1 ;
@end
