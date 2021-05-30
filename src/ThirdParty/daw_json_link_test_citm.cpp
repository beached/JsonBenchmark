
#include "daw_json_link_test_citm_json.h"

#include <daw/json/daw_json_link.h>

#include <string_view>

daw::citm::citm_object_t parse_citm(std::string_view json_data) {
  return daw::json::from_json<daw::citm::citm_object_t>(json_data);
}

std::string serialize_citm(daw::citm::citm_object_t const &v) {
  return daw::json::to_json(v);
}
