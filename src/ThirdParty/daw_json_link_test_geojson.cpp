#include "daw_json_link_test_geojson_json.h"

#include <daw/json/daw_json_link.h>

#include <string>
#include <string_view>

daw::geojson::FeatureCollection parse_geojson(std::string_view json_data) {
  return daw::json::from_json<daw::geojson::FeatureCollection>(json_data);
}

std::string serialize_geojson(daw::geojson::FeatureCollection const &v) {
  return daw::json::to_json(v);
}
