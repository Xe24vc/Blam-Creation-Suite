#pragma once

bool definition_migration_compare_string_list(
	const blofeld::s_string_list_definition& old_string_list_definition,
	const blofeld::s_string_list_definition& new_string_list_definition,
	s_engine_platform_build engine_platform_build);

bool definition_migration_compare_struct(
	const blofeld::s_tag_struct_definition& old_struct_definition,
	const blofeld::s_tag_struct_definition& new_struct_definition,
	s_engine_platform_build engine_platform_build);

bool definition_migration_compare_block(
	const blofeld::s_tag_block_definition& old_block_definition,
	const blofeld::s_tag_block_definition& new_block_definition,
	s_engine_platform_build engine_platform_build);

// #TODO: Convert this over to BCS_RESULT
BCS_DEBUG_API bool definition_migration(
	const blofeld::s_tag_group** old_tag_groups,
	const blofeld::s_tag_group** new_tag_groups,
	s_engine_platform_build engine_platform_build);

class c_tag_struct_definition_view;
BCS_DEBUG_API BCS_RESULT definition_duplicate_check(c_tag_struct_definition_view& tag_structs_view);
