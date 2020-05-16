#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(reward_globals_definition, REWARD_GLOBALS_DEFINITION_TAG, reward_globals_definition_block_block )

TAG_BLOCK_FROM_STRUCT(reward_globals_definition_block, 1, reward_globals_definition_struct_definition_struct_definition );

TAG_BLOCK(rewardDefinitionBlock, RewardGlobalDefinition::k_maximum_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_pad, "PJB1", 3 ),
	FIELD( _field_block, "rewards", &rewardBlock_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(reward_globals_definition_struct_definition)
{
	FIELD( _field_block, "reward definitions{cookie awards}", &rewardDefinitionBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld
