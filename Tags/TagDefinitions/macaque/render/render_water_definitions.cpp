#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		render_water_ripple_group,
		RENDER_WATER_RIPPLE_TAG,
		nullptr,
		INVALID_TAG,
		render_water_ripple_block );

	TAG_BLOCK_FROM_STRUCT(
		render_water_ripple_block,
		"render_water_ripple_block",
		1,
		render_water_ripple_struct_definition);

	#define RENDER_WATER_RIPPLE_STRUCT_DEFINITION_ID { 0xCB60D088, 0x882E4775, 0x883C8C94, 0x8CE7CD58 }
	TAG_STRUCT(
		render_water_ripple_struct_definition,
		"render_water_ripple_struct_definition",
		"s_render_water_ripple_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_WATER_RIPPLE_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("TYPE FLAGS", nullptr, ""),
		{ _field_long_flags, "flags", &ripple_behavior_flags },
		FIELD_EXPLANATION("INITIAL SETTINGS", nullptr, ""),
		{ _field_real, "initial radius" },
		{ _field_real, "initial amplitude" },
		{ _field_real, "spread speed" },
		{ _field_real, "speed bias" },
		{ _field_real, "position random range" },
		{ _field_real, "max visibility distance" },
		FIELD_EXPLANATION("LIFE SETTINGS", nullptr, "what happens during the ripple life. damping should be always larger than 0."),
		{ _field_real, "duration max" },
		{ _field_real, "duration min" },
		{ _field_real, "rise period ratio" },
		{ _field_enum, "rise function", &transition_function_enum },
		{ _field_enum, "descend function", &transition_function_enum },
		FIELD_EXPLANATION("PENDULUM SETTINGS", nullptr, "Only valid in case of the predulum flag has been checked."),
		{ _field_real, "phase revolution speed" },
		{ _field_real, "phase repeat along radius" },
		FIELD_EXPLANATION("SHAPE TRANSITION", nullptr, "interpolate between shapes in ripple pattern array"),
		{ _field_real, "pattern start idx" },
		{ _field_real, "pattern end idx" },
		{ _field_enum, "pattern transition", &transition_function_enum },
		FIELD_PAD("SexyPadding1", nullptr, 2),
		FIELD_EXPLANATION("FOAM", nullptr, "quick flashed foam"),
		{ _field_real, "foam out radius" },
		{ _field_real, "foam fade distance" },
		{ _field_real, "foam duration" },
		{ _field_enum, "foam fade function", &transition_function_enum },
		FIELD_PAD("SexyPadding2", nullptr, 2),
		{ _field_terminator }
	};

	STRINGS(ripple_behavior_flags)
	{
		"ripple drifted by flow",
		"amplitude changed by pendulum function",
		"display flash foam",
		"foam size defined in game unit"
	};
	STRING_LIST(ripple_behavior_flags, ripple_behavior_flags_strings, _countof(ripple_behavior_flags_strings));

	STRINGS(transition_function_enum)
	{
		"linear",
		"early",
		"very early",
		"late",
		"very late",
		"cosine",
		"one",
		"zero"
	};
	STRING_LIST(transition_function_enum, transition_function_enum_strings, _countof(transition_function_enum_strings));

} // namespace macaque

} // namespace blofeld

