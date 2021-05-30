#include "test.h"

#define HEADER_ONLY 1

#include "daw_json_link_test_common.h"

#include <daw/daw_fnv1a_hash.h>
#include <daw/daw_visit.h>

#include <cstddef>
#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>

inline namespace {
using map2m01_t =
    get_value<std::map<std::string, std::map<std::string, std::string>>>;

using test_functions_t = std::variant<
    /*get_value<std::vector<L18>>,*/ get_value<std::vector<bool>>,
    get_value<std::vector<double>>, get_value<std::vector<int>>,
    get_value<std::vector<long>>, get_value<std::vector<std::optional<int>>>,
    get_value<std::vector<std::string>>, get_value<std::map<std::string, bool>>,
    get_value<std::map<std::string, int>>,
    get_value<std::map<std::string, std::optional<int>>>,
    get_value<std::map<std::string, std::string>>,
    get_value<daw::citm::citm_object_t>,
    get_value<daw::geojson::FeatureCollection>,
    get_value<daw::twitter::twitter_object_t>, get_value<object2>,
    get_value<object3>, map2m01_t, test_empty, test_vector_double,
    test_vector_string>;

test_functions_t choose_test(char const *test_name ) {
  switch (daw::fnv1a_hash(test_name)) {
  case daw::fnv1a_hash("vector-double"):
    return test_functions_t{test_vector_double{}};
  case daw::fnv1a_hash("vector-string"):
    return test_functions_t{test_vector_string{}};
  case daw::fnv1a_hash("performance/canada.json"):
    return test_functions_t{get_value<daw::geojson::FeatureCollection>{}};
  case daw::fnv1a_hash("performance/citm_catalog.json"):
    return test_functions_t{get_value<daw::citm::citm_object_t>{}};
  case daw::fnv1a_hash("performance/twitter.json"):
    return test_functions_t{get_value<daw::twitter::twitter_object_t>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail02.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail03.json"):
    return test_functions_t{get_value<std::map<std::string, std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail04.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail05.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail06.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail07.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail08.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail09.json"):
    return test_functions_t{get_value<std::map<std::string, bool>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail10.json"):
    return test_functions_t{get_value<std::map<std::string, bool>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail11.json"):
    return test_functions_t{get_value<std::map<std::string, int>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail12.json"):
    return test_functions_t{get_value<std::map<std::string, std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail13.json"):
    return test_functions_t{get_value<std::map<std::string, int>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail14.json"):
    return test_functions_t{get_value<std::map<std::string, int>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail15.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail16.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail17.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail19.json"):
    return test_functions_t{
        get_value<std::map<std::string, std::optional<int>>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail20.json"):
    return test_functions_t{
        get_value<std::map<std::string, std::optional<int>>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail21.json"):
    return test_functions_t{
        get_value<std::map<std::string, std::optional<int>>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail22.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail23.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail24.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail25.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail26.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail27.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail28.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail29.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail30.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail31.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail32.json"):
    return test_functions_t{get_value<std::map<std::string, bool>>{}};
  case daw::fnv1a_hash("jsonchecker_fail/fail33.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
    /*		case daw::fnv1a_hash( "jsonchecker_pass/pass01.json" ):
          return test_functions_t{&testPolyVec};*/ // Polymorphic Array, probaly vector<json_value>
    /*
case daw::fnv1a_hash( "jsonchecker_pass/pass02.json" ):
    return test_functions_t{ get_value<std::vector<L18>>{} };
    */
  case daw::fnv1a_hash("jsonchecker_pass/pass03.json"):
    return test_functions_t{map2m01_t{}};
  case daw::fnv1a_hash("roundtrip/roundtrip01.json"):
    return test_functions_t{get_value<std::vector<std::optional<int>>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip02.json"):
    return test_functions_t{get_value<std::vector<bool>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip03.json"):
    return test_functions_t{get_value<std::vector<bool>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip04.json"):
    return test_functions_t{get_value<std::vector<int>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip05.json"):
    return test_functions_t{get_value<std::vector<std::string>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip06.json"):
    return test_functions_t{get_value<std::vector<int>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip07.json"):
    return test_functions_t{get_value<std::map<std::string, std::string>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip08.json"):
    return test_functions_t{get_value<std::vector<int>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip09.json"):
    return test_functions_t{get_value<object2>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip10.json"):
    return test_functions_t{get_value<object3>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip11.json"):
    return test_functions_t{get_value<std::vector<int>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip12.json"):
    return test_functions_t{get_value<std::vector<int>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip13.json"):
    return test_functions_t{get_value<std::vector<long>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip14.json"):
    return test_functions_t{get_value<std::vector<long>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip15.json"):
    return test_functions_t{get_value<std::vector<int>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip16.json"):
    return test_functions_t{get_value<std::vector<int>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip17.json"):
    return test_functions_t{get_value<std::vector<long>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip18.json"):
    return test_functions_t{get_value<std::vector<long>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip19.json"):
    return test_functions_t{get_value<std::vector<long>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip20.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip21.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip22.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip23.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip24.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip25.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip26.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  case daw::fnv1a_hash("roundtrip/roundtrip27.json"):
    return test_functions_t{get_value<std::vector<double>>{}};
  }
  return test_functions_t{test_empty{}};
}
} // namespace
class daw_json_linkTest : public TestBase {
  mutable test_functions_t current_runner = test_empty{};

public:
  daw_json_linkTest() {}

  void SetUp(char const *fullPath) const override {
    current_runner = choose_test(fullPath);
  }

  void TearDown(char const *) const override { current_runner = test_empty{}; }

  char const *GetName() const override { return "daw_json_link"; }

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
