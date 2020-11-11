
#include "hw/l3_DomainLayer.h"

using namespace std;


bool AutoPart::invariant() const
{
    return _cost     
        && !_auto_part_name.empty() && _auto_part_name.size() <= MAX_LENGTH
        && !_car_brand.empty() && _car_brand.size() <= MAX_LENGTH
        && !_car_model.empty() && _car_model.size() <= MAX_LENGTH
        && !_availability.empty() && _availability.size() <= MAX_LENGTH;
}

AutoPart::AutoPart(const std::string & auto_part_name, const std::string & car_brand, const std::string & car_model, uint16_t cost, const std::string & availability)
    : _auto_part_name(auto_part_name), _car_brand(car_brand), _car_model(car_model), _cost(cost), _availability(availability)
{
    assert(invariant());
}

const string & AutoPart::getAutoPartName() const
{
    return _auto_part_name;
}

const string & AutoPart::getCarBrand() const
{
    return _car_brand;
}

const string & AutoPart::getCarModel() const
{
    return _car_model;
}

uint16_t AutoPart::getCost() const
{
    return _cost;
}

const string & AutoPart::getAvailability() const
{
    return _availability;
}

bool   AutoPart::write(ostream& os)
{
    writeString(os, _auto_part_name);
    writeString(os, _car_brand);
    writeString(os, _car_model);
    writeNumber(os, _cost);
    writeString(os, _availability);

    return os.good();
}



shared_ptr<ICollectable> ItemCollector::read(istream& is)
{
    string   auto_part_name = readString(is, MAX_LENGTH);
    string   car_brand  = readString(is, MAX_LENGTH);
    string   car_model  = readString(is, MAX_LENGTH);
    uint16_t cost       = readNumber<uint16_t>(is);
    string   availability  = readString(is, MAX_LENGTH);

    return std::make_shared<AutoPart>(auto_part_name, car_brand, car_model, cost, availability);
}
