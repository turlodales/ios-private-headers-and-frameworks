/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:08 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <SpringBoard/SpringBoard-Structs.h>
#import <UIKit/UIView.h>

@class SBCornerAnimatingImageView, UIView, UIImage;

@interface SBSwitcherSnapshotImageView : UIView {

	SBCornerAnimatingImageView* _imageView;
	UIView* _scalingView;
	double _cornerRadius;
	BOOL _usesNonuniformScaling;

}

@property (nonatomic,readonly) UIImage * image; 
@property (assign,nonatomic) double cornerRadius; 
@property (assign,nonatomic) BOOL usesNonuniformScaling;              //@synthesize usesNonuniformScaling=_usesNonuniformScaling - In the implementation block
-(void)setUsesNonuniformScaling:(BOOL)arg1 ;
-(CGAffineTransform)scalingTransform;
-(BOOL)usesNonuniformScaling;
-(double)_transformHorizontalScale;
-(double)_transformVerticalScale;
-(double)_transformScale;
-(void)layoutSubviews;
-(id)initWithImage:(id)arg1 ;
-(void)setCornerRadius:(double)arg1 ;
-(UIImage *)image;
-(double)cornerRadius;
-(void)_updateCornerRadius;
@end

