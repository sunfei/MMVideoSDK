//
//  MDCameraRenderFilter.h
//  RecordSDK
//
//  Created by sunfei on 2018/12/18.
//  Copyright © 2018 sunfei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MDProcessImageProtocol.h"
#import "MDRecordFilter.h"
#import "MDBBGPUImageSlidingFilter.h"
@import CXBeautyKit;
#import "MDRGift.h"

@class FDKDecoration, FDKDecorationFilterOptions, CXBeautyConfiguration, FDKBeautySettings, MDGPUImageMediaFiltersAttachment;
@protocol FDKDecorationFilterUpdating;

NS_ASSUME_NONNULL_BEGIN

@interface MDCameraRenderFilter : NSObject <MDProcessImageProtocol, FDKDecorationFilterUpdating>

- (instancetype)init;
- (instancetype)initWithFDKDecorationFilterOptions:(FDKDecorationFilterOptions *)options;
- (instancetype)initWithFDKDecorationFilterOptions:(FDKDecorationFilterOptions *)options
                                 slidingFilterMode:(MDRGPUImageSlidingFilterMode)mode NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong) FDKDecoration * _Nullable decoration;
@property (nonatomic, assign) float audioVolume;

@property (nonatomic, assign) BOOL canUseAIBeautySetting;

/** 是否开启ai 美白 默认关闭*/
@property (nonatomic, assign) BOOL useAISkinWhiten;

/** 是否开启ai 磨皮 默认关闭 */
@property (nonatomic, assign) BOOL useAISkinSmooth;

/** 是否开启ai 大眼 瘦脸 默认关闭 */
@property (nonatomic, assign) BOOL useAIBigEyeThinFace;


@property (nonatomic, strong) CXBeautyConfiguration *beautyConfiguration;

- (void)enableMakeup:(BOOL)enable;
- (void)addMakeupLayerConfiguration:(CXMakeupLayerConfiguration *)layerConfiguration;
- (void)removeMakeupLayerConfigurationWithLayerIdentifier:(NSString *)layerIdentifier;

- (void)enableBackgroundBlur:(BOOL)enable;
- (void)backgroundBlurIntensity:(float)intensity;
- (void)backgroundBlurMode:(CXBackgroundBlurMode)mode;

@property (nonatomic, copy) MDRecordFilter *slidingMDFilterA;
@property (nonatomic, copy) MDRecordFilter *slidingMDFilterB;
@property (nonatomic, assign) float slidingOffset;

- (void)updateBeautySetting:(FDKBeautySettings *)beautySetting;
- (void)configDecorationFilterAttachment:(MDGPUImageMediaFiltersAttachment *)filtersAttachment;

- (void)addGift:(MDRGift *)gift;
- (void)removeGift:(NSString *)giftID;
- (void)clearAllGifts;

- (void)cleanCache;
- (void)purgeGPUCache;

// add custom filter
- (void)addCustomFilter:(GPUImageOutput<GPUImageInput> *)filter;
- (void)removeCustomFilter:(GPUImageOutput<GPUImageInput> *)filter;

@end

NS_ASSUME_NONNULL_END