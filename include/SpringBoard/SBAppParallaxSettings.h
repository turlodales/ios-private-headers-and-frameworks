/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:07 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <UIKit/_UISettings.h>

@class SBFLockScreenWallpaperParallaxSettings, SBFHomeScreenWallpaperParallaxSettings, SBFParallaxSettings;

@interface SBAppParallaxSettings : _UISettings {

	SBFLockScreenWallpaperParallaxSettings* _lockscreenWallpaperSettings;
	SBFHomeScreenWallpaperParallaxSettings* _homescreenWallpaperSettings;
	SBFParallaxSettings* _iconSettings;
	SBFParallaxSettings* _iconBadgeSettings;

}

@property (retain) SBFLockScreenWallpaperParallaxSettings * lockscreenWallpaperSettings;              //@synthesize lockscreenWallpaperSettings=_lockscreenWallpaperSettings - In the implementation block
@property (retain) SBFHomeScreenWallpaperParallaxSettings * homescreenWallpaperSettings;              //@synthesize homescreenWallpaperSettings=_homescreenWallpaperSettings - In the implementation block
@property (retain) SBFParallaxSettings * iconSettings;                                                //@synthesize iconSettings=_iconSettings - In the implementation block
@property (retain) SBFParallaxSettings * iconBadgeSettings;                                           //@synthesize iconBadgeSettings=_iconBadgeSettings - In the implementation block
+(id)settingsControllerModule;
-(SBFParallaxSettings *)iconBadgeSettings;
-(SBFLockScreenWallpaperParallaxSettings *)lockscreenWallpaperSettings;
-(SBFHomeScreenWallpaperParallaxSettings *)homescreenWallpaperSettings;
-(void)setLockscreenWallpaperSettings:(SBFLockScreenWallpaperParallaxSettings *)arg1 ;
-(void)setHomescreenWallpaperSettings:(SBFHomeScreenWallpaperParallaxSettings *)arg1 ;
-(void)setIconBadgeSettings:(SBFParallaxSettings *)arg1 ;
-(void)setDefaultValues;
-(SBFParallaxSettings *)iconSettings;
-(void)setIconSettings:(SBFParallaxSettings *)arg1 ;
@end

