#pragma once

#include "scenarioobject.h"

namespace rsg {

class ScenarioVariables : public ScenarioObject
{
public:
    ScenarioVariables(const CMidgardID& id)
        : ScenarioObject(id)
    { }

    ~ScenarioVariables() override = default;

    const char* rawName() const override
    {
        return ".?AVCMidScenVariables@@";
    }

    void serialize(Serializer& serializer, const Map& scenario) const override;
};

} // namespace rsg
