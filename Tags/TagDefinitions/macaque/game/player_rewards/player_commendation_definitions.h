#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long COMMENDATION_AGGREGATOR_LIST_TAG = 'coag';
	extern s_tag_group commendation_aggregator_list_group; // commendation_aggregator_list_block

	constexpr unsigned long COMMENDATION_GLOBALS_DEFINITION_TAG = 'comg';
	extern s_tag_group commendation_globals_definition_group; // commendation_globals_definition_block


	extern s_tag_block_definition commendation_aggregator_list_block;
	extern s_tag_block_definition commendation_globals_definition_block;
	extern s_tag_block_definition commendationAggregator_block;
	extern s_tag_struct_definition commendationAggregator_block_struct_definition; // commendationAggregator_block
	extern s_tag_block_definition commendationRewardBlock_block;
	extern s_tag_struct_definition commendationRewardBlock_block_struct_definition; // commendationRewardBlock_block
	extern s_tag_block_definition commendationAggregatorDependent_block;
	extern s_tag_block_definition commendationBlock_block;
	extern s_tag_struct_definition commendationBlock_block_struct_definition; // commendationBlock_block
	extern s_tag_block_definition commendationLevelBlock_block;
	extern s_tag_struct_definition commendationLevelBlock_block_struct_definition; // commendationLevelBlock_block

	extern s_tag_struct_definition commendation_aggregator_list_struct_definition; // tag group
	extern s_tag_struct_definition commendation_globals_definition_struct_definition; // tag group
	extern s_tag_struct_definition commendationAggregatorDependent_struct;

	extern c_versioned_string_list commendationCategoryEnum_strings;
	extern s_string_list_definition commendationCategoryEnum;
	extern c_versioned_string_list commendationFlags_strings;
	extern s_string_list_definition commendationFlags;
	extern c_versioned_string_list commendationSubcategoryEnum_strings;
	extern s_string_list_definition commendationSubcategoryEnum;
	extern c_versioned_string_list aggregatorDependentTypeEnumDefinition_strings;
	extern s_string_list_definition aggregatorDependentTypeEnumDefinition;


} // namespace macaque

} // namespace blofeld
