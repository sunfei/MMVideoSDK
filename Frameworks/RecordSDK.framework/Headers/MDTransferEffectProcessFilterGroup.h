//
//  MDTransferEffectProcessFilterGroup.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/2.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface MDTransferEffectProcessFilterGroup : GPUImageFilterGroup

@property (nonatomic, assign, getter=isClip) BOOL clip;

@end

NS_ASSUME_NONNULL_END
