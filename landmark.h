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

#pragma once

#include "mapelement.h"
#include "scenarioobject.h"

namespace rsg {

class Landmark
    : public ScenarioObject
    , public MapElement
{
public:
    Landmark(const CMidgardID& landmarkId, const Position& size)
        : ScenarioObject(landmarkId)
        , MapElement(size)
    { }

    ~Landmark() override = default;

    const char* rawName() const override
    {
        return ".?AVCMidLandmark@@";
    }

    void serialize(Serializer& serializer, const Map& scenario) const override;

    void setTypeId(const CMidgardID& typeId)
    {
        landmarkTypeId = typeId;
    }

private:
    CMidgardID landmarkTypeId;
};

} // namespace rsg
