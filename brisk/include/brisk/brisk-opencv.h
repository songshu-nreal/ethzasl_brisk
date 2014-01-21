/*
 Copyright (C) 2013  The Autonomous Systems Lab, ETH Zurich,
 Stefan Leutenegger and Simon Lynen.

 BRISK - Binary Robust Invariant Scalable Keypoints
 Reference implementation of
 [1] Stefan Leutenegger,Margarita Chli and Roland Siegwart, BRISK:
 Binary Robust Invariant Scalable Keypoints, in Proceedings of
 the IEEE International Conference on Computer Vision (ICCV2011).

 This file is part of BRISK.

 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the <organization> nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BRISK_BRISK_OPENCV_H_
#define BRISK_BRISK_OPENCV_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/nonfree/nonfree.hpp>

#if HAVE_OPENCV
#include <opencv2/features2d/features2d.hpp>
#else
#include <features-2d-helpers/keypoint.h>
#endif

namespace brisk {

#if HAVE_OPENCV
typedef cv::KeyPoint KeyPoint;
inline float& KeyPointX(KeyPoint& keypoint) {  // NOLINT
  return keypoint.pt.x;
}
inline float& KeyPointY(KeyPoint& keypoint) {  // NOLINT
  return keypoint.pt.y;
}
inline const float& KeyPointX(const KeyPoint& keypoint) {
  return keypoint.pt.x;
}
inline const float& KeyPointY(const KeyPoint& keypoint) {
  return keypoint.pt.y;
}
#else
typedef features_2d::Keypoint KeyPoint;
inline float& KeyPointX(KeyPoint& keypoint) {  // NOLINT
  return keypoint.x;
}
inline float& KeyPointY(KeyPoint& keypoint) {  // NOLINT
  return keypoint.y;
}
inline const float& KeyPointX(const KeyPoint& keypoint) {
  return keypoint.x;
}
inline const float& KeyPointY(const KeyPoint& keypoint) {
  return keypoint.y;
}
#endif  // HAVE_OPENCV

}  // namespace brisk

#endif  // BRISK_BRISK_OPENCV_H_
