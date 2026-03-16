// Copyright (C) 2019  Joseph Artsimovich <joseph.artsimovich@gmail.com>, 4lex4 <4lex49@zoho.com>
// Use of this source code is governed by the GNU GPL v3 license that can be found in the LICENSE file.

#include <BinaryImage.h>
#include <SkewFinder.h>
#include <filters/deskew/ObliqueFinder.h>

#include <boost/test/unit_test.hpp>

namespace Tests {
using namespace deskew;
using namespace imageproc;

BOOST_AUTO_TEST_SUITE(ObliqueFinderTestSuite)

BOOST_AUTO_TEST_CASE(build_sausage_mask_null_returns_null) {
  const BinaryImage empty;
  const BinaryImage result = buildSausageMask(empty);
  BOOST_CHECK(result.isNull());
}

BOOST_AUTO_TEST_CASE(build_sausage_mask_preserves_size) {
  BinaryImage img(50, 30, WHITE);
  img.fill(QRect(10, 5, 20, 10), BLACK);
  const BinaryImage result = buildSausageMask(img);
  BOOST_REQUIRE(!result.isNull());
  BOOST_CHECK_EQUAL(result.width(), 50);
  BOOST_CHECK_EQUAL(result.height(), 30);
}

BOOST_AUTO_TEST_CASE(find_oblique_null_mask_returns_nullopt) {
  const BinaryImage empty;
  SkewFinder finder;
  const auto result = findObliqueDegrees(empty, finder, 5.0);
  BOOST_CHECK(!result.has_value());
}

BOOST_AUTO_TEST_SUITE_END()
}  // namespace Tests
