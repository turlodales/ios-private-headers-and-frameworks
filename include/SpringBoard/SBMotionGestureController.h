/*
* This header is generated by classdump-dyld 1.0
* on Friday, March 3, 2017 at 12:02:08 AM China Standard Time
* Operating System: Version 9.3 (Build 13E233)
* Image Source: /System/Library/CoreServices/SpringBoard.app/SpringBoard
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@class NSMutableDictionary, CMGestureManager;

@interface SBMotionGestureController : NSObject {

	NSMutableDictionary* _observersByPriority;
	CMGestureManager* _motionGestureManager;

}
+(id)sharedInstance;
+(void)initialize;
-(void)removeGestureObserver:(id)arg1 ;
-(void)addGestureObserver:(id)arg1 withPriority:(unsigned long long)arg2 ;
-(void)addGestureObserver:(id)arg1 ;
-(void)_removeGestureManager;
-(void)_addGestureObserver:(id)arg1 withPriority:(unsigned long long)arg2 ;
-(void)_updateGestureManager;
-(void)_removeGestureObserver:(id)arg1 ;
-(void)_enumerateObserversByPriority:(/*^block*/id)arg1 ;
-(id)_highestPriorityObservers;
-(void)_addGestureManager;
-(void)_notifyObserversOfGesture:(int)arg1 ;
-(void)dealloc;
-(id)init;
-(BOOL)_hasObservers;
-(id)_observersForPriority:(unsigned long long)arg1 ;
@end
