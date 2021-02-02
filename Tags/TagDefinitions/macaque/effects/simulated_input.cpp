#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		simulated_input_group,
		SIMULATED_INPUT_TAG,
		nullptr,
		INVALID_TAG,
		simulated_input_block );

	TAG_BLOCK_FROM_STRUCT(
		simulated_input_block,
		"simulated_input_block",
		1,
		simulated_input_struct_definition);

	#define SIMULATED_INPUT_STRUCT_DEFINITION_ID { 0x92B9F13E, 0x845845C7, 0x98EE12D2, 0xEF28014D }
	TAG_STRUCT(
		simulated_input_struct_definition,
		"simulated_input_struct_definition",
		"s_simulated_input_definition",
		SIMULATED_INPUT_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "Simulated Input (SI)", "Adds accelerations into unit\'s movement (by simulating movement stick change) and/or view angle (by simulating camera stick change)" },
		{ _field_explanation, "Impulse", "At SI spawn time the SI\'s angle is determined by adding the result of \'response type\' & \'mapping type\' to a random angle in given angle range.\nEach tick, this acceleration angle is multiplied by the final scaler resulting from logic below. That scaled impulse is then applied as stick input." },
		{ _field_explanation, "Scalers", "Starting scaler value comes from damage multiplier or is set to 1.0 if SI not directly related to damage.\nThat is then scaled by the following:\n * area control falloff\n * function output y: func(SI_elapsed_time/duration) --> y)\n * 1 / zoom magnification\n * tick_delta_secs / tick_length\nresult of this is final scaler value" },
		{ _field_explanation, "Screen Space angles", "0 - pitch up, +/-180 - pitch down\n-90 - yaw left, +90 - yaw right" },
		{ _field_explanation, "Move", "" },
		{ _field_struct, "move", &simulated_input_stick_struct },
		{ _field_explanation, "Look", "" },
		{ _field_struct, "look", &simulated_input_stick_struct },
		{ _field_terminator }
	};

	#define SIMULATED_INPUT_STICK_STRUCT_ID { 0x259EAC93, 0x0D744048, 0x9B737CB9, 0x55515831 }
	TAG_STRUCT(
		simulated_input_stick_struct,
		"simulated_input_stick_struct",
		"s_simulated_input_stick_definition",
		SIMULATED_INPUT_STICK_STRUCT_ID)
	{
		{ _field_long_flags, "flags", &simulated_input_flags },
		{ _field_enum, "response type", &direction_type_enum_definition },
		{ _field_enum, "mapping type", &mapping_type_enum_definition },
		{ _field_real_bounds, "angle", "degrees" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "duration", "seconds" },
		{ _field_real, "inverse duration", "if >0.f, accumulated inpulse will be \'undone\' over the give time span", "seconds" },
		{ _field_real, "inverse random length", "15.0 would randomly adjust length of accumulated impulse +/-15%", "percent" },
		{ _field_real_bounds, "inverse random angle", "apply random adjustment to direction of accumulated impulse", "degrees" },
		{ _field_real, "linear zoom penalty", "linear multiplier of zoom that increases effect; computed for no change at zoom 1" },
		{ _field_real, "square root zoom penalty", "multiplier to increase effect proportional to square root of zoom; computed for no change at zoom 1" },
		{ _field_terminator }
	};

	STRINGS(simulated_input_flags)
	{
		"ignore base scaler#Always start with 1.0 instead of any value from damage multiplier value",
		"ignore area control falloff#Skip this scaler",
		"ignore elapsed time function scaler#Skip this scaler",
		"ignore zoom scaler#Skip this scaler",
		"ignore tick_delta_secs scaler#Skip this scaler"
	};
	STRING_LIST(simulated_input_flags, simulated_input_flags_strings, _countof(simulated_input_flags_strings));

	STRINGS(direction_type_enum_definition)
	{
		"aim vector",
		"hit vector",
		"inverse hit vector",
		"attacker origin to victim origin",
		"victim origin to attacker origin"
	};
	STRING_LIST(direction_type_enum_definition, direction_type_enum_definition_strings, _countof(direction_type_enum_definition_strings));

	STRINGS(mapping_type_enum_definition)
	{
		"top down",
		"screen space"
	};
	STRING_LIST(mapping_type_enum_definition, mapping_type_enum_definition_strings, _countof(mapping_type_enum_definition_strings));

	TAG_REFERENCE(global_simulated_input_reference, SIMULATED_INPUT_TAG);

} // namespace macaque

} // namespace blofeld
