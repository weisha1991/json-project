#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace nlohmann;

namespace
{
    class Person
	{
	  private:
		std::string name{};
		int age = 0;

	  public:
		bool operator==(const Person& rhs) const
		{
			return name == rhs.name && age == rhs.age;
		}

		Person() = default;
		Person(std::string name_, int age_)
			: name(std::move(name_))
			, age(age_)
		{}

		friend void to_json(nlohmann::json& nlohmann_json_j, const Person& nlohmann_json_t) { nlohmann_json_j["age"] = nlohmann_json_t.age; nlohmann_json_j["name"] = nlohmann_json_t.name; } \
    friend void from_json(const nlohmann::json& nlohmann_json_j, Person& nlohmann_json_t) { nlohmann_json_j.at("age").get_to(nlohmann_json_t.age); nlohmann_json_j.at("name").get_to(nlohmann_json_t.name); }
	};
}
TEST(JsonTest, should_succ)
{
	Person person("lzb", 31);
	cout << json(person).dump(4) << endl;
}
