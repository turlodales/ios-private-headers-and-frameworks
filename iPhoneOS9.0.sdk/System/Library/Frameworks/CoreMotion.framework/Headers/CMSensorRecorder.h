/*
 *  CMSensorRecorder.h
 *  CoreMotion
 *
 *  Copyright (c) 2015 Apple Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreMotion/CMAccelerometer.h>

NS_ASSUME_NONNULL_BEGIN

/*
 * CMRecordedAccelerometerData
 *
 * Discussion:
 *   CMRecordedAccelerometerData contains data for each accelerometer sample.
 */
NS_CLASS_AVAILABLE(NA, 9_0) __WATCHOS_AVAILABLE(2.0)
@interface CMRecordedAccelerometerData : CMAccelerometerData

/*
 * identifier
 *
 * Discussion:
 *   Unique identifier that identifies the batch for which the accelerometer sample
 *   was recorded in. This identifier will be monotonically increased
 *   for each new sensor batch recorded and can be used as an anchor for future queries.
 */
@property(readonly) uint64_t identifier;

/*
 * startDate
 *
 * Discussion:
 *   Wall time for when this sensor sample is recorded.
 *
 */
@property(readonly) NSDate *startDate;

@end

/*
 * CMSensorDataList
 *
 * Discussion:
 *   Allows retroactive access to sensor data via enumeration.
 *   If created with accelerometerDataSince: or accelerometerDataFrom:to:
 *   each enumeration will yield an object of type CMRecordedAccelerometerData.
 *   Due to the large number of samples that can be processed, the
 *   enumeration should not be run on the main/UI thread.
 */
NS_CLASS_AVAILABLE(NA, 9_0) __WATCHOS_AVAILABLE(2.0)
@interface CMSensorDataList : NSObject<NSFastEnumeration>
@end

/*
 * CMSensorRecorder
 *
 * Discussion:
 *    CMSensorRecorder allows applications to record sensor data for periods
 *    during which the application is not active.  This data is then made
 *    available for later access (up to 3 days) when the application
 *    is run at a later time.
 */
NS_CLASS_AVAILABLE(NA, 9_0) __WATCHOS_AVAILABLE(2.0)
@interface CMSensorRecorder : NSObject

/*
 * isAccelerometerAvailable
 *
 * Discussion:
 *   Determines whether accelerometer recording is available.
 */
+ (BOOL)isAccelerometerRecordingAvailable;

/*
 * isAuthorizedForRecording
 *
 * Discussion:
 *   Determines whether the application is authorized for sensor recording.
 */
+ (BOOL)isAuthorizedForRecording;

/*
 * accelerometerDataSince
 *
 * Discussion:
 *    Gives access to recorded accelerometer samples based on batch id.
 */
- (nullable CMSensorDataList *)accelerometerDataSince:(uint64_t)identifier;

/*
 * accelerometerDataFrom:To:
 *
 * Discussion:
 *    Gives access to recorded accelerometer samples given a time range (fromDate, toDate]
 */
- (nullable CMSensorDataList *)accelerometerDataFrom:(NSDate *)fromDate to:(NSDate *)toDate;

/*
 * recordAccelerometerFor:
 *
 * Discussion:
 *    Starts recording accelerometer data for the duration given at 50hz.  Data can be recorded
 *    for up to 12 hours.
 */
- (void)recordAccelerometerFor:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
