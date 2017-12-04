/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:08 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <UIKit/_UISettings.h>

@interface SBStatusBarStyleOverridesSettings : _UISettings {

	BOOL _exclusive;
	BOOL _showsWhenForeground;
	int _styleOverride;

}

@property (assign,nonatomic) int styleOverride;                     //@synthesize styleOverride=_styleOverride - In the implementation block
@property (assign,nonatomic) BOOL exclusive;                        //@synthesize exclusive=_exclusive - In the implementation block
@property (assign,nonatomic) BOOL showsWhenForeground;              //@synthesize showsWhenForeground=_showsWhenForeground - In the implementation block
+(id)settingsControllerModule;
-(void)setStyleOverride:(int)arg1 ;
-(int)styleOverride;
-(BOOL)showsWhenForeground;
-(void)setShowsWhenForeground:(BOOL)arg1 ;
-(void)setDefaultValues;
-(void)setExclusive:(BOOL)arg1 ;
-(BOOL)exclusive;
@end
