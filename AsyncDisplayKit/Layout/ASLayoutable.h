/*
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#import <AsyncDisplayKit/ASDimension.h>
#import <AsyncDisplayKit/ASStackLayoutChild.h>

@class ASLayout;

@protocol ASLayoutable <NSObject>

/** 
 * @abstract Additional space to place before this object in the stacking direction.
 * Used when attached to a stack layout.
 */
@property (nonatomic, readwrite) CGFloat spacingBefore;

/**
 * @abstract Additional space to place after this object in the stacking direction.
 * Used when attached to a stack layout.
 */
@property (nonatomic, readwrite) CGFloat spacingAfter;

/**
 * @abstract If the sum of childrens' stack dimensions is less than the minimum size, should this object grow?
 * Used when attached to a stack layout.
 */
@property (nonatomic, readwrite) BOOL flexGrow;

/**
 * @abstract If the sum of childrens' stack dimensions is greater than the maximum size, should this object shrink?
 * Used when attached to a stack layout.
 */
@property (nonatomic, readwrite) BOOL flexShrink;

/**
 * @abstract Specifies the initial size in the stack dimension for this object.
 * Default to ASRelativeDimensionUnconstrained.
 * Used when attached to a stack layout.
 */
@property (nonatomic, readwrite) ASRelativeDimension flexBasis;

/**
 * @abstract Orientation of the object along cross axis, overriding alignItems
 * Used when attached to a stack layout.
 */
@property (nonatomic, readwrite) ASStackLayoutAlignSelf alignSelf;

/**
 * @abstract Calculate a layout based on given size range.
 *
 * @param constrainedSize The minimum and maximum sizes the receiver should fit in.
 *
 * @return An ASLayout instance defining the layout of the receiver and its children.
 *
 * @discussion This method is called on a non-main thread. Other expensive work that needs to
 * be done before display can be performed here, and using ivars to cache any valuable intermediate results is
 * encouraged.
 */
- (ASLayout *)calculateLayoutThatFits:(ASSizeRange)constrainedSize;

@end