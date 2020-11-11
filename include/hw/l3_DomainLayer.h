
#ifndef HW_L3_DOMAIN_LAYER_H
#define HW_L3_DOMAIN_LAYER_H

#include "hw/l4_InfrastructureLayer.h"

const size_t MAX_LENGTH    = 50;

class AutoPart : public ICollectable
{
    std::string _auto_part_name;
    std::string _car_brand;
    std::string _car_model;
    uint16_t    _cost;
    std::string _availability;

protected:
    bool invariant() const;

public:
    AutoPart() = delete;
    AutoPart(const AutoPart & p) = delete;

    AutoPart & operator = (const AutoPart & p) = delete;

    AutoPart(const std::string & auto_part_name, const std::string & car_brand, const std::string & car_model, uint16_t cost, const std::string & availability);

    const std::string & getAutoPartName() const;
    const std::string & getCarBrand() const;
    const std::string & getCarModel() const;
    uint16_t getCost() const;
    const std::string & getAvailability() const;

    virtual bool   write(std::ostream& os) override;
};


class ItemCollector: public ACollector
{
public:
    virtual std::shared_ptr<ICollectable> read(std::istream& is) override;
};

#endif // HW_L3_DOMAIN_LAYER_H
