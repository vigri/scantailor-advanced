// Copyright (C) 2019  Joseph Artsimovich <joseph.artsimovich@gmail.com>, 4lex4 <4lex49@zoho.com>
// Use of this source code is governed by the GNU GPL v3 license that can be found in the LICENSE file.
//
// Auto oblique (Issue #2): algorithm requested by Zvezdochiot; in the dev branch this is implemented
// as requested (sausage mask, 90° rotation, skew difference, ±5° limit).

#ifndef SCANTAILOR_CORE_OBLIQUEFINDER_H_
#define SCANTAILOR_CORE_OBLIQUEFINDER_H_

#include <optional>

namespace imageproc {
class BinaryImage;
class SkewFinder;
}  // namespace imageproc

namespace deskew {

/**
 * \brief Build a "sausage" mask from a binary image.
 *
 * For each row, black pixels are replaced by a horizontal strip of the same
 * length centered at their average x position. Used to estimate oblique (shear)
 * by comparing skew of the normal mask vs the same mask rotated 90°.
 */
imageproc::BinaryImage buildSausageMask(const imageproc::BinaryImage& image);

/**
 * \brief Estimate oblique angle in degrees using sausage-mask and skew difference.
 *
 * Builds sausage mask, rotates it 90°, runs SkewFinder on original and rotated.
 * Oblique = skew(original) - skew(rotated), clamped to ±maxObliqueDeg.
 * Returns std::nullopt if either skew has low confidence or result is invalid.
 */
std::optional<double> findObliqueDegrees(const imageproc::BinaryImage& mask,
                                         imageproc::SkewFinder& skewFinder,
                                         double maxObliqueDeg = 5.0);

}  // namespace deskew

#endif
