/*
 * This file is part of the random scenario generator for Disciples 2.
 * (https://github.com/VladimirMakeev/D2RSG)
 * Copyright (C) 2023 Vladimir Makeev.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "road.h"
#include "serializer.h"

namespace rsg {

void Road::serialize(Serializer& serializer, const Map& scenario) const
{
    serializer.enterRecord();
    serializer.serialize("ROAD_ID", objectId);
    serializer.serialize("INDEX", index);
    // According to game code, roads can be without 'VAR' field.
    // We can save some bytes and do not serialize it, since it is always (?) zero.
    // My Kaitai Struct .sg format description does not handle roads without 'VAR' field,
    // so leave it as is for now to be able to debug generated scenarios.
    serializer.serialize("VAR", 0);
    serializer.serialize("POS_X", "POS_Y", position);
    serializer.leaveRecord();
}

} // namespace rsg
