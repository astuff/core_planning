// Copyright 2018-2020 Autoware Foundation. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DECISION_MAKER_CROSS_ROAD_AREA_H
#define DECISION_MAKER_CROSS_ROAD_AREA_H

#include <vector>

#include <autoware_msgs/Lane.h>
#include <geometry_msgs/Point.h>
#include <jsk_recognition_msgs/BoundingBox.h>

namespace decision_maker
{
class CrossRoadArea
{
public:
  CrossRoadArea();
  static bool isInsideArea(const CrossRoadArea* _TargetArea, geometry_msgs::Point pt);

  int id;
  int area_id;
  std::vector<geometry_msgs::Point> points;
  jsk_recognition_msgs::BoundingBox bbox;
  std::vector<autoware_msgs::Lane> insideLanes;
  std::vector<geometry_msgs::Point> insideWaypoint_points;

private:
  static std::vector<geometry_msgs::Point> convhull(const CrossRoadArea* _TargetArea);
};
}  // namespace decision_maker

#endif  // DECISION_MAKER_CROSS_ROAD_AREA_H
