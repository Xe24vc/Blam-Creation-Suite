#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cellular_automata2d_group,
		CELLULAR_AUTOMATA2D_TAG,
		nullptr,
		INVALID_TAG,
		cellular_automata2d_block );

	TAG_BLOCK_FROM_STRUCT(
		cellular_automata2d_block,
		"cellular_automata2d_block",
		1,
		cellular_automata2d_struct_definition);

	#define RULES_BLOCK_ID { 0xDBEB4D68, 0x20704C35, 0x9B47CD3F, 0x0C94F08B }
	TAG_BLOCK(
		rules_block,
		"rules_block",
		MAXIMUM_RULES_PER_CA,
		"ca2d_rule",
		RULES_BLOCK_ID)
	{
		{ _field_string, "name" },
		{ _field_real_rgb_color, "tint color" },
		FIELD_PAD("VJSKSPI", nullptr, 32),
		{ _field_block, "states", &states_block },
		{ _field_terminator }
	};

	#define STATES_BLOCK_ID { 0x3BD7BDBB, 0xD2EE413B, 0x822971B4, 0x516A8D30 }
	TAG_BLOCK(
		states_block,
		"states_block",
		MAXIMUM_STATES_PER_RULE,
		"ca2d_rule_state",
		STATES_BLOCK_ID)
	{
		{ _field_string, "name" },
		{ _field_real_rgb_color, "color" },
		{ _field_short_integer, "counts as", "neighbors" },
		FIELD_PAD("IZ", nullptr, 2),
		{ _field_real, "initial placement weight" },
		FIELD_PAD("B", nullptr, 24),
		{ _field_short_block_index, "zero", &states_block },
		{ _field_short_block_index, "one", &states_block },
		{ _field_short_block_index, "two", &states_block },
		{ _field_short_block_index, "three", &states_block },
		{ _field_short_block_index, "four", &states_block },
		{ _field_short_block_index, "five", &states_block },
		{ _field_short_block_index, "six", &states_block },
		{ _field_short_block_index, "seven", &states_block },
		{ _field_short_block_index, "eight", &states_block },
		FIELD_PAD("BJVWP", nullptr, 2),
		{ _field_terminator }
	};

	#define CELLULAR_AUTOMATA2D_STRUCT_DEFINITION_ID { 0x58015675, 0xB4FA436F, 0xAAB9EC7C, 0x90E51960 }
	TAG_STRUCT(
		cellular_automata2d_struct_definition,
		"cellular_automata2d_struct_definition",
		"ca2d_definition",
		CELLULAR_AUTOMATA2D_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "properties", "" },
		{ _field_short_integer, "updates per second", "Hz" },
		FIELD_PAD("IFJ", nullptr, 2),
		{ _field_real, "dead cell penalty" },
		{ _field_real, "live cell bonus" },
		FIELD_PAD("EPTNF", nullptr, 80),
		{ _field_explanation, "height map", "" },
		{ _field_short_integer, "width", "cells" },
		{ _field_short_integer, "height", "cells" },
		{ _field_real, " cell width", "world units" },
		{ _field_real, " height", "world units" },
		{ _field_real_vector_2d, "velocity", "cells/update" },
		FIELD_PAD("KHXCI", nullptr, 28),
		{ _field_old_string_id, "marker" },
		{ _field_long_flags, "interpolation flags", &global_rgb_interpolation_flags },
		{ _field_real_rgb_color, "base color" },
		{ _field_real_rgb_color, "peak color" },
		FIELD_PAD("IXKLNR", nullptr, 76),
		{ _field_explanation, "detail map", "" },
		{ _field_short_integer, "  width", "cells" },
		{ _field_short_integer, "  height", "cells" },
		{ _field_real, "  cell width", "world units" },
		{ _field_real_vector_2d, " velocity", "cells/update" },
		FIELD_PAD("JXB", nullptr, 48),
		{ _field_old_string_id, " marker" },
		{ _field_short_integer, "texture width", "cells" },
		FIELD_PAD("HNOIXYJ", nullptr, 2),
		FIELD_PAD("DDIGC", nullptr, 48),
		{ _field_tag_reference, "texture", &global_bitmap_reference },
		FIELD_PAD("HSJQLXWS", nullptr, 160),
		{ _field_block, "rules", &rules_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld
