#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_block_definition;

	struct s_tag_group
	{
		s_tag_group(
			const char* const name,
			const char* const filename,
			long const line,
			const char* const group_tag_code_string,
			unsigned long const group_tag,
			unsigned long const parent_group_tag,
			const s_tag_block_definition& block_definition,
			const s_tag_group* const parent_tag_group
		);

		const char* const name;
		unsigned long const group_tag;
		unsigned long const parent_group_tag;
		const s_tag_block_definition& block_definition;
		const s_tag_group* const parent_tag_group;
		char group_tag_code_string[64];
		char group_tag_short_string[8];
		s_symbol_file_public* symbol;
		const char* const filename;
		long const line;
	};
}
