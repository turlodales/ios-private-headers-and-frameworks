/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:06 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

@class FBSDisplay, SBLayoutState;


@protocol SBDisplayLayoutContext <NSObject>
@property (nonatomic,readonly) FBSDisplay * display; 
@property (nonatomic,readonly) SBLayoutState * layoutState; 
@required
-(FBSDisplay *)display;
-(SBLayoutState *)layoutState;

@end
