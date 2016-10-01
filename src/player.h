/*
 * Copyright (C) 2016 Incognito
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "cell.h"
#include "common.h"
#include "identifier.h"

#include <boost/intrusive_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

#include <Eigen/Core>

#include <bitset>
#include <map>

struct Player
{
	Player(int id);

	int activeCheckpoint;
	int activeRaceCheckpoint;
	bool checkedPickups;
	bool checkedActors;
	std::size_t currentVisibleObjects;
	std::size_t currentVisibleTextLabels;
	int delayedCheckpoint;
	int delayedRaceCheckpoint;
	bool delayedUpdate;
	boost::chrono::steady_clock::time_point delayedUpdateTime;
	int delayedUpdateType;
	int interiorID;
	std::size_t maxVisibleMapIcons;
	std::size_t maxVisibleObjects;
	std::size_t maxVisibleTextLabels;
	int playerID;
	Eigen::Vector3f position;
	float radiusMultipliers[STREAMER_MAX_TYPES];
	int references;
	bool requestingClass;
	std::size_t tickCount;
	std::size_t tickRate;
	bool updateUsingCameraPosition;
	bool updateWhenIdle;
	SharedCell visibleCell;
	int visibleCheckpoint;
	int visibleRaceCheckpoint;
	int worldID;

	std::bitset<STREAMER_MAX_TYPES> enabledItems;
	std::bitset<STREAMER_MAX_TYPES> processingChunks;

	std::multimap<std::pair<int, float>, Item::SharedMapIcon, Item::Compare> discoveredMapIcons;
	std::multimap<std::pair<int, float>, Item::SharedMapIcon, Item::Compare> existingMapIcons;
	std::multimap<std::pair<int, float>, Item::SharedObject, Item::Compare> discoveredObjects;
	std::multimap<std::pair<int, float>, Item::SharedObject, Item::Compare> existingObjects;
	std::multimap<std::pair<int, float>, Item::SharedTextLabel, Item::Compare> discoveredTextLabels;
	std::multimap<std::pair<int, float>, Item::SharedTextLabel, Item::Compare> existingTextLabels;

	boost::unordered_set<int> internalAreas;
	boost::unordered_map<int, int> internalMapIcons;
	boost::unordered_map<int, int> internalObjects;
	boost::unordered_map<int, int> internalTextLabels;

	Identifier mapIconIdentifier;

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

#endif
