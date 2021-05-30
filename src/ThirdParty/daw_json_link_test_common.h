#pragma once

#include <daw/json/daw_json_link.h>

#include <cassert>
#include <ciso646>
#include <cstddef>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <vector>

using namespace daw::json;

using L01 = std::vector<std::string>;
using L02 = std::vector<L01>;
using L03 = std::vector<L02>;
using L04 = std::vector<L03>;
using L05 = std::vector<L04>;
using L06 = std::vector<L05>;
using L07 = std::vector<L06>;
using L08 = std::vector<L07>;
using L09 = std::vector<L08>;
using L10 = std::vector<L09>;
using L11 = std::vector<L10>;
using L12 = std::vector<L11>;
using L13 = std::vector<L12>;
using L14 = std::vector<L13>;
using L15 = std::vector<L14>;
using L16 = std::vector<L15>;
using L17 = std::vector<L16>;
using L18 = std::vector<L17>;

struct object2 {
	std::string foo;
};

struct object3 {
	std::optional<int> a;
	std::string foo;
};

namespace daw::json {
	template<>
	struct json_data_contract<object2> {
		static constexpr char const foo[] = "foo";
		using type = json_member_list<json_string<foo>>;

		static inline auto to_json_data( object2 const &v ) {
			return std::forward_as_tuple( v.foo );
		}
	};

	template<>
	struct json_data_contract<object3> {
		static constexpr char const a[] = "a";
		static constexpr char const foo[] = "foo";
		using type = json_member_list<json_number_null<a, std::optional<int>>,
		                              json_string<foo>>;

		static inline auto to_json_data( object3 const &v ) {
			return std::forward_as_tuple( v.a, v.foo );
		}
	};
} // namespace daw::json

struct string_result : StringResultBase {
	std::string value;

	char const *c_str( ) const override {
		return value.c_str( );
	}
};

template<typename Value>
struct value_result : ParseResultBase {
	Value data;
};

template<typename Value>
struct get_value {
	std::string json_path = std::string{ };

	ParseResultBase *Parse( char const *json, size_t sz ) const {
		try {
			if( json_path.empty( ) ) {
				return new value_result<Value>{
				  from_json<Value>( std::string_view( json, sz ) ) };
			} else {
				return new value_result<Value>{ from_json<Value>(
				  std::string_view( json, sz ),
				  std::string_view( json_path.data( ), json_path.size( ) ) ) };
			}
		} catch( json_exception const & ) { return nullptr; }
		return nullptr;
	}

	StringResultBase *Stringify( ParseResultBase const *value ) const {
		auto const *inputValue = dynamic_cast<value_result<Value> const *>( value );
		if( not inputValue ) {
			return nullptr;
		}
		try {
			return new string_result{ to_json( inputValue->data ) };
		} catch( json_exception const & ) { return nullptr; }
	}

	bool ParseDouble( char const *, double * ) const {
		return false;
	}

	bool ParseString( char const *, std::string & ) const {
		return false;
	}

	StringResultBase *Prettify( ParseResultBase const * ) const {
		return nullptr;
	}

	bool Statistics( ParseResultBase const *, Stat * ) const {
		return false;
	}

	StringResultBase *SaxRoundtrip( char const *, size_t ) const {
		return nullptr;
	}

	bool SaxStatistics( char const *, size_t, Stat * ) const {
		return false;
	}
};

template<typename T, typename U = T>
struct get_key_value {
	std::string json_path = std::string{ };

	using result_t = std::map<std::string, T>;
	using jv_t = json_key_value<no_name, result_t, U>;

	ParseResultBase *Parse( char const *json, size_t sz ) const {
		try {
			if( json_path.empty( ) ) {
				return new value_result<result_t>{
				  from_json<jv_t>( std::string_view( json, sz ) ) };
			} else {
				return new value_result<result_t>{ from_json<jv_t>(
				  std::string_view( json, sz ),
				  std::string_view( json_path.data( ), json_path.size( ) ) ) };
			}
		} catch( json_exception const & ) { return nullptr; }
		return nullptr;
	}

	StringResultBase *Stringify( ParseResultBase const *value ) const {
		auto const *inputT = dynamic_cast<value_result<result_t> const *>( value );
		if( not inputT ) {
			return nullptr;
		}
		try {
			return new string_result{ to_json<std::string, jv_t>( inputT->data ) };
		} catch( json_exception const & ) { return nullptr; }
	}

	bool ParseDouble( char const *, double * ) const {
		return false;
	}

	bool ParseString( char const *, std::string & ) const {
		return false;
	}

	StringResultBase *Prettify( ParseResultBase const * ) const {
		return nullptr;
	}

	bool Statistics( ParseResultBase const *, Stat * ) const {
		return false;
	}

	StringResultBase *SaxRoundtrip( char const *, size_t ) const {
		return nullptr;
	}

	bool SaxStatistics( char const *, size_t, Stat * ) const {
		return false;
	}
};

template<typename T, typename U = T>
struct get_array_value {
	std::string json_path = std::string{ };

	ParseResultBase *Parse( char const *json, size_t sz ) const {
		try {
			auto result = std::make_unique<value_result<std::vector<U>>>( );
			if( json_path.empty( ) ) {
				result->data = from_json_array<T>( std::string_view( json, sz ) );
			} else {
				result->data = from_json_array<T>(
				  std::string_view( json, sz ),
				  std::string_view( json_path.data( ), json_path.size( ) ) );
			}
			return result.release( );
		} catch( json_exception const & ) { return nullptr; }
		return nullptr;
	}

	StringResultBase *Stringify( ParseResultBase const *value ) const {
		auto const *inputT = dynamic_cast<value_result<U> const *>( value );
		assert( inputT );
		try {
			return new string_result{ to_json_array( inputT->data ) };
		} catch( json_exception const & ) { return nullptr; }
	}

	bool ParseDouble( char const *, double * ) const {
		return false;
	}

	bool ParseString( char const *, std::string & ) const {
		return false;
	}

	StringResultBase *Prettify( ParseResultBase const * ) const {
		return nullptr;
	}

	bool Statistics( ParseResultBase const *, Stat * ) const {
		return false;
	}

	StringResultBase *SaxRoundtrip( char const *, size_t ) const {
		return nullptr;
	}

	bool SaxStatistics( char const *, size_t, Stat * ) const {
		return false;
	}
};

struct test_vector_string {
	std::size_t document_size;

	ParseResultBase *Parse( char const *, size_t ) const {
		return nullptr;
	}

	bool ParseDouble( char const *, double * ) const {
		return false;
	}

	bool ParseString( char const *json_document, std::string &result ) const {
		try {
			result = from_json_array<std::string>(
			           std::string_view( json_document, document_size ) )
			           .at( 0 );
			return true;
		} catch( json_exception const & ) { return false; }
	}

	StringResultBase *SaxRoundtrip( char const *, size_t ) const {
		return nullptr;
	}

	StringResultBase *Stringify( ParseResultBase const * ) const {
		return nullptr;
	}

	StringResultBase *Prettify( ParseResultBase const * ) const {
		return nullptr;
	}

	bool Statistics( ParseResultBase const *, Stat * ) const {
		return false;
	}

	bool SaxStatistics( char const *, size_t, Stat * ) const {
		return false;
	}
};

struct test_vector_double {
	std::size_t document_size;

	ParseResultBase *Parse( char const *, size_t ) const {
		return nullptr;
	}

	bool ParseDouble( char const *json_document, double *result ) const {
		try {
			*result = from_json_array<double>(
			            std::string_view( json_document, document_size ) )
			            .at( 0 );
			return true;
		} catch( json_exception const & ) { return false; }
	}

	bool ParseString( char const *, std::string & ) const {
		return false;
	}

	StringResultBase *SaxRoundtrip( char const *, size_t ) const {
		return nullptr;
	}

	StringResultBase *Stringify( ParseResultBase const * ) const {
		return nullptr;
	}

	StringResultBase *Prettify( ParseResultBase const * ) const {
		return nullptr;
	}

	bool Statistics( ParseResultBase const *, Stat * ) const {
		return false;
	}

	bool SaxStatistics( char const *, size_t, Stat * ) const {
		return false;
	}
};

struct test_empty {
	ParseResultBase *Parse( char const *, size_t ) const {
		return nullptr;
	}

	bool ParseDouble( char const *, double * ) const {
		return false;
	}

	bool ParseString( char const *, std::string & ) const {
		return false;
	}

	StringResultBase *SaxRoundtrip( char const *, size_t ) const {
		return nullptr;
	}

	StringResultBase *Stringify( ParseResultBase const * ) const {
		return nullptr;
	}

	StringResultBase *Prettify( ParseResultBase const * ) const {
		return nullptr;
	}

	bool Statistics( ParseResultBase const *, Stat * ) const {
		return false;
	}

	bool SaxStatistics( char const *, size_t, Stat * ) const {
		return false;
	}
};
