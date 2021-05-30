// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/beached/daw_json_link
//

#pragma once

#include "daw_json_link_test_geojson.h"

#include <daw/json/daw_from_json_fwd.h>
#include <daw/json/daw_json_link_types.h>

#include <array>
#include <cstdint>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>

namespace daw::json {
template <> struct json_data_contract<daw::geojson::Point> {
  using type = json_ordered_member_list<double, double>;
  using exact_class_mapping = void;

  [[nodiscard, maybe_unused]] static constexpr auto
  to_json_data(daw::geojson::Point const &p) {
    return std::forward_as_tuple(p.x, p.y);
  }
};

template <> struct json_data_contract<daw::geojson::Property> {
  using ignore_unknown_members = void;
  static constexpr char const type_sym[] = "type";
  static constexpr char const name[] = "name";
  using type = json_member_list<json_string_raw<name, std::string_view>>;

  [[nodiscard, maybe_unused]] static constexpr auto
  to_json_data(daw::geojson::Property const &value) {
    return std::forward_as_tuple(value.name);
  }
};

template <> struct json_data_contract<daw::geojson::Polygon> {
  static constexpr char const type_sym[] = "type";
  static constexpr char const coordinates[] = "coordinates";
  using type = json_member_list<
      json_string_raw<type_sym, std::string_view>,
      json_array<coordinates, std::vector<daw::geojson::Point>>>;

  using exact_class_mapping = void;
  [[nodiscard, maybe_unused]] static constexpr auto
  to_json_data(daw::geojson::Polygon const &value) {
    return std::forward_as_tuple(value.type, value.coordinates);
  }
};

template <> struct json_data_contract<daw::geojson::Feature> {
  using ignore_unknown_members = void;
  static constexpr char const type_sym[] = "type";
  static constexpr char const properties[] = "properties";
  static constexpr char const geometry[] = "geometry";
  using type = json_member_list<json_string_raw<type_sym, std::string_view>,
                                json_class<properties, daw::geojson::Property>,
                                json_class<geometry, daw::geojson::Polygon>>;

  [[nodiscard, maybe_unused]] static constexpr auto
  to_json_data(daw::geojson::Feature const &value) {
    return std::forward_as_tuple(value.type, value.properties, value.geometry);
  }
};

template <> struct json_data_contract<daw::geojson::FeatureCollection> {
  using ignore_unknown_members = void;
  static constexpr char const type_sym[] = "type";
  static constexpr char const features[] = "features";
  using type = json_member_list<json_string_raw<type_sym, std::string_view>,
                                json_array<features, daw::geojson::Feature>>;

  [[nodiscard, maybe_unused]] static constexpr auto
  to_json_data(daw::geojson::FeatureCollection const &value) {
    return std::forward_as_tuple(value.type, value.features);
  }
};
} // namespace daw::json
