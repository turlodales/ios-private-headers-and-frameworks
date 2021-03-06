/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:07 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <SpringBoard/SpringBoard-Structs.h>
#import <UIKit/UIView.h>

@class _UIBackdropView, SBLockOverlayView;

@interface SBLoginAppContainerOverlayWrapperView : UIView {

	_UIBackdropView* _backdropView;
	SBLockOverlayView* _overlayView;

}

@property (nonatomic,readonly) SBLockOverlayView * overlayView;              //@synthesize overlayView=_overlayView - In the implementation block
-(id)initWithFrame:(CGRect)arg1 overlayView:(id)arg2 ;
-(void)layoutSubviews;
-(SBLockOverlayView *)overlayView;
@end

