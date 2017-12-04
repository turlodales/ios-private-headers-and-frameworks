//
//  HKHealthStore.h
//  HealthKit
//
//  Copyright (c) 2013-2014 Apple Inc. All rights reserved.
//

#import <HealthKit/HKDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class HKBiologicalSexObject;
@class HKBloodTypeObject;
@class HKDevice;
@class HKFitzpatrickSkinTypeObject;
@class HKObject;
@class HKObjectType;
@class HKQuantity;
@class HKQuantityType;
@class HKQuery;
@class HKSample;
@class HKSampleType;
@class HKSource;
@class HKSourceRevision;
@class HKUnit;
@class HKWorkout;
@class HKWorkoutSession;

/*!
 @class         HKHealthStore
 @abstract      The HKHealthStore class provides an interface for accessing and storing the user's health data.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKHealthStore : NSObject

/*!
 @method        isHealthDataAvailable
 @abstract      Returns YES if HealthKit is supported on the device.
 @discussion    HealthKit is not supported on all iOS devices.  Using HKHealthStore APIs on devices which are not
                supported will result in errors with the HKErrorHealthDataUnavailable code.  Call isHealthDataAvailable
                before attempting to use other parts of the framework.
 */
+ (BOOL)isHealthDataAvailable;

/*!
 @method        authorizationStatusForType:
 @abstract      Returns the application's authorization status for the given object type.
 */
- (HKAuthorizationStatus)authorizationStatusForType:(HKObjectType *)type;

/*!
 @method        requestAuthorizationToShareTypes:readTypes:completion:
 @abstract      Prompts the user to authorize the application for reading and saving objects of the given types.
 @discussion    Before attempting to execute queries or save objects, the application should first request authorization
                from the user to read and share every type of object for which the application may require access.
 
                The request is performed asynchronously and its completion will be executed on an arbitrary background
                queue after the user has responded.  If the user has already chosen whether to grant the application
                access to all of the types provided, then the completion will be called without prompting the user.
                The success parameter of the completion indicates whether prompting the user, if necessary, completed
                successfully and was not cancelled by the user.  It does NOT indicate whether the application was
                granted authorization.
 
                To customize the messages displayed on the authorization sheet, set the following keys in your app's
                Info.plist file. Set the NSHealthShareUsageDescription key to customize the message for reading data. Set
                the NSHealthUpdateUsageDescription key to customize the message for writing data.
 */
- (void)requestAuthorizationToShareTypes:(nullable NSSet<HKSampleType *> *)typesToShare
                               readTypes:(nullable NSSet<HKObjectType *> *)typesToRead
                              completion:(void (^)(BOOL success, NSError * __nullable error))completion;

/*!
 @method        handleAuthorizationForExtensionWithCompletion:
 @abstract      Prompts the user to authorize the application for reading and saving objects.
 @discussion    When an app extension calls requestAuthorizationToShareTypes:readTypes:completion:, the parent application
                is responsible for calling this method to prompt the user to authorize the app and its extensions for the
                types that the extension requested access to.
 
                The request is performed asynchronously and its completion will be executed on an arbitrary background
                queue after the user has responded.  The success parameter of the completion indicates whether prompting
                the user, if necessary, completed successfully and was not cancelled by the user.  It does NOT indicate
                whether the application was granted authorization.
 */
- (void)handleAuthorizationForExtensionWithCompletion:(void (^)(BOOL success, NSError * __nullable error))completion NS_AVAILABLE_IOS(9_0) __WATCHOS_UNAVAILABLE NS_EXTENSION_UNAVAILABLE("Not available to extensions") ;

/*!
 @method        earliestPermittedSampleDate
 @abstract      Samples prior to the earliestPermittedSampleDate cannot be saved or queried.
 @discussion    On some platforms, only samples with end dates newer than the value returned by earliestPermittedSampleDate
                may be saved or retreived.
 */
- (NSDate *)earliestPermittedSampleDate NS_AVAILABLE_IOS(9_0);

/*!
 @method        saveObject:withCompletion:
 @abstract      Saves an HKObject.
 @discussion    After an object is saved, on subsequent retrievals the sourceRevision property of the object will be set
                to the HKSourceRevision representing the version of the application that saved it.
 
                If the object has an HKObjectType property, then in order to save an object successfully the application
                must first request authorization to share objects with that type.  Saving an object with the same unique
                identifier as another object that has already been saved will fail.  When the application attempts to
                save multiple objects, if any single object cannot be saved then none of the objects will be saved.
                The operation will fail if the objects array contains samples with endDates that are older than the date
                returned by earliestPermittedSampleDate.
 
                This operation is performed asynchronously and the completion will be executed on an arbitrary
                background queue.
 */
- (void)saveObject:(HKObject *)object withCompletion:(void(^)(BOOL success, NSError * __nullable error))completion;

/*!
 @method        saveObjects:withCompletion:
 @abstract      Saves an array of HKObjects.
 @discussion    See discussion of saveObject:withCompletion:.
 */
- (void)saveObjects:(NSArray<HKObject *> *)objects withCompletion:(void(^)(BOOL success, NSError * __nullable error))completion;

/*!
 @method        deleteObject:withCompletion:
 @abstract      Deletes a single HKObject from the HealthKit database.
 @discussion    See deleteObjects:withCompletion:.
 */
- (void)deleteObject:(HKObject *)object withCompletion:(void(^)(BOOL success, NSError * __nullable error))completion;

/*!
 @method        deleteObjects:withCompletion:
 @abstract      Deletes multiple HKObjects from the HealthKit database.
 @discussion    An application may only delete objects that it previously saved.  This operation is performed
                asynchronously and the completion will be executed on an arbitrary background queue.
 */
- (void)deleteObjects:(NSArray<HKObject *> *)objects withCompletion:(void(^)(BOOL success, NSError * __nullable error))completion NS_AVAILABLE_IOS(9_0);

/*!
 @method        deleteObjectsMatchingQuery:withCompletion:
 @abstract      Deletes all objects matching the given predicate from the HealthKit database.
 @discussion    An application may only delete objects that it previously saved.  This operation is performed
                asynchronously and the completion will be executed on an arbitrary background queue.
 */
- (void)deleteObjectsOfType:(HKObjectType *)objectType predicate:(NSPredicate *)predicate withCompletion:(void(^)(BOOL success, NSUInteger deletedObjectCount, NSError * __nullable error))completion NS_AVAILABLE_IOS(9_0);

/*!
 @method        executeQuery:
 @abstract      Begins executing the given query.
 @discussion    After executing a query the completion, update, and/or results handlers of that query will be invoked
                asynchronously on an arbitrary background queue as results become available.  Errors that prevent a
                query from executing will be delivered to one of the query's handlers.  Which handler the error will be
                delivered to is defined by the HKQuery subclass.  The behavior of calling this method with a query that
                is already executing is undefined.  If a query would retrieve objects with an HKObjectType property,
                then the application must request authorization to access objects of that type before executing the query.
 */
- (void)executeQuery:(HKQuery *)query;

/*!
 @method        stopQuery:
 @abstract      Stops a query that is executing from continuing to run.
 @discussion    Calling this method will prevent the handlers of the query from being invoked in the future.  If the
                query is already stopped, this method does nothing.
 */
- (void)stopQuery:(HKQuery *)query;

/*!
 @method        splitTotalEnergy:startDate:endDate:resultsHandler:
 @abstract      For the time period specified, this method calculates the resting and active energy parts of the total
                energy passed.
 @discussion    This method uses the users metrics like age, biological sex, body mass and height to determine
                their basal metabolic rate. If the application does not have authorization to access these characteristics
                or if the user has not entered their data then this method uses builtin default values.
 */
- (void)splitTotalEnergy:(HKQuantity *)totalEnergy
               startDate:(NSDate *)startDate
                 endDate:(NSDate *)endDate
          resultsHandler:(void(^)(HKQuantity * __nullable restingEnergy, HKQuantity * __nullable activeEnergy, NSError * __nullable error))resultsHandler NS_AVAILABLE_IOS(9_0);

/*!
 @method        dateOfBirthWithError:
 @abstract      Returns the user's date of birth.
 @discussion    Before calling this method, the application should request authorization to access objects with the
                HKCharacteristicType identified by HKCharacteristicTypeIdentifierDateOfBirth.
 */
- (nullable NSDate *)dateOfBirthWithError:(NSError **)error;

/*!
 @method        biologicalSexWithError:
 @abstract      Returns an object encapsulating the user's biological sex.
 @discussion    Before calling this method, the application should request authorization to access objects with the
                HKCharacteristicType identified by HKCharacteristicTypeIdentifierBiologicalSex.
 */
- (nullable HKBiologicalSexObject *)biologicalSexWithError:(NSError **)error;

/*!
 @method        bloodTypeWithError:
 @abstract      Returns an object encapsulating the user's blood type.
 @discussion    Before calling this method, the application should request authorization to access objects with the
                HKCharacteristicType identified by HKCharacteristicTypeIdentifierBloodType.
 */
- (nullable HKBloodTypeObject *)bloodTypeWithError:(NSError **)error;

/*!
 @method        fitzpatrickSkinTypeWithError:
 @abstract      Returns an object encapsulating the user's Fitzpatrick skin type.
 @discussion    Before calling this method, the application should request authorization to access objects with the
                HKCharacteristicType identified by HKCharacteristicTypeIdentifierFitzpatrickSkinType.
 */
- (nullable HKFitzpatrickSkinTypeObject *)fitzpatrickSkinTypeWithError:(NSError **)error NS_AVAILABLE_IOS(9_0);

@end

@interface HKHealthStore (HKWorkout)

/*!
 @method        addSamples:toWorkout:completion:
 @abstract      Associates samples with a given workout.
 @discussion    This will associate the given samples with the given workout. These samples will then be returned by a
                query that contains this workout as a predicate. If a sample is added that is not saved yet, then it will
                be saved for you. Note that the sample will be saved without an HKDevice.
 
                The workout provided must be one that has already been saved to HealthKit.
 */
- (void)addSamples:(NSArray<HKSample *> *)samples toWorkout:(HKWorkout *)workout completion:(void(^)(BOOL success, NSError * __nullable error))completion;

/*!
 @method        startWorkoutSession:
 @abstract      Starts the given workout session.
 @discussion    This method will asynchronously begin a workout session. The methods on the session's delegate will be 
                called when the session has successfully started or fails to start.
 */
- (void)startWorkoutSession:(HKWorkoutSession *)workoutSession HK_AVAILABLE_WATCHOS_ONLY(2_0);

/*!
 @method        endWorkoutSession:
 @abstract      Ends the given workout session.
 @discussion    This method will end the given session if it is currently running. The state of the workout session will
                transition to HKWorkoutSessionStateEnded. Once a workout session is ended, it cannot be reused to start
                a new workout session.
 */
- (void)endWorkoutSession:(HKWorkoutSession *)workoutSession HK_AVAILABLE_WATCHOS_ONLY(2_0);

@end


@interface HKHealthStore (HKBackgroundDelivery)

/*!
 @method        enableBackgroundDeliveryForType:frequency:withCompletion:
 @abstract      This method enables activation of your app when data of the type is recorded at the cadence specified.
 @discussion    When an app has subscribed to a certain data type it will get activated at the cadence that is specified
                with the frequency parameter. The app is still responsible for creating an HKObserverQuery to know which
                data types have been updated and the corresponding fetch queries. Note that certain data types (such as
                HKQuantityTypeIdentifierStepCount) have a minimum frequency of HKUpdateFrequencyHourly. This is enforced
                transparently to the caller.
 */
- (void)enableBackgroundDeliveryForType:(HKObjectType *)type frequency:(HKUpdateFrequency)frequency withCompletion:(void(^)(BOOL success, NSError * __nullable error))completion __WATCHOS_UNAVAILABLE;

- (void)disableBackgroundDeliveryForType:(HKObjectType *)type withCompletion:(void(^)(BOOL success, NSError * __nullable error))completion __WATCHOS_UNAVAILABLE;

- (void)disableAllBackgroundDeliveryWithCompletion:(void(^)(BOOL success, NSError * __nullable error))completion __WATCHOS_UNAVAILABLE;

@end

/*!
 @constant      HKUserPreferencesDidChangeNotification
 @abstract      A notification posted every time the user updates their preferred units.
 @discussion    Each HKHealthStore posts a HKUserPreferencesDidChangeNotification notification when the preferred unit 
                for a HKQuantityType is changed by the user. To guarantee your listener will only receive a single 
                notification when this occurs, it is necessary to provide an HKHealthStore instance for the object
                parameter of NSNotificationCenter's addObserver methods.
 */
HK_EXTERN NSString * const HKUserPreferencesDidChangeNotification NS_AVAILABLE_IOS(8_2);

@interface HKHealthStore (HKUserPreferences)

/*!
 @method        preferredUnitsForQuantityTypes:completion:
 @abstract      Calls the completion with the preferred HKUnits for a given set of HKQuantityTypes.
 @discussion    A preferred unit is either the unit that the user has chosen in Health for displaying samples of the
                given quantity type or the default unit for that type in the current locale of the device. To access the
                user's preferences it is necessary to request read or share authorization for the set of HKQuantityTypes
                provided. If neither read nor share authorization has been granted to the app, then the default unit for
                the locale is provided.
 
                An error will be returned when preferred units are inaccessible because protected health data is
                unavailable or authorization status is not determined for one or more of the provided types.
 
                The returned dictionary will map HKQuantityType to HKUnit.
 */
- (void)preferredUnitsForQuantityTypes:(NSSet<HKQuantityType *> *)quantityTypes completion:(void(^)(NSDictionary<HKQuantityType*, HKUnit *> *preferredUnits, NSError * __nullable error))completion NS_AVAILABLE_IOS(8_2);

@end

/*!
 @class     HKBiologicalSexObject
 @abstract  A wrapper object for HKBiologicalSex enumeration.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKBiologicalSexObject : NSObject <NSCopying, NSSecureCoding>

@property (readonly) HKBiologicalSex biologicalSex;

@end

/*!
 @class     HKBloodTypeObject
 @abstract  A wrapper object for HKBloodType enumeration.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKBloodTypeObject : NSObject <NSCopying, NSSecureCoding>

@property (readonly) HKBloodType bloodType;

@end

/*!
 @class     HKFitzpatrickSkinTypeObject
 @abstract  A wrapper object for HKFitzpatrickSkinType enumeration.
 */
HK_CLASS_AVAILABLE_IOS(9_0)
@interface HKFitzpatrickSkinTypeObject : NSObject <NSCopying, NSSecureCoding>

@property (readonly) HKFitzpatrickSkinType skinType;

@end

NS_ASSUME_NONNULL_END