// MIT License, Copyright (c) 2022 Malik Allen

#ifndef ECS_DEFINITIONS_H
#define ECS_DEFINITIONS_H

#include <cstdint>

#include "Utility/CompilerHash.h"

#define GENERATE_ID(y) (COMPILE_TIME_CRC32_STR(y))

namespace FiveDeadlyVenoms {

	using EntityId =  uint64_t;

	using ComponentId = uint64_t;

	static constexpr size_t MAX_ENTITIES	{ 10000 };

	static constexpr size_t MAX_COMPONENTS_PER_ENTITY	{ 1000 };

	static constexpr size_t MAX_SYSTEMS	{ 1000 };

	static constexpr size_t MAX_COMPONENTS	{ MAX_ENTITIES * MAX_COMPONENTS_PER_ENTITY };

}


#endif // !ECS_DEFINITIONS_H

