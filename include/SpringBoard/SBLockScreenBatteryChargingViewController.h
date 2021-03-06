/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:05 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <UIKit/UIViewController.h>

@protocol SBLockScreenBatteryChargingViewControllerDelegate;
@class SBLockScreenBatteryChargingView, NSTimer, NSMutableArray;

@interface SBLockScreenBatteryChargingViewController : UIViewController {

	BOOL _shouldDisplayBattery;
	SBLockScreenBatteryChargingView* _chargingView;
	NSTimer* _visibilityTimer;
	BOOL _displayDetailedCharge;
	NSMutableArray* _connectedDevices;
	id<SBLockScreenBatteryChargingViewControllerDelegate> _delegate;

}

@property (assign,nonatomic,__weak) id<SBLockScreenBatteryChargingViewControllerDelegate> delegate;              //@synthesize delegate=_delegate - In the implementation block
-(void)_clearVisibilityTimer;
-(BOOL)batteryVisible;
-(void)_visibilityTimerFired:(id)arg1 ;
-(id)initForDisplayOfBattery:(BOOL)arg1 ;
-(id)chargingView;
-(void)showChargeLevelWithBatteryVisible:(BOOL)arg1 ;
-(void)setDelegate:(id<SBLockScreenBatteryChargingViewControllerDelegate>)arg1 ;
-(void)dealloc;
-(id<SBLockScreenBatteryChargingViewControllerDelegate>)delegate;
-(void)loadView;
-(void)prepareForDismissal;
@end

