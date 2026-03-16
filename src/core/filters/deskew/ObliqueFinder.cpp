// Copyright (C) 2019  Joseph Artsimovich <joseph.artsimovich@gmail.com>, 4lex4 <4lex49@zoho.com>
// Use of this source code is governed by the GNU GPL v3 license that can be found in the LICENSE file.
// Auto oblique: Zvezdochiot; dev branch implements as requested (see ObliqueFinder.h).

#include "ObliqueFinder.h"

#include <algorithm>
#include <cmath>

#include <BinaryImage.h>
#include <BWColor.h>
#include <SkewFinder.h>
#include <imageproc/OrthogonalRotation.h>

namespace deskew {

using namespace imageproc;

BinaryImage buildSausageMask(const BinaryImage& image) {
  if (image.isNull()) {
    return BinaryImage();
  }
  const int w = image.width();
  const int h = image.height();
  BinaryImage result(w, h, WHITE);

  for (int y = 0; y < h; ++y) {
    int count = 0;
    int64_t sumX = 0;
    for (int x = 0; x < w; ++x) {
      if (image.getPixel(x, y) == BLACK) {
        ++count;
        sumX += x;
      }
    }
    if (count > 0) {
      const double center = static_cast<double>(sumX) / count;
      const int left = std::max(0, static_cast<int>(std::floor(center - count / 2.0)));
      const int len = std::min(count, w - left);
      if (len > 0) {
        result.fill(QRect(left, y, len, 1), BLACK);
      }
    }
  }
  return result;
}

std::optional<double> findObliqueDegrees(const BinaryImage& mask,
                                         SkewFinder& skewFinder,
                                         double maxObliqueDeg) {
  if (mask.isNull()) {
    return std::nullopt;
  }

  const BinaryImage sausage = buildSausageMask(mask);
  const BinaryImage rotated = orthogonalRotation(sausage, 90);

  const Skew s1 = skewFinder.findSkew(mask);
  const Skew s2 = skewFinder.findSkew(rotated);

  if (s1.confidence() < Skew::GOOD_CONFIDENCE || s2.confidence() < Skew::GOOD_CONFIDENCE) {
    return std::nullopt;
  }

  double oblique = s1.angle() - s2.angle();
  oblique = std::max(-maxObliqueDeg, std::min(maxObliqueDeg, oblique));
  return oblique;
}

}  // namespace deskew
