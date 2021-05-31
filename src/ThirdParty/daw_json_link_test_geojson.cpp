#include "daw_json_link_test_geojson_json.h"

#include <daw/json/daw_json_link.h>

#include <string>
#include <string_view>

daw::geojson::FeatureCollection parse_geojson(std::string_view json_data) {
  using policy_t =
      daw::json::NoCommentSkippingPolicyChecked::template SetPolicyOptions<
          daw::json::MustVerifyEndOfDataIsValid::yes>;
  return daw::json::from_json<daw::geojson::FeatureCollection, policy_t>(
      json_data);
}

std::string serialize_geojson(daw::geojson::FeatureCollection const &v) {
	std::string result{};
	result.reserve( 2251051U );
  (void)daw::json::to_json( v, std::back_inserter( result ) );
	return result;
}
