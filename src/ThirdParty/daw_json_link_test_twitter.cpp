
#include "daw_json_link_test_twitter_json.h"

#include <daw/json/daw_json_link.h>

#include <string>
#include <string_view>

daw::twitter::twitter_object_t parse_twitter(std::string_view json_data) {
  using policy_t =
      daw::json::NoCommentSkippingPolicyChecked::template SetPolicyOptions<
          daw::json::MustVerifyEndOfDataIsValid::yes>;
  return daw::json::from_json<daw::twitter::twitter_object_t, policy_t>(
      json_data);
}

std::string serialize_twitter(daw::twitter::twitter_object_t const &v) {
	std::string result{};
	result.reserve( 631514U );
  (void)daw::json::to_json( v, std::back_inserter( result ) );
	return result;

}
