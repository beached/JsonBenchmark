
#include "daw_json_link_test_citm_json.h"

#include <daw/json/daw_from_json.h>

#include <string_view>

namespace daw::json {
	template daw::citm::citm_object_t
	from_json<daw::citm::citm_object_t, NoCommentSkippingPolicyChecked, false,
	          daw::citm::citm_object_t>( std::string_view const &json_data );
}
