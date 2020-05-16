#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(ai_mission_dialogue, AI_MISSION_DIALOGUE_TAG, ai_mission_dialogue_block_block )

TAG_BLOCK_FROM_STRUCT(ai_mission_dialogue_block, 1, ai_mission_dialogue_struct_definition_struct_definition );

TAG_BLOCK(mission_dialogue_lines_block, k_max_lines_per_scenario)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_block, "variants", &mission_dialogue_variants_block_block ),
	FIELD( _field_string_id, "default sound effect" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(mission_dialogue_variants_block, k_max_variants_per_line)
{
	FIELD( _field_string_id, "variant designation#3-letter designation for the character^" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_string_id, "sound effect" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_scene_block, k_max_scenes_per_scenario)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_block, "trigger conditions", &ai_scene_trigger_block_block ),
	FIELD( _field_useless_pad ),
	FIELD( _field_block, "roles", &ai_scene_role_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_scene_trigger_block, 1)
{
	FIELD( _field_enum, "combination rule" ),
	FIELD( _field_pad, "NJBJMKU", 2 ),
	FIELD( _field_block, "triggers", &trigger_references_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_scene_role_block, k_max_roles_per_scene)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_enum, "group" ),
	FIELD( _field_pad, "XZUW", 2 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_block, "role variants", &ai_scene_role_variants_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_scene_role_variants_block, k_max_variants_per_line)
{
	FIELD( _field_string_id, "variant designation^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_scenario_mission_dialogue_block, 1)
{
	FIELD( _field_tag_reference, "mission dialogue" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(ai_mission_dialogue_struct_definition)
{
	FIELD( _field_block, "lines", &mission_dialogue_lines_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld
