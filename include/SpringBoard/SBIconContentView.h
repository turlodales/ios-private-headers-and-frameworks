/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:05 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <SpringBoard/SpringBoard-Structs.h>
#import <UIKit/UIView.h>

@class NSMutableArray;

@interface SBIconContentView : UIView {

	long long _orientation;
	NSMutableArray* _folderContentViews;
	double _statusBarHeight;

}

@property (assign,nonatomic) long long orientation;               //@synthesize orientation=_orientation - In the implementation block
@property (assign,nonatomic) double statusBarHeight;              //@synthesize statusBarHeight=_statusBarHeight - In the implementation block
-(id)initWithOrientation:(long long)arg1 statusBarHeight:(double)arg2 ;
-(void)clearAllFolderContentViews;
-(void)pushFolderContentView:(id)arg1 ;
-(CGRect)_frameForFolderView:(id)arg1 ;
-(void)popFolderContentView:(id)arg1 ;
-(id)_folderViews;
-(void)layoutSubviews;
-(double)statusBarHeight;
-(void)setOrientation:(long long)arg1 ;
-(long long)orientation;
-(void)didAddSubview:(id)arg1 ;
-(void)setStatusBarHeight:(double)arg1 ;
@end
