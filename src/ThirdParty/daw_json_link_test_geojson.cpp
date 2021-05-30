#include "daw_json_link_test_geojson_json.h"

#include <daw/json/daw_from_json.h>

#include <string_view>

namespace daw::json {
	template daw::geojson::Polygon
	from_json<daw::geojson::Polygon, NoCommentSkippingPolicyChecked, false,
	          daw::geojson::Polygon>( std::string_view const &json_data,
	                                  std::string_view );
}
