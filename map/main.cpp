
#include <map>
#include <unordered_map>

#include <iostream>
#include <string>

struct CityRecord {
  std::string name;
  uint64_t population;
  double latitude, longitude;

  bool operator==(const CityRecord &other) const {
    return population == other.population;
  }

  bool operator<(const CityRecord &other) const {
    return population < other.population;
  }
};

template <> struct std::hash<CityRecord> {
  std::size_t operator()(const CityRecord &key) const {
    return std::hash<std::string>()(key.name);
  }
};

int main() {
  std::map<std::string, CityRecord> cityMap;
  cityMap["Melbourne"] = CityRecord{"Melbourne", 500000, 2.4, 9.4};
  cityMap["Berlin"] = CityRecord{"Berlin", 43214, 2.4, 9.4};
  cityMap["Paris"] = CityRecord{"Paris", 3215616, 2.4, 9.4};
  cityMap["Tokyo"] = CityRecord{"Tokyo", 43642772, 2.4, 9.4};
  cityMap["London"] = CityRecord{"London", 43265, 2.4, 9.4};

  if (cityMap.find("Berlin") != cityMap.end()) {
    std::cout << "Found Berlin\n";
  }

  for (auto &[name, city] : cityMap) {
    std::cout << name << "\n";
  }

  CityRecord &BeijingData = cityMap["Beijing"];
  BeijingData.population = 654323754;
  BeijingData.name = "Beijing";
  BeijingData.latitude = 2.5;
  BeijingData.longitude = 9.4;

  // struct as key doesn't work like this alone, the hash function with key type
  // CityRecord has to be defined.
  std::map<CityRecord, uint32_t> foundedMap;

  foundedMap[BeijingData] = 203;

  std::cout << BeijingData.name << " is founded at " << foundedMap[BeijingData]
            << "\n";

  for (auto &[name, city] : cityMap) {
    std::cout << name << "\n";
    foundedMap[city] = 0;
  }

  for (auto &[city, founded] : foundedMap) {
    std::cout << city.name << " has population " << city.population << "\n";
  }

  return 0;
}
