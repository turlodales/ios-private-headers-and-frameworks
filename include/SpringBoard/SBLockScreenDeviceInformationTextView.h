/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:07 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <SpringBoard/SpringBoard-Structs.h>
#import <UIKit/UIView.h>
#import <libobjc.A.dylib/SBUILegibility.h>

@class _UILegibilitySettings, UIView, NSString, SBUILegibilityLabel, NSArray;

@interface SBLockScreenDeviceInformationTextView : UIView <SBUILegibility> {

	_UILegibilitySettings* _legibilitySettings;
	double _strength;
	UIView* _containerView;
	NSString* _supervisionText;
	SBUILegibilityLabel* _supervisionLabel;
	NSArray* _deviceInformationText;
	SBUILegibilityLabel* _deviceInformationLabel;

}

@property (nonatomic,copy) NSString * supervisionText;                   //@synthesize supervisionText=_supervisionText - In the implementation block
@property (nonatomic,copy) NSArray * deviceInformationText;              //@synthesize deviceInformationText=_deviceInformationText - In the implementation block
@property (assign,nonatomic) double strength;                            //@synthesize strength=_strength - In the implementation block
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
-(void)_updateSupervisionLabel;
-(void)_updateDeviceInformationLabel;
-(void)setSupervisionText:(NSString *)arg1 ;
-(void)setDeviceInformationText:(NSArray *)arg1 ;
-(NSString *)supervisionText;
-(NSArray *)deviceInformationText;
-(id)initWithFrame:(CGRect)arg1 ;
-(void)layoutSubviews;
-(double)strength;
-(void)setStrength:(double)arg1 ;
-(void)updateForChangedSettings:(id)arg1 ;
-(id)_labelFont;
@end

