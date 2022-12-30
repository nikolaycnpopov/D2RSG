#include "turnsummary.h"
#include "serializer.h"

namespace rsg {

void TurnSummary::serialize(Serializer& serializer, const Map& scenario) const
{
    serializer.enterRecord();

    CMidgardID::String idString{};
    objectId.toString(idString);

    serializer.serialize(idString.data(), 0);

    serializer.leaveRecord();
}

} // namespace rsg
