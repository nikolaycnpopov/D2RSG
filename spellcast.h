#pragma once

#include "scenarioobject.h"

namespace rsg {

class SpellCast : public ScenarioObject
{
public:
    SpellCast(const CMidgardID& id)
        : ScenarioObject(id)
    { }

    ~SpellCast() override = default;

    const char* rawName() const override
    {
        return ".?AVCMidSpellCast@@";
    }

    void serialize(Serializer& serializer, const Map& scenario) const override;
};

} // namespace rsg
