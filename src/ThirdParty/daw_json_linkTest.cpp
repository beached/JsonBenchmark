#include "test.h"

#define HEADER_ONLY 1

#include "daw_json_link_test_citm_json.h"
#include "daw_json_link_test_common.h"
#include "daw_json_link_test_geojson_json.h"
#include "daw_json_link_test_twitter_json.h"

#include <daw/daw_fnv1a_hash.h>
#include <daw/daw_visit.h>
#include <daw/json/daw_json_link.h>

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>

template <typename T, typename U = T>
using get_key_value = get_value<
    daw::json::json_key_value<daw::json::no_name, std::map<std::string, T>, U>>;

using map2m01_t = get_key_value<
    std::map<std::string, std::string>,
    daw::json::json_key_value<daw::json::no_name,
                              std::map<std::string, std::string>, std::string>>;

using test_functions_t = std::variant<
    test_vector_double, test_vector_string, get_value<daw::geojson::Polygon>,
    get_value<daw::citm::citm_object_t>,
    get_value<daw::twitter::twitter_object_t>, get_array_value<std::string>,
    get_key_value<std::string>, get_array_value<std::string>,
    get_array_value<std::string>, get_array_value<std::string>,
    get_array_value<std::string>, get_array_value<std::string>,
    get_key_value<bool>, get_key_value<bool>, get_key_value<int>,
    get_key_value<std::string>, get_key_value<int>, get_key_value<int>,
    get_array_value<std::string>, get_array_value<std::string>,
    get_array_value<std::string>, get_key_value<std::optional<int>>,
    get_key_value<std::optional<int>>, get_key_value<std::optional<int>>,
    get_array_value<std::string>, get_array_value<std::string>,
    get_array_value<std::string>, get_array_value<std::string>,
    get_array_value<std::string>, get_array_value<std::string>,
    get_array_value<std::string>, get_array_value<double>,
    get_array_value<double>, get_array_value<double>, get_key_value<bool>,
    get_array_value<std::string>, get_array_value<L18>, map2m01_t,
    get_array_value<std::optional<int>>, get_array_value<bool>,
    get_array_value<bool>, get_array_value<int>, get_array_value<std::string>,
    get_array_value<int>, get_key_value<std::string>, get_array_value<int>,
    get_value<object2>, get_value<object3>, get_array_value<int>,
    get_array_value<int>, get_array_value<long>, get_array_value<long>,
    get_array_value<int>, get_array_value<int>, get_array_value<long>,
    get_array_value<long>, get_array_value<long>, get_array_value<double>,
    get_array_value<double>, get_array_value<double>, get_array_value<double>,
    get_array_value<double>, get_array_value<double>, get_array_value<double>,
    get_array_value<double>, test_empty>;

test_functions_t choose_test(char const *test_name, std::size_t sz) {
  switch (daw::fnv1a_hash(test_name)) {
  case daw::fnv1a_hash("vector-double"):
    return test_vector_double{sz};
  case daw::fnv1a_hash("vector-string"):
    return test_vector_string{sz};
  case daw::fnv1a_hash("performance/canada.json"):
    return get_value<daw::geojson::Polygon>{"features[0].geometry"};
  case daw::fnv1a_hash("performance/citm_catalog.json"):
    return get_value<daw::citm::citm_object_t>{};
  case daw::fnv1a_hash("performance/twitter.json"):
    return get_value<daw::twitter::twitter_object_t>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail02.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail03.json"):
    return get_key_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail04.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail05.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail06.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail07.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail08.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail09.json"):
    return get_key_value<bool>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail10.json"):
    return get_key_value<bool>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail11.json"):
    return get_key_value<int>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail12.json"):
    return get_key_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail13.json"):
    return get_key_value<int>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail14.json"):
    return get_key_value<int>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail15.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail16.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail17.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail19.json"):
    return get_key_value<std::optional<int>>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail20.json"):
    return get_key_value<std::optional<int>>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail21.json"):
    return get_key_value<std::optional<int>>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail22.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail23.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail24.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail25.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail26.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail27.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail28.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail29.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail30.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail31.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail32.json"):
    return get_key_value<bool>{};
  case daw::fnv1a_hash("jsonchecker_fail/fail33.json"):
    return get_array_value<std::string>{};
    /*		case daw::fnv1a_hash( "jsonchecker_pass/pass01.json" ):
          return &testPolyVec;*/ // Polymorphic Array, probaly vector<json_value>
  case daw::fnv1a_hash("jsonchecker_pass/pass02.json"):
    return get_array_value<L18>{};
  case daw::fnv1a_hash("jsonchecker_pass/pass03.json"):
    return map2m01_t{};
  case daw::fnv1a_hash("roundtrip/roundtrip01.json"):
    return get_array_value<std::optional<int>>{};
  case daw::fnv1a_hash("roundtrip/roundtrip02.json"):
    return get_array_value<bool>{};
  case daw::fnv1a_hash("roundtrip/roundtrip03.json"):
    return get_array_value<bool>{};
  case daw::fnv1a_hash("roundtrip/roundtrip04.json"):
    return get_array_value<int>{};
  case daw::fnv1a_hash("roundtrip/roundtrip05.json"):
    return get_array_value<std::string>{};
  case daw::fnv1a_hash("roundtrip/roundtrip06.json"):
    return get_array_value<int>{};
  case daw::fnv1a_hash("roundtrip/roundtrip07.json"):
    return get_key_value<std::string>{};
  case daw::fnv1a_hash("roundtrip/roundtrip08.json"):
    return get_array_value<int>{};
  case daw::fnv1a_hash("roundtrip/roundtrip09.json"):
    return get_value<object2>{};
  case daw::fnv1a_hash("roundtrip/roundtrip10.json"):
    return get_value<object3>{};
  case daw::fnv1a_hash("roundtrip/roundtrip11.json"):
    return get_array_value<int>{};
  case daw::fnv1a_hash("roundtrip/roundtrip12.json"):
    return get_array_value<int>{};
  case daw::fnv1a_hash("roundtrip/roundtrip13.json"):
    return get_array_value<long>{};
  case daw::fnv1a_hash("roundtrip/roundtrip14.json"):
    return get_array_value<long>{};
  case daw::fnv1a_hash("roundtrip/roundtrip15.json"):
    return get_array_value<int>{};
  case daw::fnv1a_hash("roundtrip/roundtrip16.json"):
    return get_array_value<int>{};
  case daw::fnv1a_hash("roundtrip/roundtrip17.json"):
    return get_array_value<long>{};
  case daw::fnv1a_hash("roundtrip/roundtrip18.json"):
    return get_array_value<long>{};
  case daw::fnv1a_hash("roundtrip/roundtrip19.json"):
    return get_array_value<long>{};
  case daw::fnv1a_hash("roundtrip/roundtrip20.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("roundtrip/roundtrip21.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("roundtrip/roundtrip22.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("roundtrip/roundtrip23.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("roundtrip/roundtrip24.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("roundtrip/roundtrip25.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("roundtrip/roundtrip26.json"):
    return get_array_value<double>{};
  case daw::fnv1a_hash("roundtrip/roundtrip27.json"):
    return get_array_value<double>{};
  }
  return test_empty{};
}

class daw_json_linkTest : public TestBase {
  mutable test_functions_t current_runner = test_empty{};

public:
  daw_json_linkTest() {}

  void SetUp(char const *fullPath) const override {
    auth const p = std::filesystem::path(fullPath);
    auto const sz = static_cast<std::size_t>(std::filesystem::file_size(p));
    current_runner = choose_test(fullPath, sz);
  }

  void TearDown(char const *) const override { current_runner = test_empty{}; }

  char const *GetName() const override { return "DAW JSON Link"; }

  char const *Type() const override { return "C++17"; }

  char const *GetFilename() const override { return __FILE__; }

  ParseResultBase *Parse(char const *json, std::size_t length) const override {
    return daw::visit_nt(current_runner,
                         [&](auto const &r) { return r.Parse(json, length); });
  }

  bool ParseDouble(char const *json, double *d) const override {
    return daw::visit_nt(current_runner,
                         [&](auto const &r) { return r.ParseDouble(json, d); });
  }

  bool ParseString(char const *json, std::string &s) const override {
    return daw::visit_nt(current_runner,
                         [&](auto const &r) { return r.ParseString(json, s); });
  }

  StringResultBase *SaxRoundtrip(char const *json,
                                 std::size_t length) const override {

    return daw::visit_nt(current_runner, [&](auto const &r) {
      return r.SaxRoundtrip(json, length);
    });
  }

  StringResultBase *
  Stringify(ParseResultBase const *parseResult) const override {
    return daw::visit_nt(current_runner, [&](auto const &r) {
      return r.Stringify(parseResult);
    });
  }

  StringResultBase *
  Prettify(ParseResultBase const *parseResult) const override {
    return daw::visit_nt(
        current_runner, [&](auto const &r) { return r.Prettify(parseResult); });
  }

  bool Statistics(ParseResultBase const *parseResult,
                  Stat *stat) const override {
    stat->objectCount = 0;
    stat->arrayCount = 0;
    stat->numberCount = 0;
    stat->stringCount = 0;
    stat->trueCount = 0;
    stat->falseCount = 0;
    stat->nullCount = 0;

    stat->memberCount = 0;
    stat->elementCount = 0;
    stat->stringLength = 0;
    return daw::visit_nt(current_runner, [&](auto const &r) {
      return r.Statistics(parseResult, stat);
    });
  }

  bool SaxStatistics(char const *json, std::size_t length,
                     Stat *stat) const override {
    stat->objectCount = 0;
    stat->arrayCount = 0;
    stat->numberCount = 0;
    stat->stringCount = 0;
    stat->trueCount = 0;
    stat->falseCount = 0;
    stat->nullCount = 0;

    stat->memberCount = 0;
    stat->elementCount = 0;
    stat->stringLength = 0;

    return daw::visit_nt(current_runner, [&](auto const &r) {
      return r.SaxStatistics(json, length, stat);
    });
  }

  bool SaxStatisticsUTF16(char const *, std::size_t, Stat *) const override {
    return false;
  }
};

REGISTER_TEST(daw_json_linkTest);
